#include "structure_account.h"
#include "string.h"
#include "aution_room.h"
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
#include <algorithm>

#define BUFF_SIZE 8192
pthread_mutex_t blockThreadMutex_account;

using namespace std;
// typedef struct
// {
//     int id;
//     string username;
//     string password;
//     string phoneNumber;
//     string address;
//     char status; // 1 is online - 0 is offline status
// } Account;

void get_accounts(list<Account> *accounts)
{
    FILE *f = fopen("database/account.txt", "r");
    if (f == NULL)
    {
        cout << "Fail to read file" << endl;
        return;
    }

    Account acc;
    while (fscanf(f, "%d %s %s %s %s %d", &acc.id, acc.username, acc.password, acc.phoneNumber, acc.address, &acc.status) == 6)
    {
        acc.connectSocket = -1;
        accounts->push_back(acc);
    }
    fclose(f);
}
// 1: found, 2: not found
int get_account_by_id(int user_id, list<Account> accounts, Account *account)
{
    for (Account acc : accounts)
    {
        if (acc.id == user_id)
        {
            *account = acc;
            return 1;
        }
    }
    return 2;
}

void get_participate_by_room_id(list<AuctionRoomParticipate> account_rooms, list<Account> accounts,int room_id, list<Account> *participates){
    for (AuctionRoomParticipate account_room : account_rooms)
    {
        if (account_room.room_id == room_id && account_room.status == 1 )
        {
            Account participate;
            int status = get_account_by_id(account_room.user_id, accounts, &participate);
            if(status == 1) participates->push_back(participate);
        }
    }
}

void print_accounts(list<Account> accounts)
{
    for (Account a : accounts)
    {
        cout << a.username << " " << a.password << " " << a.phoneNumber << " " << a.address << endl;
    }
}

void save_account(list<Account> accounts)
{
    FILE *file;
    file = fopen("database/account.txt", "w+");
    if (file != NULL)
    {
        for (Account acc : accounts)
            fprintf(file, "%d %s %s %s %s %d\n", acc.id, acc.username, acc.password, acc.phoneNumber, acc.address, acc.status);
    }
    else
    {
        printf("File is null");
    }
    fclose(file);
}

void save_status(list<Account> accounts, Account account)
{
    FILE *file;
    file = fopen("database/account.txt", "w+");
    if (file != NULL)
    {
        for (Account acc : accounts)
            if (strcasecmp(acc.username, account.username) == 0)
                fprintf(file, "%d %s %s %s %s %d\n", acc.id, acc.username, acc.password, acc.phoneNumber, acc.address, account.status);
            else
                fprintf(file, "%d %s %s %s %s %d\n", acc.id, acc.username, acc.password, acc.phoneNumber, acc.address, acc.status);
    }
    else
    {
        printf("File is null");
    }
    fclose(file);
}

// 1: exist 2: no exist
int checkAccountAvailability(Account account, list<Account> accounts)
{
    for (Account acc : accounts)
    {
        if (strcasecmp(acc.username, account.username) == 0)
            return 1;
    }
    return 2;
}

// 1: successfull 2: fail
int sign_up(list<Account> *accounts, Account account)
{
    if (checkAccountAvailability(account, *accounts) == 1)
        return 2;
    account.id = accounts->size() + 1;
    account.status = 0;
    accounts->push_back(account);
    save_account(*accounts);

    return 1;
}

// 1: successfull 2: fail 3: account is online on the other devices
int sign_in(list<Account> *accounts, Account account, int conn_sock, Account *account_signed)
{
    for (Account &acc : *accounts)
    {
        if (strcasecmp(acc.username, account.username) == 0 && strcasecmp(acc.password, account.password) == 0)
        {

            if (acc.status == 0)
            {
                account.status = 1;
                acc.status = 1;
                acc.connectSocket = conn_sock;
                save_status(*accounts, account);
                *account_signed = acc;
                return 1;
            }
            else
            {
                return 3;
            }
        }
    }
    return 2;
}
// 1: Successfully 2: Fail
int logout(list<Account> *accounts, Account account)
{
    for (Account &acc : *accounts)
    {
        if (acc.id == account.id)
        {
            cout << acc.username << endl;
            if (acc.status == 0)
                return 2;
            acc.status = 0;
            save_status(*accounts, acc);
            return 1;
            break;
        }
    }

    return 2;
}

int handleSignup(SignupMess accountMess, list<Account> *accounts)
{

    Account account;
    strcpy(account.address, accountMess.address);
    strcpy(account.password, accountMess.password);
    strcpy(account.phoneNumber, accountMess.phoneNumber);
    strcpy(account.username, accountMess.username);
    pthread_mutex_lock(&blockThreadMutex_account);
    int status = sign_up(accounts, account);
    pthread_mutex_unlock(&blockThreadMutex_account);
    return status;
}

int handleLogin(LoginMess accountMess, list<Account> *accounts, int conn_sock, Account *account_signed)
{
    Account account;
    strcpy(account.password, accountMess.password);
    strcpy(account.username, accountMess.username);
    pthread_mutex_lock(&blockThreadMutex_account);
    int status = sign_in(accounts, account, conn_sock, account_signed);
    pthread_mutex_unlock(&blockThreadMutex_account);
    return status;
}

int handleLogout(LogoutMess accountMess, list<AuctionRoomParticipate> *listAccountRooms, list<Account> *accounts)
{
    Account account;
    account.id = accountMess.user_id;
    pthread_mutex_lock(&blockThreadMutex_account);
    int status = logout(accounts, account);
    if (status == 1)
    {
        outRoom(listAccountRooms, account.id);
    }
    pthread_mutex_unlock(&blockThreadMutex_account);
    return status;
}

// #OK is OK and #FAIL is fail
int recv_and_handle_sign_up(int conn_sock, list<Account> *accounts)
{
    SignupMess accountMess;
    cout << "Signing up" << endl;
    int rcvBytes = recv(conn_sock, &accountMess, sizeof(accountMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char message[BUFF_SIZE];
    int status = handleSignup(accountMess, accounts);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 2)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}
// #OK: successfull #FAIL: fail #ONLINE: account is online on the other devices
int recv_and_handle_login(int conn_sock, list<Account> *accounts)
{
    LoginMess accountMess;
    cout << "Logining" << endl;
    int rcvBytes = recv(conn_sock, &accountMess, sizeof(accountMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }
    Account account_signed;
    char message[BUFF_SIZE];
    int status = handleLogin(accountMess, accounts, conn_sock, &account_signed);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
        send(conn_sock, &account_signed, sizeof(account_signed), 0);
    }
    else if (status == 2)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 3)
    {
        strcpy(message, "#ONLINING");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}
// #OK is OK and #FAIL is fail
int recv_and_handle_logout(int conn_sock, list<AuctionRoomParticipate> *listAccountRooms, list<Account> *accounts)
{
    LogoutMess accountMess;
    cout << "Logouting" << endl;
    int rcvBytes = recv(conn_sock, &accountMess, sizeof(accountMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char message[BUFF_SIZE];
    int status = handleLogout(accountMess, listAccountRooms, accounts);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 2)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}

int recv_and_handle_get_rooms(int conn_sock, list<AuctionRoom> *rooms)
{
    cout << "Getting rooms..." << endl;
    char message[BUFF_SIZE];
    strcpy(message, to_string((*rooms).size()).c_str());
    send(conn_sock, message, BUFF_SIZE - 1, 0);
    for (AuctionRoom &room : *rooms)
    {
        send(conn_sock, &room, sizeof(AuctionRoom), 0);
    }
    return 1;
}

int recv_and_handle_kick_account(int conn_sock, list<AuctionRoom> *rooms, list<AuctionRoomParticipate> *list_account_rooms)
{
    cout << "Kicking rooms..." << endl;
    KickMess kickMess;
    int rcvBytes = recv(conn_sock, &kickMess, sizeof(KickMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }
    char message[BUFF_SIZE];
    if (checkRole(*rooms, kickMess.proprietor_id, kickMess.room_id) == 2 || kickMess.proprietor_id == kickMess.user_id)
    {
        strcpy(message, "#PERMISSION_DENIED");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
        return 2;
    }
    int status = outRoom(list_account_rooms, kickMess.user_id);
    if (status == 2)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 1)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}

int recv_and_handle_out_rooms(int conn_sock, list<AuctionRoomParticipate> *list_account_rooms)
{
    cout << "Outing rooms..." << endl;
    OutRoomMess outRoomMess;
    int rcvBytes = recv(conn_sock, &outRoomMess, sizeof(OutRoomMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }
    char message[BUFF_SIZE];

    int status = outRoom(list_account_rooms, outRoomMess.user_id);
    if (status == 2)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 1)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}

int recv_and_handle_get_participate(int conn_sock, list<AuctionRoomParticipate> *list_account_rooms, list<Account> *list_accounts)
{
    cout << "Getting participate..." << endl;
    GetParticipateMess roomMess;
    int rcvBytes = recv(conn_sock, &roomMess, sizeof(GetParticipateMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }
    list<Account> list_participate;

    get_participate_by_room_id(*list_account_rooms, *list_accounts, roomMess.room_id, &list_participate);

    char message[BUFF_SIZE];
    strcpy(message, to_string(list_participate.size()).c_str());
    send(conn_sock, message, BUFF_SIZE - 1, 0);
    for (Account acc : list_participate)
    {
        send(conn_sock, &acc, sizeof(Account), 0);
    }
    return 1;
}
