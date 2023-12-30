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
signals:
    void HomeClicked();
private slots:
    void on_btn_backHome_clicked();
    void on_btn_bid_clicked();
    void on_btn_overview_clicked();
    void backfromOverview();
    void moveToOverview();
    void on_btn_bin_clicked();
    void addNemItem();
    void moveToParticipant();

private:
    Ui::AuctionRoom *ui;
    RoomOverview RoomOverview;
    addItem addItem;
    JoinerManage joinerManage;
};

#endif // AUCTIONROOM_H
