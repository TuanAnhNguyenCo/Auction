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
#include <filesystem>
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
    std::filesystem::path currentPath = std::filesystem::current_path();
    // Chuyển đổi đường dẫn thành chuỗi

    Item item;
    while (fscanf(f, "%d %d %s %Lf %Lf %s %ld %ld %d %d %Lf %s", &item.id, &item.room_id, item.name, &item.current_price, &item.BIN_price, item.description, &item.created_at, &item.end, &item.status, &item.price_maker_id, &item.reserve_price, item.url) == 12)
    {
        string pathString = currentPath.string();
        pathString += "/";
        pathString += item.url;
        strcpy(item.url, pathString.c_str());
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
        cout << i.id << " " << i.room_id << " " << i.name << " " << i.current_price << " " << i.BIN_price << " " << i.description << " " << ctime(&i.created_at) << " " << ctime(&i.end) << i.status << " " << i.price_maker_id << endl;
    }
}

void save_items(list<Item> items)
{
    FILE *file;
    file = fopen("database/item.txt", "w+");
    std::filesystem::path currentPath = std::filesystem::current_path();
    // Chuyển đổi đường dẫn thành chuỗi
    string pathString = currentPath.string();
    pathString += "/";
    // Kiểm tra xem searchString có xuất hiện trong url hay không

    if (file != NULL)
    {
        for (Item item : items)
        {

            string new_url = item.url;
            size_t pos = new_url.find(pathString);

            // Nếu searchString xuất hiện, loại bỏ nó
            if (pos != std::string::npos)
            {
                new_url.erase(pos, pathString.length());
            }
            strcpy(item.url, new_url.c_str());
            fprintf(file, "%d %d %s %Lf %Lf %s %ld %ld %d %d %Lf %s\n", item.id, item.room_id, item.name, item.current_price, item.BIN_price, item.description, item.created_at, item.end, item.status, item.price_maker_id, item.reserve_price, item.url);
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
    strcpy(item.url, "./GUI/con-cho.jpeg");
    items->push_back(item);
    save_items(*items);
    return 1;
}
// 1: Successfully 2: Fail
int closeItem(list<Item> *items, int item_id)
{
    for (Item &item : *items)
    {
        if (item.id == item_id)
        {
            item.status = 0;
            save_items(*items);
            return 1;
        }
    }
    return 2;
}
// 1: success, 2: price error, 3: Item not found
int change_current_price(list<Item> *items, long double price, int price_maker_id, int item_id)
{
    for (Item &item : *items)
    {
        if (item.id == item_id && item.status == 1)
        {
            if (item.current_price + 10000 <= price)
            {
                item.current_price = price;
                item.price_maker_id = price_maker_id;
                save_items(*items);
                return 1;
            }
            else
                return 2;
        }
    }
    return 3;
}

// 1: success, 2: not found
int change_url(list<Item> *items, char *url, int item_id)
{
    std::filesystem::path currentPath = std::filesystem::current_path();
    // Chuyển đổi đường dẫn thành chuỗi
    string pathString = currentPath.string();
    pathString += "/";
    for (Item &item : *items)
    {
        if (item.id == item_id)
        {

            pathString += url;
            strcpy(item.url, pathString.c_str());
            save_items(*items);
            return 1;
        }
    }
    return 2;
}
// 1: success, 3: Item not found
int change_bin_price(list<Item> *items, int price_maker_id, int item_id)
{
    for (Item &item : *items)
    {
        if (item.id == item_id && item.status == 1)
        {

            item.current_price = item.BIN_price;
            item.price_maker_id = price_maker_id;
            item.status = 0;
            save_items(*items);
            return 1;
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
    Item item;
    get_item_by_id(*items, &item, bidMess.item_id);

    char message[BUFF_SIZE];
    int status = change_current_price(items, bidMess.price, bidMess.user_id, bidMess.item_id);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
        return item.room_id;
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
    return -1;
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

    char message[BUFF_SIZE];
    int status = change_bin_price(items, binMess.user_id, binMess.item_id);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
        return item.room_id;
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
    return -1;
}

int recv_and_handle_close_item(int conn_sock, list<Item> *items)
{
    CloseItemMess closeItemMess;
    cout << "Closing item ..." << endl;
    int rcvBytes = recv(conn_sock, &closeItemMess, sizeof(CloseItemMess), 0);
    if (rcvBytes <= 0)
    {
        close(conn_sock);
        return 0;
    }
    Item item;
    get_item_by_id(*items, &item, closeItemMess.item_id);

    char message[BUFF_SIZE];
    int status = closeItem(items, closeItemMess.item_id);
    if (status == 1)
    {
        strcpy(message, "#OK");
        send(conn_sock, message, BUFF_SIZE - 1, 0);
        return item.room_id;
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
    return -1;
}
