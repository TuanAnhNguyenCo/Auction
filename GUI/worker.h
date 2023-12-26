#ifndef WORKER_H
#define WORKER_H
#include <QObject>

class Worker : public QObject {
    Q_OBJECT

public:
    Worker();

public slots:
    void doWork();

signals:
    void signUp_dataReceived(char *message);
    void signIn_dataReceived(char *message);
};

#endif // WORKER_H
