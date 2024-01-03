#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

typedef struct
{
    int message_type;
    int current_user_id;
} MessageForm;

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
    int user_id;
} LogoutMess;

typedef struct
{
    int user_id;
} GetRoomHistoryMess;




// typedef struct
// {
//     int id;
//     int type;
//     int current_user_id;
//     Account account;

// } MessageForm;
