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
    int id;
    int room_id;
    char name[100];
    double reserve_price;
    double BIN_price;
    char description[1024];
    time_t created_at;
} Items;

typedef struct
{
    int id;
    int proprietor_id;
    char name[100];
    time_t created_at;
    int status; // 1 is active - 0 is closed
} AuctionRoom;

typedef struct
{
    int id;
    int user_id;
    int room_id;
} AuctionRoomParticipate;

typedef struct
{
    int id;
    int user_id;
    int room_id;
    int item_id;
    double bid_amount;
    time_t timestamp;
} Bid;

// typedef struct
// {
//     int id;
//     int type;
//     int current_user_id;
//     Account account;

// } MessageForm;
