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

void *handle_client(void *args)
{
    pthread_detach(pthread_self());
    thread_args *arg = (thread_args *)args;
    int connectSocket = arg->conn_sock;
    char message[BUFF_SIZE];
    while (1)
    {
        ssize_t recvbytes = recv(connectSocket, &message, BUFF_SIZE - 1, 0);
        if (recvbytes <= 0)
        {
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
        if (atoi(message) == 2)
        {
            char messageType[BUFF_SIZE] = "#message2";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);


            if (recv_and_handle_login(connectSocket, &listAccounts, &listRooms) == 0)
            {
                break;
            }

        }
        if (atoi(message) == 3)
        {
            char messageType[BUFF_SIZE] = "#message3";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_logout(connectSocket, &listAccountRooms, &listAccounts) == 0)
            {
                break;
            }
        }
        if (atoi(message) == 4)
        {
            char messageType[BUFF_SIZE] = "#message4";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_create_auction(connectSocket, &listAccountRooms, &listRooms) == 0)
            {
                break;
            }
        }
        if (atoi(message) == 5)
        {
            char messageType[BUFF_SIZE] = "#message5";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_join_auction(connectSocket, &listAccountRooms) == 0)
            {
                break;
            }
        }
        if (atoi(message) == 7)
        {
            char messageType[BUFF_SIZE] = "#message7";
            for (Account acc : listAccounts)
            {
                cout << acc.connectSocket << endl;
                if (acc.connectSocket != -1)
                {
                    send(acc.connectSocket, messageType, BUFF_SIZE - 1, 0);
                }
            }
        }
        if (atoi(message) == 9)
        {
            char messageType[BUFF_SIZE] = "#message9";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_delete_item(connectSocket, &listItems, &listRooms) == 0)
            {
                break;
            }

        }
        if (atoi(message) == 11)
        {
            char messageType[BUFF_SIZE] = "#message11";
            send(connectSocket, messageType, BUFF_SIZE - 1, 0);
            if (recv_and_handle_create_item(connectSocket, &listItems, &listRooms) == 0)
            {
                break;
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
