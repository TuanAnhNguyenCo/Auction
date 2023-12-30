#include "worker.h"
#include "config.h"
#include "room.h"
#include <string.h>
#include <iostream>
#include <QThread>
#include <QDebug>


Worker::Worker() {}
void Worker::doWork() {
    char message[BUFF_SIZE];
    while(1){
        int rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
        if (rcvBytes > 0){
            message[rcvBytes] = '\0';
        }

        if (strcmp(message,"#message1") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            emit signUp_dataReceived(respond);
        }
        if (strcmp(message,"#message2") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            // get account information
            if(strcmp(respond,"#OK") ==0 )
            {
                Account account;
                recv(MySingleton::instance().getValue(), &account,sizeof(account), 0);
                MySingleton::instance().setAccount(account);
                MySingleton::instance().getRooms();
                MySingleton::instance().getItems();
            }
            emit signIn_dataReceived(respond);
        }
        if (strcmp(message,"#message3") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            emit signout_dataReceived(respond);

        }
        if (strcmp(message,"#message4") == 0){
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);

            respond[rcvBytes] = '\0';

            qDebug() << "Respond from creating room " << respond;

            emit create_room_dataRecieved(respond);
        }
        if (strcmp(message,"#message5") == 0){
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            qDebug() << "Respond from joining room " << respond;

            emit join_room_dataRecieved(respond);
        }
        // get message from creating auction
        if (strcmp(message,"#message11") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            emit create_item_dataReceived(respond);

        }
        if (strcmp(message,"#message14") == 0){
            char num_rooms[BUFF_SIZE];

            int rcvBytes = recv(MySingleton::instance().getValue(), num_rooms, BUFF_SIZE - 1, 0);
            num_rooms[rcvBytes] = '\0';
            qDebug() << "Num Rooms: " << num_rooms;
            MySingleton::instance().auction_rooms.clear();
            for (int i = 0; i < atoi(num_rooms); i++)
            {
                AuctionRoomStruct room;
                rcvBytes = recv(MySingleton::instance().getValue(), &room, sizeof(AuctionRoomStruct), 0);
                MySingleton::instance().auction_rooms.push_back(room);
            }
        }
        if ((strcmp(message,"#update_room") == 0))
        {
            MySingleton::instance().getRooms();
        }
        if (strcmp(message,"#update_account_room")==0)
        {
            qDebug("Message: #update_account_room") ;
        }
        // recieve items
        if (strcmp(message,"#message18")==0)
        {
            char num_items[BUFF_SIZE];

            int rcvBytes = recv(MySingleton::instance().getValue(), num_items, BUFF_SIZE - 1, 0);
            num_items[rcvBytes] = '\0';
            qDebug() << "Num items: " << num_items;
            MySingleton::instance().items.clear();
            for (int i = 0; i < atoi(num_items); i++)
            {
                Item item;
                rcvBytes = recv(MySingleton::instance().getValue(), &item, sizeof(Item), 0);
                MySingleton::instance().items.push_back(item);
            }

        }
        if (strcmp(message,"#message19")==0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            qDebug("Message: #Out room") ;

        }






    }
}
