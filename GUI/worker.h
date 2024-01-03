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
    void signout_dataReceived(char *message);
    void create_room_dataRecieved(char *message);
    void join_room_dataRecieved(char *message);
    void leaveRoom_dataReceived(char *message);
    void create_item_dataReceived(char *message);
    void handleKickingMember();
    void sendOff();
    void notifyInfo(char *message);
    void bid_dataReceived(char *message);
    void updateAuctionItem();
    void updateAuctionItemByID(int id);
    void callShowItems();
    void setNewTime();
    void stopTime();
    void showAlertMessage();
    void showJoinedRooms();
    void viewItemInfo();
    void showRoom();
    void sendImg(int id);
};

#endif // WORKER_H
