#include "worker.h"
#include "config.h"
#include <QThread>


Worker::Worker() {}
void Worker::doWork() {
    char message[BUFF_SIZE];
    while(1){
        int rcvBytes = recv(MySingleton::instance().getValue(), message, BUFF_SIZE - 1, 0);
        emit signUp_dataReceived(message);
    }
}
