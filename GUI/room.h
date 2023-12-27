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

#endif // ROOM_H
