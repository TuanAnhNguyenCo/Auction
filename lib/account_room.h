#include "structure_account_room.h"
#include "string.h"
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <pthread.h>
#include <algorithm>
using namespace std;

#define BUFF_SIZE 8192
pthread_mutex_t blockThreadMutex_account_room;

void get_account_rooms(list<AuctionRoomParticipate> *account_rooms)
{
    FILE *f = fopen("database/account_room.txt", "r");
    if (f == NULL)
    {
        cout << "Fail to read file" << endl;
        return;
    }

    AuctionRoomParticipate account_room;
    while (fscanf(f, "%d %d %d", &account_room.user_id, &account_room.room_id, &account_room.status) == 3)
    {
        account_rooms->push_back(account_room);
    }
    fclose(f);
}

void print_account_rooms(list<AuctionRoomParticipate> account_rooms)
{
    for (AuctionRoomParticipate acc : account_rooms)
    {
        cout << acc.user_id << " " << acc.room_id << " " << acc.status << endl;
    }
}

void save_account_rooms(list<AuctionRoomParticipate> account_rooms)
{
    FILE *file;
    file = fopen("database/account_room.txt", "w+");
    if (file != NULL)
    {
        for (AuctionRoomParticipate acc : account_rooms)
            fprintf(file, "%d %d %d\n", acc.user_id, acc.room_id, acc.status);
    }
    else
    {
        printf("File is null");
    }
    fclose(file);
}

// 1: joined, 2: not join
int checkValidJoin(int user_id, list<AuctionRoomParticipate> account_rooms)
{
    for (AuctionRoomParticipate acc : account_rooms)
    {
        if (acc.user_id == user_id && acc.status == 1)
        {
            return 1;
        }
    }
    return 2;
}
// check has ever participated // 1: joined, 2: not join
int checkParticipated(int user_id, int room_id, list<AuctionRoomParticipate> account_rooms)
{
    for (AuctionRoomParticipate acc : account_rooms)
    {
        if (acc.user_id == user_id && acc.room_id == room_id && acc.status == 0)
        {
            return 1;
        }
    }
    return 2;
}
// 1: Successfully 2: Fail
int join(list<AuctionRoomParticipate> *account_rooms, AuctionRoomParticipate account)
{
    if (checkValidJoin(account.user_id, *account_rooms) == 2)
    {

        for (AuctionRoomParticipate &acc : *account_rooms)
        {
            if (acc.room_id == account.room_id && acc.user_id == account.user_id && acc.status == 0)
            {
                acc.status = 1;
                save_account_rooms(*account_rooms);
                return 1;
            }
        }
        account.status = 1;
        print_account_rooms(*account_rooms);
        account_rooms->push_back(account);
        save_account_rooms(*account_rooms);
        return 1;
    }
    return 2;
}
// 1: OK, 2: FAIL
int outRoom(list<AuctionRoomParticipate> *account_rooms, int user_id)
{
    // if (account_rooms == nullptr || account_rooms->empty())
    // {
    //     // Danh sách rỗng hoặc con trỏ không hợp lệ, không cần thực hiện thêm thao tác.
    //     return 1;
    // }

    // auto it = std::remove_if(account_rooms->begin(), account_rooms->end(),
    //                          [user_id](const AuctionRoomParticipate &acc)
    //                          { return acc.user_id == user_id; });
    // if (it == account_rooms->end())
    // {
    //     // Không có phần tử thỏa mãn điều kiện, không cần thực hiện thêm thao tác.
    //     return 1;
    // }

    // account_rooms->erase(it, account_rooms->end());
    // save_account_rooms(*account_rooms);
    for (AuctionRoomParticipate &acc : *account_rooms)
    {
        if (acc.user_id == user_id && acc.status == 1)
        {
            acc.status = 0;
            save_account_rooms(*account_rooms);
            return 2; // Phần tử đã được xóa thành công
        }
    }

    return 1;
}

int handleJoinAuction(JoinMess joinMess, list<AuctionRoomParticipate> *account_rooms)
{
    AuctionRoomParticipate account_room;
    account_room.user_id = joinMess.user_id;
    account_room.room_id = joinMess.room_id;
    pthread_mutex_lock(&blockThreadMutex_account_room);
    int status = join(account_rooms, account_room);
    pthread_mutex_unlock(&blockThreadMutex_account_room);
    return status;
}

// #OK is OK and #FAIL is fail
int recv_and_handle_join_auction(int conn_sock, list<AuctionRoomParticipate> *account_rooms)
{
    JoinMess JoinMess;
    cout << "Joining..." << endl;
    int rcvBytes = recv(conn_sock, &JoinMess, sizeof(JoinMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char message[BUFF_SIZE];
    int status = handleJoinAuction(JoinMess, account_rooms);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 2)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}
