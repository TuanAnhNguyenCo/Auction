#include "structure_aution.h"
#include "account_room.h"
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

void get_rooms(list<AuctionRoom> *rooms)
{
    FILE *f = fopen("database/auctionRoom.txt", "r");
    if (f == NULL)
    {
        cout << "Fail to read file" << endl;
        return;
    }

    AuctionRoom room;
    while (fscanf(f, "%d %d %s %ld %d", &room.id, &room.proprietor_id, room.name, &room.created_at, &room.status) == 5)
    {
        rooms->push_back(room);
    }
    fclose(f);
}

void print_rooms(list<AuctionRoom> rooms)
{
    for (AuctionRoom r : rooms)
    {
        cout << r.id << " " << r.proprietor_id << " " << r.name << " " << ctime(&r.created_at) << r.status << endl;
    }
}

void save_rooms(list<AuctionRoom> rooms)
{
    FILE *file;
    file = fopen("database/auctionRoom.txt", "w+");
    if (file != NULL)
    {
        for (AuctionRoom room : rooms)
            fprintf(file, "%d %d %s %ld %d\n", room.id, room.proprietor_id, room.name, room.created_at, room.status);
    }
    else
    {
        printf("File is null");
    }
    fclose(file);
}
// // 1: joined, 2: not join
// int checkJoined(int user_id, list<AuctionRoom> rooms)
// {
//     for (AuctionRoom r : rooms)
//     {
//         if (r.proprietor_id == user_id && r.status == 1)
//         {
//             return 1;
//         }
//     }
//     return 2;
// }
// 1: Successfully 2: Fail
int create(list<AuctionRoom> *rooms, list<AuctionRoomParticipate> *listAccountRooms, AuctionRoom room)
{
    if (checkValidJoin(room.proprietor_id, *listAccountRooms) == 2)
    {
        room.id = rooms->size() + 1;
        room.status = 1;
        cout << room.name << endl;
        rooms->push_back(room);

        AuctionRoomParticipate newAccountRoom;
        newAccountRoom.user_id = room.proprietor_id;
        newAccountRoom.room_id = room.id;
        listAccountRooms->push_back(newAccountRoom);

        save_rooms(*rooms);
        save_account_rooms(*listAccountRooms);
        return 1;
    }
    return 2;
}
// 1: Successfully 2: Fail
int handleCreateAuction(AuctionRoomCreationMess roomMess, list<AuctionRoomParticipate> *listAccountRooms, list<AuctionRoom> *rooms)
{
    AuctionRoom room;
    strcpy(room.name, roomMess.name);
    room.created_at = roomMess.created_at;
    room.proprietor_id = roomMess.proprietor_id;
    pthread_mutex_lock(&blockThreadMutex_auction);
    int status = create(rooms, listAccountRooms, room);
    pthread_mutex_unlock(&blockThreadMutex_auction);
    return status;
}
// #OK is OK and #FAIL is fail
int recv_and_handle_create_auction(int conn_sock, list<AuctionRoomParticipate> *listAccountRooms, list<AuctionRoom> *rooms)
{
    AuctionRoomCreationMess roomMess;
    cout << "Creating..." << endl;
    int rcvBytes = recv(conn_sock, &roomMess, sizeof(roomMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char *message;
    int status = handleCreateAuction(roomMess, listAccountRooms, rooms);
    if (status == 1)
    {
        message = "#OK";
        send(conn_sock, message, strlen(message), 0);
    }
    else if (status == 2)
    {
        message = "#FAIL";
        send(conn_sock, message, strlen(message), 0);
    }
    return 1;
}
