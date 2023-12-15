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

int main()
{

  struct sockaddr_in server_address;
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(5500);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  int result = connect(client_socket, (struct sockaddr *)&server_address, sizeof(struct sockaddr));
  if (result >= 0)
    printf("connect was successfull\n");

  char *line = NULL;
  size_t lineSize = 0;
  ssize_t charCount = ::getline(&line, &lineSize, stdin);

  // char *messId = "1";
  ssize_t amountWasSent = send(client_socket, line, sizeof(line), 0);

  char buffer[1024];
  int rcvBytes = recv(client_socket, buffer, 1024, 0);
  line[rcvBytes] = '/0';
  printf("%s\n", line);
  if (strcmp(line, "#0K"))
  {
    SignupMess accountMess;
    strcpy(accountMess.address, "bacninh");
    strcpy(accountMess.password, "123456");
    strcpy(accountMess.phoneNumber, "12345678");
    strcpy(accountMess.username, "anh3");
    ssize_t amountWasSent = send(client_socket, &accountMess, sizeof(accountMess), 0);
  }

  close(client_socket);
  return 0;
}
