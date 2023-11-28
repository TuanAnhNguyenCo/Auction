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
    string username;
    string password;
    string phoneNumber;
    string address;
    char status; // 1 is online - 0 is offline status
} Account;

typedef struct
{
    int id;
    int room_id;
    string name;
    double reserve_price;
    double BIN_price;
    string description;
    time_t created_at;
}Items;

typedef struct
{
    int id;
    int proprietor_id;
    string name;
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