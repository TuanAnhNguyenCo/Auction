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

extern char ResponedMessage[BUFF_SIZE];

#endif // ACCOUNT_H
