#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <list>
#include "lib/account.h"
#define BUFF_SIZE 8192
#define BACKLOG 2
char buff[BUFF_SIZE];



int main()
{
    list<Account> accounts;
    Account account;
    strcpy(account.username, "anh2");
    strcpy(account.password, "1");
    strcpy(account.phoneNumber, "0374470525");
    strcpy(account.address, "HaNoi");
    get_accounts(&accounts);
    print_accounts(accounts);
    cout << sign_up(&accounts, account);
    cout << sign_in(accounts, account);
    logout(accounts, account);
}