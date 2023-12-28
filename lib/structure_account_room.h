#include <cstring>
#include <iostream>
#include <ctime>

typedef struct
{
  int id;
  int user_id;
  int room_id;
} AuctionRoomParticipate;

typedef struct
{
  int user_id;
  int room_id;
} JoinMess;

typedef struct
{
  int user_id;
  int proprietor_id;
  int room_id;
} KickMess;

typedef struct
{
  int user_id;
} OutRoomMess;
