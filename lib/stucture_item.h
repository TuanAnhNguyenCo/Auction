#include <cstring>
#include <iostream>
#include <ctime>

typedef struct
{
    int id;
    int room_id;
    int price_maker_id;
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

typedef struct
{
  int user_id;
  int room_id;
  int item_id;
} DeleteItemMess;

typedef struct
{
  long double price;
  int user_id;
  int item_id;
} BidMess;

typedef struct
{
  int user_id;
  int item_id;
} BinMess;
