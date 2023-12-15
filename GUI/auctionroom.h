#ifndef AUCTIONROOM_H
#define AUCTIONROOM_H

#include <QWidget>
#include <QInputDialog>
#include "roomoverview.h"

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

    void on_btn_bin_clicked();

private:
    Ui::AuctionRoom *ui;
    RoomOverview RoomOverview;
};

#endif // AUCTIONROOM_H
