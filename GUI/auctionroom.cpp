#include "auctionroom.h"
#include "ui_auctionroom.h"
#include <QPixmap>

AuctionRoom::AuctionRoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuctionRoom)
{
    ui->setupUi(this);
    QPixmap logo("/Users/dieulinh/untitled/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    //set icon for button
    ui->btn_backHome->setIcon(QIcon("/Users/dieulinh/auction/icon_back.jpeg"));
    ui->btn_overview->setIcon(QIcon("/Users/dieulinh/auction/icon_overview.png"));
    // image minh hoa
    QPixmap image("/Users/dieulinh/auction/con-cho.jpeg");
    ui->label_image->setPixmap(image.scaled(ui->label_image->size(),Qt::KeepAspectRatio));
    // navigate
    ui->stackedWidget_2->insertWidget(1, &RoomOverview);
    connect(&RoomOverview, SIGNAL(backtoRoomClicked()), this, SLOT(backfromOverview()));

}

AuctionRoom::~AuctionRoom()
{
    delete ui;

}

void AuctionRoom::on_btn_bid_clicked()
{
    double bidding = QInputDialog::getDouble(this, tr("New bidding"),"Enter your bidding");
}

// navigate
void AuctionRoom::on_btn_backHome_clicked() //back home
{
    emit HomeClicked();
}
void AuctionRoom::on_btn_overview_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}
void AuctionRoom::backfromOverview(){
    ui->stackedWidget_2->setCurrentIndex(0);
}

