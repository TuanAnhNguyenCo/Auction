#include "structure.h"
#include "string.h"
#include <iostream>

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
        accounts->push_back(acc);
    }
    fclose(f);
}

void print_accounts(list<Account> accounts)
{
    for (Account a : accounts)
    {
        cout << a.username << " " << a.password << " " << a.phoneNumber << " " << a.address << endl;
    }
}

void save_account(list<Account> accounts){
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

void save_status(list<Account> accounts,Account account)
{
    FILE *file;
    file = fopen("database/account.txt", "w+");
    if (file != NULL)
    {
        for (Account acc : accounts)
            if (strcasecmp(acc.username,account.username) == 0)
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
int checkAccountAvailability(Account account,list<Account> accounts)
{
    for (Account acc : accounts)
    {
        if (strcasecmp(acc.username,account.username) == 0)
            return 1;
    }
    return 2;
}

// 1: successfull 2: fail
int sign_up(list<Account> *accounts, Account account)
{
    if (checkAccountAvailability(account,*accounts) == 1)
        return 2;
    account.id = accounts->size() + 1;
    account.status = 0;
    accounts->push_back(account);
    save_account(*accounts);
    return 1;
}

// 1: successfull 2: fail 3: account is online on the other devices
int sign_in(list<Account> accounts, Account account){
    for (Account acc : accounts)
    {
        if (strcasecmp(acc.username, account.username) == 0 && strcasecmp(acc.username, account.username) == 0)
        {
            if(acc.status == 0)
            {
                account.status = 1;
                save_status(accounts, account);
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

void logout(list<Account> accounts, Account account)
{
    account.status = 0;
    save_status(accounts, account);
}

int handleSignup(SignupMess accountMess, list<Account> *accounts)
{
    Account account;
    strcpy(account.address, accountMess.address);
    strcpy(account.password, accountMess.password);
    strcpy(account.phoneNumber, accountMess.phoneNumber);
    strcpy(account.username, accountMess.username);
   
    return sign_up(accounts, account);
}
