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

// void *handle_server_auto(void *args)
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
    if (strcmp(line, "abc") != 0)
    {
      send(client_socket, line, strlen(line), 0);
    }

    char message[BUFF_SIZE];

    ssize_t recvbytes = recv(client_socket, message, BUFF_SIZE - 1, 0);
    if (recvbytes <= 0)
    {
      break;
    }

    message[recvbytes] = '\0';
    cout << message << endl;
    if (strcmp(message, "#message2") == 0)
    {
      /* code */
      LoginMess acc;
      cin.getline(acc.username, sizeof(acc.username));
      // strcpy(acc.username, "anh1");
      strcpy(acc.password, "1");
      send(client_socket, &acc, sizeof(acc), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
      if (strcmp(buffer, "#OK") == 0)
      {
        Account account_signed;
        recv(client_socket, &account_signed, sizeof(account_signed), 0);
        cout << account_signed.address << endl;
      }
    }
    if (strcmp(message, "#message3") == 0)
    {
      LogoutMess acc;
      char line[10];
      cin.getline(line, sizeof(line));
      acc.user_id = atoi(line);
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

      rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
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

      rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message6") == 0)
    {
      /* code */
      BidMess bidMess;
      bidMess.user_id = 3;
      bidMess.item_id = 1;
      bidMess.price = 16000;
      send(client_socket, &bidMess, sizeof(BidMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);

      rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);

      rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
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
    if (strcmp(message, "#message10") == 0)
    {
      KickMess kickMess;
      kickMess.user_id = 3;
      kickMess.proprietor_id = 2;
      kickMess.room_id = 4;
      send(client_socket, &kickMess, sizeof(kickMess), 0);
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
    if (strcmp(message, "#message14") == 0)
    {
      char message[BUFF_SIZE];
      ssize_t rcvBytes = recv(client_socket, message, BUFF_SIZE - 1, 0);
      message[rcvBytes] = '\0';
      cout << message << endl;
      for (int i = 0; i < atoi(message); i++)
      {
        AuctionRoom room;
        rcvBytes = recv(client_socket, &room, sizeof(AuctionRoom), 0);
        cout << room.name << endl;
      }
    }
    if (strcmp(message, "#message16") == 0)
    {
      /* code */
      BinMess binMess;
      binMess.user_id = 3;
      binMess.item_id = 1;
      send(client_socket, &binMess, sizeof(BinMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);

      rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);

      rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message18") == 0)
    {
      char message[BUFF_SIZE];
      ssize_t rcvBytes = recv(client_socket, message, BUFF_SIZE - 1, 0);
      message[rcvBytes] = '\0';
      cout << message << endl;
      for (int i = 0; i < atoi(message); i++)
      {
        Item item;
        rcvBytes = recv(client_socket, &item, sizeof(Item), 0);
        cout << item.name << " " << item.current_price << endl;
      }
    }
    if (strcmp(message, "#message19") == 0)
    {
      OutRoomMess outRoomMess;
      outRoomMess.user_id = 3;
      send(client_socket, &outRoomMess, sizeof(OutRoomMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message20") == 0)
    {
      GetParticipateMess room;
      room.room_id = 4;
      send(client_socket, &room, sizeof(GetParticipateMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      for (int i = 0; i < atoi(buffer); i++)
      {
        Account participate;
        rcvBytes = recv(client_socket, &participate, sizeof(Account), 0);
        cout << participate.username << endl;
      }
    }
    if (strcmp(message, "#message21") == 0)
    {
      CloseItemMess closeItemMess;
      closeItemMess.item_id = 1;
      send(client_socket, &closeItemMess, sizeof(CloseItemMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);

      rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      printf("%s\n", buffer);
    }
    if (strcmp(message, "#message24") == 0)
    {
      GetParticipateMess room;
      room.room_id = 4;
      send(client_socket, &room, sizeof(GetParticipateMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      for (int i = 0; i < atoi(buffer); i++)
      {
        Account participate;
        rcvBytes = recv(client_socket, &participate, sizeof(Account), 0);
        cout << participate.username << endl;
      }
    }
    if (strcmp(message, "#message25") == 0)
    {
      GetRoomHistoryMess user;
      user.user_id = 3;
      send(client_socket, &user, sizeof(GetRoomHistoryMess), 0);
      char buffer[BUFF_SIZE];
      int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
      buffer[rcvBytes] = '\0';
      for (int i = 0; i < atoi(buffer); i++)
      {
        AuctionRoom participate;
        rcvBytes = recv(client_socket, &participate, sizeof(AuctionRoom), 0);
        cout << participate.name << endl;
      }
    }
    if (strcmp(message, "#message26") == 0)
    {
      // read img
      Image image;
      FILE *fp;
      fp = fopen("./GUI/con-cho.jpeg", "rb");
      if (fp == NULL)
      {

        perror("Failed to open image file");
        close(client_socket);
        continue;
      }
      int n = fread(image.buff, 1, sizeof(BUFF_SIZE - 1), fp);
      if (n <= 0)
      {
        continue;
      }
      // status == 2: carry out function 2
      image.status = 2;
      image.isFirst = 1;
      image.item_id = 1;
      send(client_socket, &image, sizeof(Image), 0);

      // read and send to server
      while (1)
      {
        int n = fread(image.buff, 1, BUFF_SIZE - 1, fp);
        if (n <= 0)
        {
          break;
        }
        // status == 2: carry out function 2
        image.status = 2;
        image.isFirst = 0;
        send(client_socket, "26", BUFF_SIZE - 1, 0);
        send(client_socket, &image, sizeof(Image), 0);
      }
      fclose(fp);
      // notify to server that sending image has done
      image.status = 3;
      send(client_socket, "26", BUFF_SIZE - 1, 0);
      send(client_socket, &image, sizeof(Image), 0);

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
