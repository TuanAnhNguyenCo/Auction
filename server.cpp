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

typedef struct
{
    int conn_sock;

} thread_args;



void *handle_client(void *args)
{
    pthread_detach(pthread_self());
    int bytes_sent, bytes_received;
    thread_args *arg = (thread_args *)args;
    char message[2];
    while (1)
    {
        recv(arg->conn_sock, &message, 1, 0);
        if (atoi(message) == 1)
        {
            if (recv_and_handle_sign_up(arg->conn_sock, &listAccounts) == 0)
            {
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int listenSocket, connectSocket;
    get_accounts(&listAccounts);
    char message[2];
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t sin_size;
    pthread_t tid;
    char buff[BUFF_SIZE];

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
