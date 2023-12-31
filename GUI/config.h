// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <QDebug>
#include <pthread.h>
#include <unistd.h>
#include "account.h"
#include "room.h"
#include <QtGui>
#include <QStackedWidget>
#include "worker.h"

#define BUFF_SIZE 8192


class MySingleton {
public:
    static MySingleton& instance();

    // Các phương thức để truy cập và cập nhật biến
    int getValue() const;
    void setValue(int server_sock);

    Account getAccount() const;
    void setAccount(Account account);
    void getRooms();
    void getItems();
    void getParticipents();
    int current_item_id;
    std::list<AuctionRoomStruct> auction_rooms;
    std::list<Item> items;
    std::list<Participents> participents;
    std::list<int> room_ids;
    Participents mems;


    QStackedWidget *auction_root_ui;
    QStackedWidget *home;
    QWidget* scrollRoomsContent;
    AuctionRoomStruct joinedRoom;
    Worker *worker;



private:
    MySingleton();   // Constructor private
    ~MySingleton();  // Destructor private

    // Không cho phép sao chép
    MySingleton(const MySingleton&) = delete;
    MySingleton& operator=(const MySingleton&) = delete;

    // Biến để lưu giữ trạng thái
    int server_sock;
    Account account;
    static MySingleton* instancePtr;

};

#endif // CONFIG_H
