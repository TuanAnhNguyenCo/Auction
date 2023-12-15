#include "worker.h"
#include <QThread>


Worker::Worker() {}
void Worker::doWork() {
    while(50)
    {
        emit dataReceived();
        QThread::msleep(1000);
    }


}
