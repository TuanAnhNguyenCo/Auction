#include "roomoverview.h"
#include "ui_roomoverview.h"

RoomOverview::RoomOverview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RoomOverview)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->btn_backAuctionroom->setIcon(QIcon(":/image/icon_back.jpeg"));

}

RoomOverview::~RoomOverview()
{
    delete ui;
}

void RoomOverview::on_btn_backAuctionroom_clicked()
{
    emit backtoRoomClicked();
}


