#include <iostream>
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
#include <cstdio>
#include <cstdlib>
#include "lib/account.h"

using namespace std;

#define BUFF_SIZE 8192

typedef struct
{
  int conn_sock;

} thread_args;

// void *handle_server(void *args)
// {
//   int bytes_sent, bytes_received;
//   thread_args *arg = (thread_args *)args;
//   char message[BUFF_SIZE];
//   while (1)
//   {
//     recv(arg->conn_sock, &message, BUFF_SIZE - 1, 0);
//     if (strcmp(message, "#message7") == 0)
//     {
//       cout << message << endl;
//     }
//   }
// }

void *handle_server(void *args)
{
  pthread_detach(pthread_self());
  thread_args *arg = (thread_args *)args;
  int client_socket = arg->conn_sock;
  while (1)
  {
    char line[10];
    memset(line, 0, sizeof(line));
    cin.getline(line, sizeof(line));
    // ssize_t charCount = ::getline(&line, &lineSize, stdin);

    // char *messId = "1";
    send(client_socket, line, strlen(line), 0);
    char message[BUFF_SIZE];

    ssize_t recvbytes = recv(client_socket, message, BUFF_SIZE - 1, 0);
    message[recvbytes] = '\0';
    cout << message << endl;
    if (strcmp(message, "#message2") == 0)
    {
      /* code */
      LoginMess acc;
      strcpy(acc.username, "anh3");
      strcpy(acc.password, "1");
      send(client_socket, &acc, sizeof(acc), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
      if (strcmp(buffer, "#OK") == 0)
      {
        Account account_signed;
        int rcvBytes = recv(client_socket, &account_signed, sizeof(account_signed), 0);
        cout << account_signed.address << endl;
        char message[BUFF_SIZE];
        rcvBytes = recv(client_socket, message, BUFF_SIZE - 1, 0);
        message[rcvBytes] = '\0';
        cout << message << endl;
        for (int i = 0; i < atoi(message); i++)
        {
          AuctionRoom room;
          rcvBytes = recv(client_socket, &room, sizeof(AuctionRoom), 0);
          cout << room.name << endl;
        }

      }

    }
    if (strcmp(message, "#message3") == 0)
    {
      LogoutMess acc;
      acc.user_id = 3;
      send(client_socket, &acc, sizeof(acc), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }

    if (strcmp(message, "#message4") == 0)
    {
      /* code */
      AuctionRoomCreationMess roomMess;
      strcpy(roomMess.name, "room_4");
      roomMess.proprietor_id = 1;
      roomMess.created_at = 1702494570;
      send(client_socket, &roomMess, sizeof(roomMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message5") == 0)
    {
      /* code */
      JoinMess joinMess;
      joinMess.user_id = 3;
      joinMess.room_id = 4;
      send(client_socket, &joinMess, sizeof(joinMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message9") == 0)
    {
      DeleteItemMess itemMess;
      itemMess.user_id = 1;
      itemMess.item_id = 2;
      itemMess.room_id = 4;
      send(client_socket, &itemMess, sizeof(itemMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message11") == 0)
    {
      CreateItemMess itemMess;
      strcpy(itemMess.name, "abc");
      itemMess.user_id = 1;
      itemMess.room_id = 4;
      strcpy(itemMess.description, "shjshdjsh");
      itemMess.price = 5000;
      itemMess.BIN_price = 400000;
      itemMess.created_at = 1702494558;
      itemMess.end = 3600;
      send(client_socket, &itemMess, sizeof(itemMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }

  }
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cout << "abc" << endl;
  }

  struct sockaddr_in server_address;
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(argv[1]));
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  int result = connect(client_socket, (struct sockaddr *)&server_address, sizeof(struct sockaddr));
  if (result >= 0)
    printf("connect was successfull\n");

  pthread_t sendThreadID;
  thread_args args;
  args.conn_sock = client_socket;

  pthread_create(&sendThreadID, NULL, &handle_server, &args);

  pthread_join(sendThreadID, NULL);

  close(client_socket);
  return 0;
}
