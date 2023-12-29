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
            rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                message[rcvBytes] = '\0';
            }
            emit signUp_dataReceived(message);
        }
        if (strcmp(message,"#message2") == 0)
        {
            rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                message[rcvBytes] = '\0';
            }
            // get account information
            if(strcmp(message,"#OK") ==0 )
            {
                Account account;
                recv(MySingleton::instance().getValue(), &account,sizeof(account), 0);
                MySingleton::instance().setAccount(account);

                char num_rooms[BUFF_SIZE];

                rcvBytes = recv(MySingleton::instance().getValue(), num_rooms, BUFF_SIZE - 1, 0);
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
            emit signIn_dataReceived(message);
        }
        if (strcmp(message,"#message3") == 0)
        {
            rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                message[rcvBytes] = '\0';
            }
            emit signout_dataReceived(message);

        }
        if (strcmp(message,"#message4") == 0){
            rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                message[rcvBytes] = '\0';
            }
            qDebug() << "Respond from creating room " << message;

            emit create_room_dataRecieved(message);
        }
        if (strcmp(message,"#message5") == 0){
            rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                message[rcvBytes] = '\0';
            }
            qDebug() << "Respond from joining room " << message;

            emit join_room_dataRecieved(message);
        }





    }
}
