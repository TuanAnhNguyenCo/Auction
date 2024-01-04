#include <cstring>
#include <iostream>
#include <ctime>

typedef struct
{
  int id;
  int user_id;
  int room_id;
  int status; // 1: on room, 2: out room
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

typedef struct
{
  int room_id;
} GetParticipateMess;

typedef struct
{
  int is_auctioning;
  int duration;
  GetParticipateMess mess;
} TimeCounting;