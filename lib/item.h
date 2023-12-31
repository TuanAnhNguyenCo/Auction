#include "stucture_item.h"
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
using namespace std;

#define BUFF_SIZE 8192
pthread_mutex_t blockThreadMutex_item;

void get_items(list<Item> *items)
{
    FILE *f = fopen("database/item.txt", "r");
    if (f == NULL)
    {
        cout << "Fail to read file" << endl;
        return;
    }

    Item item;
    while (fscanf(f, "%d %d %s %Lf %Lf %s %ld %ld %d %d", &item.id, &item.room_id, item.name, &item.reserve_price, &item.BIN_price, item.description, &item.created_at, &item.end, &item.status, &item.price_maker_id) == 10)
    {
        items->push_back(item);
    }
    fclose(f);
}

void get_item_by_id(list<Item> items, Item *item, int item_id)
{
    for (Item i : items)
    {
        if (i.id == item_id)
        {
            *item = i;
        }
    }
}

void print_items(list<Item> items)
{
    for (Item i : items)
    {
        cout << i.id << " " << i.room_id << " " << i.name << " " << i.reserve_price << " " << i.BIN_price << " " << i.description << " " << ctime(&i.created_at) << " " << ctime(&i.end) << i.status << " " << i.price_maker_id << endl;
    }
}

void save_items(list<Item> items)
{
    FILE *file;
    file = fopen("database/item.txt", "w+");
    if (file != NULL)
    {
        for (Item item : items)
        {
            fprintf(file, "%d %d %s %Lf %Lf %s %ld %ld %d %d\n", item.id, item.room_id, item.name, item.reserve_price, item.BIN_price, item.description, item.created_at, item.end, item.status, item.price_maker_id);
        }
    }
    else
    {
        printf("File is null");
    }
    fclose(file);
}
// 1: Successfully 2: Fail
int createItem(list<Item> *items, Item item)
{
    item.id = items->size() + 1;
    item.status = 1;
    items->push_back(item);
    save_items(*items);
    return 1;
}
// 1: success, 2: price error, 3: Item not found
int change_reserve_price(list<Item> *items, long double price, int price_maker_id, int item_id)
{
    for (Item &item : *items)
    {
        if (item.id == item_id && item.status == 1)
        {
            if (item.reserve_price + 10000 < price || price == item.BIN_price)
            {
                item.reserve_price = price;
                item.price_maker_id = price_maker_id;
                if (price == item.BIN_price)
                {
                    item.status = 0;
                }

                save_items(*items);
                return 1;
            }
            else
                return 2;
        }
    }
    return 3;
}

// 1: Successfully 2: Fail
int deleteItem(list<Item> *items, int item_id)
{
    if (items == nullptr || items->empty())
    {
        // Danh sách rỗng hoặc con trỏ không hợp lệ, không cần thực hiện thêm thao tác.
        return 2;
    }

    auto it = std::remove_if(items->begin(), items->end(),
                             [item_id](const Item &item)
                             { return item.id == item_id; });

    if (it == items->end())
    {
        // Không có phần tử thỏa mãn điều kiện, không cần thực hiện thêm thao tác.
        return 1;
    }

    items->erase(it, items->end());
    save_items(*items);
    return 1; // Phần tử đã được xóa thành công
}

//
int recv_and_handle_get_items(int conn_sock, list<Item> *items)
{
    cout << "Getting items..." << endl;
    char message[BUFF_SIZE];
    strcpy(message, to_string((*items).size()).c_str());
    cout << "Size " << message << endl;
    send(conn_sock, message, BUFF_SIZE - 1, 0);
    for (Item &item : *items)
    {
        send(conn_sock, &item, sizeof(Item), 0);
    }
    return 1;
}

int recv_and_handle_bid_items(int conn_sock, list<Item> *items)
{
    BidMess bidMess;
    cout << "Bidding ..." << endl;
    int rcvBytes = recv(conn_sock, &bidMess, sizeof(BidMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }

    char message[BUFF_SIZE];
    int status = change_reserve_price(items, bidMess.price, bidMess.user_id, bidMess.item_id);
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
    else if (status == 3)
    {
        strcpy(message, "#PRICE_INVALID");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}

int recv_and_handle_bin_price(int conn_sock, list<Item> *items)
{
    BinMess binMess;
    cout << "Bidding ..." << endl;
    int rcvBytes = recv(conn_sock, &binMess, sizeof(BinMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }
    Item item;
    get_item_by_id(*items, &item, binMess.item_id);
    cout << item.BIN_price << endl;

    char message[BUFF_SIZE];
    int status = change_reserve_price(items, item.BIN_price, binMess.user_id, binMess.item_id);
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
    else if (status == 3)
    {
        strcpy(message, "#PRICE_INVALID");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
    }
    return 1;
}
