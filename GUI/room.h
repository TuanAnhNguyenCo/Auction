#ifndef ROOM_H
#define ROOM_H
#include <ctime>

typedef struct
{
    int proprietor_id;
    char name[100];
    time_t created_at;
} AuctionRoomCreationMess;

typedef struct
{
    int user_id;
    int room_id;
} JoinMess;

typedef struct
{
    int id;
    int proprietor_id;
    char name[100];
    time_t created_at;
    int status; // 1 is active - 0 is closed
} AuctionRoomStruct;

typedef struct
{
    int user_id;
} OutRoomMess;

typedef struct
{
    int id;
    int room_id;
    char name[100];
    long double reserve_price;
    long double BIN_price;
    char description[100];
    time_t created_at;
    time_t end;
    int status; // 1: openning, 0: closing
} Item;

typedef struct
{
    int user_id;
    int room_id;
    char name[100];
    long double price;
    long double BIN_price;
    char description[100];
    time_t created_at;
    time_t end;
} CreateItemMess;

#endif // ROOM_H
