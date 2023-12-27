#ifndef ACCOUNT_H
#define ACCOUNT_H
#define BUFF_SIZE 8192
typedef struct
{
    char username[50];
    char password[50];
    char phoneNumber[50];
    char address[100];
} SignupMess;

typedef struct
{
    char username[50];
    char password[50];
} LoginMess;

typedef struct
{
    int id;
    char username[50];
    char password[50];
    char phoneNumber[50];
    char address[100];
    int status; // 1 is online - 0 is offline status
    int connectSocket;
} Account;

typedef struct
{
    int user_id;
} LogoutMess;

extern char ResponedMessage[BUFF_SIZE];

#endif // ACCOUNT_H
