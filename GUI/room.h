#ifndef ROOM_H
#define ROOM_H
#include <ctime>

typedef struct
{
    int proprietor_id;
    char name[100];
    time_t created_at;
} AuctionRoomCreationMess;


#endif // ROOM_H
