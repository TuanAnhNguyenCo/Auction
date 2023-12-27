#include "worker.h"
#include "config.h"
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

            // emit create_room_dataRecieved(message);
        }
        if (strcmp(message,"#message5") == 0){
            rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
            if (rcvBytes > 0){
                message[rcvBytes] = '\0';
            }
            qDebug() << "Respond from joining room " << message;

            // emit join_room_dataRecieved(message);
        }





    }
}
