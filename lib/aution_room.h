#include "structure_aution.h"
#include "account_room.h"
#include "item.h"
#include "string.h"
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <pthread.h>
#include <algorithm>

#define BUFF_SIZE 8192
pthread_mutex_t blockThreadMutex_auction;

void get_rooms(list<AuctionRoom> *rooms)
{
    FILE *f = fopen("database/auctionRoom.txt", "r");
    if (f == NULL)
    {
        cout << "Fail to read file" << endl;
        return;
    }

    AuctionRoom room;
    while (fscanf(f, "%d %d %s %ld %d", &room.id, &room.proprietor_id, room.name, &room.created_at, &room.status) == 5)
    {
        rooms->push_back(room);
    }
    fclose(f);
}

void print_rooms(list<AuctionRoom> rooms)
{
    for (AuctionRoom r : rooms)
    {
        cout << r.id << " " << r.proprietor_id << " " << r.name << " " << ctime(&r.created_at) << r.status << endl;
    }
}

int get_proprietor_id(int room_id, list<AuctionRoom> rooms){
    for (AuctionRoom r : rooms)
    {
        if (r.id == room_id)
        {
            return r.proprietor_id;
        }
    }
    return -1;
}

void save_rooms(list<AuctionRoom> rooms)
{
    FILE *file;
    file = fopen("database/auctionRoom.txt", "w+");
    if (file != NULL)
    {
        for (AuctionRoom room : rooms)
            fprintf(file, "%d %d %s %ld %d\n", room.id, room.proprietor_id, room.name, room.created_at, room.status);
    }
    else
    {
        printf("File is null");
    }
    fclose(file);
}
// 1: joined, 2: not join
int closeRoom(int room_id, int proprietor_id,list<AuctionRoom> *rooms)
{
    for (AuctionRoom &r : *rooms)
    {
        if (r.id == room_id && r.status == 1 && proprietor_id == r.proprietor_id)
        {
            r.status = 0;
            save_rooms(*rooms);
            return 1;
        }
    }
    return 2;
}
// 1: Successfully 2: Fail
int create(list<AuctionRoom> *rooms, list<AuctionRoomParticipate> *listAccountRooms, AuctionRoom room)
{
    if (checkValidJoin(room.proprietor_id, *listAccountRooms) == 2)
    {
        room.id = rooms->size() + 1;
        room.status = 1;
        rooms->push_back(room);

        AuctionRoomParticipate newAccountRoom;
        newAccountRoom.user_id = room.proprietor_id;
        newAccountRoom.room_id = room.id;
        listAccountRooms->push_back(newAccountRoom);

        save_rooms(*rooms);
        save_account_rooms(*listAccountRooms);
        return 1;
    }
    return 2;
}
// 1: is proprietor, 2: permission denied
int checkRole(list<AuctionRoom> rooms, int user_id, int room_id)
{
    for (AuctionRoom room : rooms)
    {
        if (user_id == room.proprietor_id && room_id == room.id && room.status == 1)
        {
            return 1;
        }
    }
    return 2;
}

// 1: Successfully 2: Fail
int handleCreateAuction(AuctionRoomCreationMess roomMess, list<AuctionRoomParticipate> *listAccountRooms, list<AuctionRoom> *rooms)
{
    AuctionRoom room;
    strcpy(room.name, roomMess.name);
    room.created_at = roomMess.created_at;
    room.proprietor_id = roomMess.proprietor_id;
    pthread_mutex_lock(&blockThreadMutex_auction);
    int status = create(rooms, listAccountRooms, room);
    pthread_mutex_unlock(&blockThreadMutex_auction);
    return status;
}
// #OK is OK and #FAIL is fail
int recv_and_handle_create_auction(int conn_sock, list<AuctionRoomParticipate> *listAccountRooms, list<AuctionRoom> *rooms)
{
    AuctionRoomCreationMess roomMess;
    cout << "Creating..." << endl;
    int rcvBytes = recv(conn_sock, &roomMess, sizeof(roomMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char message[BUFF_SIZE];
    int status = handleCreateAuction(roomMess, listAccountRooms, rooms);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 2)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}

// 1: Successfully 2: Fail
int handleCreateItem(CreateItemMess itemMess, list<AuctionRoom> *listRooms, list<Item> *items)
{
    if (checkRole(*listRooms, itemMess.user_id, itemMess.room_id) == 1)
    {
        Item item;
        strcpy(item.name, itemMess.name);
        item.room_id = itemMess.room_id;
        item.reserve_price = itemMess.price;
        item.current_price = itemMess.price;
        item.BIN_price = itemMess.BIN_price;
        strcpy(item.description, itemMess.description);
        item.created_at = itemMess.created_at;
        item.end = itemMess.end;
        item.price_maker_id = get_proprietor_id(itemMess.room_id, *listRooms);
        pthread_mutex_lock(&blockThreadMutex_auction);
        int status = createItem(items, item);
        pthread_mutex_unlock(&blockThreadMutex_auction);
        return status;
    }
    return 2;
}
// #OK is OK and #FAIL is fail
int recv_and_handle_create_item(int conn_sock, list<Item> *items, list<AuctionRoom> *rooms)
{
    CreateItemMess itemMess;
    cout << "Creating item..." << endl;
    int rcvBytes = recv(conn_sock, &itemMess, sizeof(itemMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char message[BUFF_SIZE];
    int status = handleCreateItem(itemMess, rooms, items);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 2)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}
// 1: existed 2: not exist
int checkItemExist(list<Item> items, int item_id, int room_id)
{
    for (Item item : items)
    {
        if (item.id == item_id && item.room_id == room_id)
        {
            return 1;
        }
    }
    return 2;
}
// 1: Successfully 2: Fail
int handleDeleteItem(DeleteItemMess itemMess, list<AuctionRoom> *listRooms, list<Item> *items)
{
    if (checkRole(*listRooms, itemMess.user_id, itemMess.room_id) == 1 && checkItemExist(*items, itemMess.item_id, itemMess.room_id) == 1)
    {
        pthread_mutex_lock(&blockThreadMutex_auction);
        int status = deleteItem(items, itemMess.item_id);
        pthread_mutex_unlock(&blockThreadMutex_auction);
        return status;
    }
    return 2;
}
// #OK is OK and #FAIL is fail
int recv_and_handle_delete_item(int conn_sock, list<Item> *items, list<AuctionRoom> *rooms)
{
    DeleteItemMess itemMess;
    cout << "Deleting item..." << endl;
    int rcvBytes = recv(conn_sock, &itemMess, sizeof(itemMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char message[BUFF_SIZE];
    int status = handleDeleteItem(itemMess, rooms, items);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    else if (status == 2)
    {
        strcpy(message, "#FAIL");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}
