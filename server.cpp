#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <list>
#include "lib/account.h"
#define BUFF_SIZE 8192
#define BACKLOG 2
char buff[BUFF_SIZE];

using namespace std;
list<Account> listAccounts;
list<AuctionRoom> listRooms;
list<AuctionRoomParticipate> listAccountRooms;
list<Item> listItems;
typedef struct
{
    int conn_sock;

} thread_args;

void send_all_client(list<Account> accounts, char *messages)
{
    for (Account acc : accounts)
    {
        if (acc.connectSocket != -1)
        {
            send(acc.connectSocket, messages, BUFF_SIZE - 1, 0);
        }
    }
}

void send_participate(list<Account> accounts, list<AuctionRoomParticipate> listAccountRooms, char *messages, int room_id)
{
    for (Account acc : accounts)
    {
        for (AuctionRoomParticipate acc_r : listAccountRooms)
        {
            if (acc_r.room_id == room_id && acc_r.status == 1 && acc_r.user_id == acc.id)
            {
                send(acc.connectSocket, messages, BUFF_SIZE - 1, 0);
            }
        }
    }
}

void *handle_client(void *args)
{
    pthread_detach(pthread_self());
    thread_args *arg = (thread_args *)args;
    int connectSocket = arg->conn_sock;
    char message[BUFF_SIZE];
    int current_user_id = -1;
    while (1)
    {
        ssize_t recvbytes = recv(connectSocket, &message, BUFF_SIZE - 1, 0);
        if (recvbytes <= 0)
        {
            if (current_user_id != -1)
            {
                LogoutMess logoutMess;
                logoutMess.user_id = current_user_id;
                handleLogout(logoutMess, &listAccountRooms, &listAccounts);
                char messageUpdate[BUFF_SIZE] = "#update_account_room";
                send_all_client(listAccounts, messageUpdate);
            }

            break;
        }
        message[recvbytes] = '\0';

        cout << "feature: " << message << endl;
        if (atoi(message) == 1)
        {
            char messageType[BUFF_SIZE] = "#message1";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_sign_up(connectSocket, &listAccounts) == 0)
            {
                break;
            }
        }
        else if (atoi(message) == 2)
        {
            char messageType[BUFF_SIZE] = "#message2";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            current_user_id = recv_and_handle_login(connectSocket, &listAccounts);
            if (current_user_id == 0)
            {
                break;
            }
        }
        else if (atoi(message) == 3)
        {
            char messageType[BUFF_SIZE] = "#message3";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);

            if (recv_and_handle_logout(connectSocket, &listAccountRooms, &listAccounts) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_account_room";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 4)
        {
            char messageType[BUFF_SIZE] = "#message4";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_create_auction(connectSocket, &listAccountRooms, &listRooms) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_room";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 5)
        {
            char messageType[BUFF_SIZE] = "#message5";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_join_auction(connectSocket, &listAccountRooms) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_account_room";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 6)
        {
            char messageType[BUFF_SIZE] = "#message6";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            int room_id = recv_and_handle_bid_items(connectSocket, &listItems);
            if (room_id == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_item";
            send_all_client(listAccounts, messageUpdate);
            char messageStopTime[BUFF_SIZE] = "#update_time";
            send_participate(listAccounts, listAccountRooms, messageStopTime, room_id);
        }
        else if (atoi(message) == 7)
        {
            char messageType[BUFF_SIZE] = "#message7";
            for (Account acc : listAccounts)
            {
                if (acc.connectSocket != -1)
                {
                    send(acc.connectSocket, messageType, BUFF_SIZE - 1, 0);
                }
            }
        }
        else if (atoi(message) == 9)
        {
            char messageType[BUFF_SIZE] = "#message9";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_delete_item(connectSocket, &listItems, &listRooms) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_item";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 10)
        {
            char messageType[BUFF_SIZE] = "#message10";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_kick_account(connectSocket, &listRooms, &listAccountRooms) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_account_room";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 11)
        {
            char messageType[BUFF_SIZE] = "#message11";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_create_item(connectSocket, &listItems, &listRooms) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_item";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 14)
        {
            char messageType[BUFF_SIZE] = "#message14";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_get_rooms(connectSocket, &listRooms) == 0)
            {
                break;
            }
        }
        else if (atoi(message) == 16)
        {
            char messageType[BUFF_SIZE] = "#message16";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            int room_id = recv_and_handle_bin_price(connectSocket, &listItems);
            if (room_id == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_item";
            send_all_client(listAccounts, messageUpdate);
            char messageStopTime[BUFF_SIZE] = "#stop_time";
            send_participate(listAccounts, listAccountRooms, messageStopTime, room_id);
        }
        else if (atoi(message) == 18)
        {
            char messageType[BUFF_SIZE] = "#message18";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_get_items(connectSocket, &listItems) == 0)
            {
                break;
            }
        }
        else if (atoi(message) == 19)
        {
            char messageType[BUFF_SIZE] = "#message19";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_out_rooms(connectSocket, &listAccountRooms) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_account_room";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 20)
        {
            char messageType[BUFF_SIZE] = "#message20";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_get_participate(connectSocket, &listAccountRooms, &listAccounts) == 0)
            {
                break;
            }
        }
        else if (atoi(message) == 21)
        {
            char messageType[BUFF_SIZE] = "#message21";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_close_item(connectSocket, &listItems) == 0)
            {
                break;
            }
            char messageUpdate[BUFF_SIZE] = "#update_item";
            send_all_client(listAccounts, messageUpdate);
        }
        else if (atoi(message) == 22)
        {
            GetParticipateMess mess;
            recv(connectSocket, &mess, sizeof(GetParticipateMess), 0);
            char messageAlert[BUFF_SIZE] = "#start_bidding";
            send_participate(listAccounts, listAccountRooms, messageAlert, mess.room_id);
        }
        else if (atoi(message) == 23)
        {
            GetParticipateMess mess;
            recv(connectSocket, &mess, sizeof(GetParticipateMess), 0);
            char messageAlert[BUFF_SIZE] = "#Alert";
            send_participate(listAccounts, listAccountRooms, messageAlert, mess.room_id);
        }
        else if (atoi(message) == 24)
        {
            char messageType[BUFF_SIZE] = "#message24";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_get_participate_history(connectSocket, &listAccountRooms, &listAccounts) == 0)
            {
                break;
            }
        }
        else if (atoi(message) == 25)
        {
            char messageType[BUFF_SIZE] = "#message25";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_get_room_history(connectSocket, &listAccountRooms, &listRooms) == 0)
            {
                break;
            }
        }
        else if (atoi(message) == 26)
        {
            // char messageType[BUFF_SIZE] = "#message26";
            // send(connectSocket, messageType, BUFF_SIZE - 1, 0);

            cout << "abc";
            Image image;
            recv(connectSocket, &image, sizeof(Image), 0);
            char url[BUFF_SIZE] = "Image/image_";
            strcat(url, to_string(image.item_id).c_str());
            strcat(url, ".jpeg");
            cout << url << endl;
            if (image.status == 2)
            {
                // read data and append to file
                FILE *fp;
                // image.image == 1: I get sending a image
                if (image.isFirst == 1)
                {
                    change_url(&listItems, url, image.item_id);
                    fp = fopen(url, "wb");
                }
                else // image.image == 0: I continue to send a image
                    fp = fopen(url, "ab");
                fwrite(image.buff, 1, sizeof(image.buff), fp);
                fclose(fp);
            }
            else if (image.status == 3)
            {
                char messageUpdate[BUFF_SIZE] = "#update_item";
                send_all_client(listAccounts, messageUpdate);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "abcd" << endl;
    }
    signal(SIGPIPE, SIG_IGN);

    int listenSocket, connectSocket;
    get_accounts(&listAccounts);
    get_rooms(&listRooms);
    get_account_rooms(&listAccountRooms);
    get_items(&listItems);
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t sin_size;
    pthread_t tid;

    if ((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if (::bind(listenSocket, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    if (listen(listenSocket, BACKLOG) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    while (1)
    {
        sin_size = sizeof(struct sockaddr_in);
        if ((connectSocket = accept(listenSocket, (struct sockaddr *)&client, &sin_size)) == -1)
            perror("\nError: ");
        if (connectSocket == -1)
        {
            perror("\nError: ");
            continue;
        }
        printf("You got a connection from %s\n", inet_ntoa(client.sin_addr));

        thread_args args;
        args.conn_sock = connectSocket;
        pthread_create(&tid, NULL, &handle_client, &args);
    }
    close(listenSocket);
    return 0;
}
