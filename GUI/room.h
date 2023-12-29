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

#endif // ROOM_H
