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

  while (1)
  {
    char *line = NULL;
    size_t lineSize = 0;
    ssize_t charCount = ::getline(&line, &lineSize, stdin);

    // char *messId = "1";
    ssize_t amountWasSent = send(client_socket, line, 1, 0);
    char message[BUFF_SIZE];
    recv(client_socket, message, BUFF_SIZE - 1, 0);
    cout << message << endl;
    LogoutMess accountMess;
    accountMess.user_id = 4;
    amountWasSent = send(client_socket, &accountMess, sizeof(accountMess), 0);
    char buffer[BUFF_SIZE];
    int rcvBytes = recv(client_socket, buffer, BUFF_SIZE - 1, 0);
    printf("%s\n", buffer);
  }

  close(client_socket);
  return 0;
}
