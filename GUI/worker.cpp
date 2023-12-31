#include "worker.h"
#include "config.h"
#include "room.h"
#include <string.h>
#include <iostream>
#include <QThread>
#include <QDebug>
#include <QMessageBox>


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

        if (strcmp(message,"#message6") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            qDebug() << "Respond from bidding item " << respond;
            if (strcmp(respond,"#OK")==0){
                char notification[BUFF_SIZE-1];
                strcpy(notification,"The bidding item is successful");
                emit bid_dataReceived(notification);
            }else{
                char notification[BUFF_SIZE-1];
                strcpy(notification,"Failed, please try against");
                emit bid_dataReceived(notification);
            }
        }

        if (strcmp(message,"#message9") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            qDebug() << "Respond from deleting item " << respond;
        }

        if (strcmp(message,"#message10") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
             qDebug() << "Respond from kicking member " << respond;
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
        if ((strcmp(message,"#update_item") == 0))
        {
            MySingleton::instance().getItems();
        }
        if (strcmp(message,"#update_account_room")==0)
        {
            MySingleton::instance().getParticipents();
        }
        if (strcmp(message,"#update_time")==0)
        {
            emit setNewTime();
            qDebug("SetNewTime");
        }
        if(strcmp(message,"#stop_time") ==0)
        {
            emit stopTime();
        }
        if(strcmp(message,"#Alert") ==0)
        {
            emit showAlertMessage();
        }

        if (strcmp(message,"#message16") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            qDebug() << "Respond from bin item " << respond;
            if (strcmp(respond,"#OK")==0){
                char notification[BUFF_SIZE-1];
                strcpy(notification,"Bin is successful");
                emit bid_dataReceived(notification);
            }else{
                char notification[BUFF_SIZE-1];
                strcpy(notification,"Failed, please try against");
                emit bid_dataReceived(notification);
            }




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
                recv(MySingleton::instance().getValue(), &item, sizeof(Item), 0);
                MySingleton::instance().items.push_back(item);

            }

            emit updateAuctionItem();
            emit callShowItems();
            // emit updateAuctionItemByID(MySingleton::instance().current_item_id);

        }
        if (strcmp(message,"#message19")==0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            if (strcmp(respond,"#OK") ==0)
            {
                MySingleton::instance().joinedRoom.id = -2;
            }
            qDebug("Message: #Out room") ;

        }
        if (strcmp(message,"#message20")==0)
        {
            char num_participents[BUFF_SIZE];
            std::list<Account> participents;

            int rcvBytes = recv(MySingleton::instance().getValue(), num_participents, BUFF_SIZE - 1, 0);
            num_participents[rcvBytes] = '\0';
            MySingleton::instance().mems.room_id = MySingleton::instance().room_ids.back();
            int status = 0;
            if (MySingleton::instance().mems.room_id==MySingleton::instance().joinedRoom.id)
            {
                status = 1;
            }
            for (int i = 0; i < atoi(num_participents); i++)
            {
                Account participate;
                rcvBytes = recv(MySingleton::instance().getValue(), &participate, sizeof(Account), 0);
                participents.push_back(participate);
                    if (MySingleton::instance().getAccount().id == participate.id)
                    {
                        status = 2;
                    }

            }
            // if status == 0 will be send off because User have been kicked
            if (status == 1){
                if (MySingleton::instance().joinedRoom.id != -2)
                {
                    MySingleton::instance().joinedRoom.id = -1;
                    emit sendOff();
                    char notification[BUFF_SIZE-1];
                    strcpy(notification,"You have been sent off by proprietor");
                    emit notifyInfo(notification);
                }
            }
            MySingleton::instance().mems.accounts.clear();
            MySingleton::instance().mems.accounts = participents;

            MySingleton::instance().participents.push_back(MySingleton::instance().mems);
            MySingleton::instance().room_ids.pop_back();

            // show participents
            if (MySingleton::instance().room_ids.size() == 0)
            {
                emit handleKickingMember();
            }

        }
        if (strcmp(message,"#message21") == 0)
        {
            char respond[BUFF_SIZE];
            rcvBytes = recv(MySingleton::instance().getValue(), respond, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                respond[rcvBytes] = '\0';
            }
            qDebug() << "Respond from closing item " << respond;
        }
        if (strcmp(message,"#start_bidding") == 0)
        {
            MySingleton::instance().is_auctioning = 1;
            emit setNewTime();
            emit updateAuctionItem();

        }






    }
}
