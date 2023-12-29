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
    while (fscanf(f, "%d %d %s %Lf %Lf %s %ld %ld %d", &item.id, &item.room_id, item.name, &item.reserve_price, &item.BIN_price, item.description, &item.created_at, &item.end, &item.status) == 9)
    {
        items->push_back(item);
    }
    fclose(f);
}

void print_items(list<Item> items)
{
    for (Item i : items)
    {
        cout << i.id << " " << i.room_id << " " << i.name << " " << i.reserve_price << " " << i.BIN_price << " " << i.description << " " << ctime(&i.created_at) << " " << ctime(&i.end) << i.status << endl;
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
            fprintf(file, "%d %d %s %Lf %Lf %s %ld %ld %d\n", item.id, item.room_id, item.name, item.reserve_price, item.BIN_price, item.description, item.created_at, item.end, item.status);
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
int recv_and_handle_get_items(int conn_sock, list<Item> *items){
    cout << "Getting items..." << endl;
    char message[BUFF_SIZE];
    strcpy(message, to_string((*items).size()).c_str());
    send(conn_sock, message, BUFF_SIZE - 1, 0);
    for (Item &item : *items)
    {
        send(conn_sock, &item, sizeof(Item), 0);
    }
    return 1;
}
