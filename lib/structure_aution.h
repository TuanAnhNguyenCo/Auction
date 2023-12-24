#include <cstring>
#include <iostream>
#include <ctime>

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
    int proprietor_id;
    char name[100];
    time_t created_at;
} AuctionRoomCreationMess;
