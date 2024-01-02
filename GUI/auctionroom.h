#ifndef AUCTIONROOM_H
#define AUCTIONROOM_H

#include <QWidget>
#include <QInputDialog>
#include "roomoverview.h"
#include "additem.h"
#include "joinermanage.h"
namespace Ui {
class AuctionRoom;
}

class AuctionRoom : public QWidget
{
    Q_OBJECT

public:
    explicit AuctionRoom(QWidget *parent = nullptr);
    ~AuctionRoom();
    int remainingTime = 2 * 60; // 2 minutes
    QTimer *timer;
    void updateCounter();
signals:
    void HomeClicked();
    void callShowItems();
    void callShowMembers();
    void callShowItem();
private slots:
    void on_btn_backHome_clicked();
    void on_btn_bid_clicked();
    void on_btn_overview_clicked();
    void backfromOverview();
    void moveToOverview();
    void on_btn_bin_clicked();
    void addNemItem();
    void moveToParticipant();
    void on_startAuction_clicked();

public slots:
    void showItem();
    void showItemByID(int id);
    void notify(char *message);
    void setNewTime();
    void stopTime();
    void showAlertMessage();


private:
    Ui::AuctionRoom *ui;

public:
    addItem additem;

    JoinerManage joinermanage; //

    RoomOverview roomoverview; //

};



#endif // AUCTIONROOM_H
