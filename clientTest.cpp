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
    char *line = NULL;
    size_t lineSize = 0;
    ssize_t charCount = ::getline(&line, &lineSize, stdin);

    // char *messId = "1";
    ssize_t amountWasSent = send(client_socket, line, 1, 0);
    char message[BUFF_SIZE];

    recv(client_socket, message, BUFF_SIZE - 1, 0);
    cout << "123" << endl;
    cout << message << endl;
    if (strcmp(message, "#message2") == 0)
    {
      /* code */
      LoginMess acc;
      strcpy(acc.username, "anh3");
      strcpy(acc.password, "1");
      amountWasSent = send(client_socket, &acc, sizeof(acc), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message3") == 0)
    {
      LogoutMess acc;
      acc.user_id = 3;
      amountWasSent = send(client_socket, &acc, sizeof(acc), 0);
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
      amountWasSent = send(client_socket, &roomMess, sizeof(roomMess), 0);
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
      amountWasSent = send(client_socket, &joinMess, sizeof(joinMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
  }
}

int main(int argc, char *argv[])
{

  struct sockaddr_in server_address;
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(argv[1]));
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  int result = connect(client_socket, (struct sockaddr *)&server_address, sizeof(struct sockaddr));
  if (result >= 0)
    printf("connect was successfull\n");
  char s[3];

  pthread_t sendThreadID, recvThreadID;
  thread_args args;
  args.conn_sock = client_socket;

  cout << client_socket << endl;
  pthread_create(&sendThreadID, NULL, &handle_server, &args);

  pthread_join(sendThreadID, NULL);

  close(client_socket);
  return 0;
}
