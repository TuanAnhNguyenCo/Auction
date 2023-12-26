#include "worker.h"
#include "config.h"
#include <string.h>
#include <iostream>
#include <QThread>


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

            emit signIn_dataReceived(message);

        }



    }
}
