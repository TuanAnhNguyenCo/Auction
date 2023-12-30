#include "auctionroom.h"
#include "ui_auctionroom.h"
#include "room.h"
#include "config.h"
#include <QPixmap>
#include <QMessageBox>


AuctionRoom::AuctionRoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuctionRoom)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    //set icon for button
    ui->btn_backHome->setIcon(QIcon(":/image/icon_back.jpeg"));
    ui->btn_overview->setIcon(QIcon(":/image/icon_overview.png"));
    // image minh hoa
    QPixmap image(":/image/con-cho.jpeg");
    ui->label_image->setPixmap(image.scaled(ui->label_image->size(),Qt::KeepAspectRatio));
    // navigate
    ui->stackedWidget_2->insertWidget(1, &RoomOverview);
    ui->stackedWidget_2->insertWidget(2,&addItem);

    ui->stackedWidget_2->insertWidget(3,&joinerManage);
   
    connect(&RoomOverview, SIGNAL(participantClicked()), this, SLOT(moveToParticipant()));
    connect(&joinerManage, SIGNAL(backClicked()), this, SLOT(moveToOverview()));

    MySingleton::instance().auction_root_ui = ui->stackedWidget_2;
    connect(&RoomOverview, SIGNAL(backtoRoomClicked()), this, SLOT(backfromOverview()));
    connect(&RoomOverview, SIGNAL(addItemClicked()), this, SLOT(addNemItem()));
    connect(&addItem, SIGNAL(cancelClicked()), this, SLOT(moveToOverview()));
    connect(this, &AuctionRoom::callShowItems, &RoomOverview, &RoomOverview::showItems);
    connect(this, &AuctionRoom::callShowMembers, &joinerManage, &JoinerManage::showParticipents);


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
    OutRoomMess outRoomMess;
    outRoomMess.user_id = MySingleton::instance().getAccount().id;
    send(MySingleton::instance().getValue(), "19",BUFF_SIZE-1, 0);
    send(MySingleton::instance().getValue(), &outRoomMess, sizeof(OutRoomMess), 0);
    emit HomeClicked();
}
void AuctionRoom::on_btn_overview_clicked()
{
    emit callShowItems();
    ui->stackedWidget_2->setCurrentIndex(1);
}

void AuctionRoom::backfromOverview(){

    ui->stackedWidget_2->setCurrentIndex(0);
}

void AuctionRoom::moveToOverview(){
    emit callShowItems();
    ui->stackedWidget_2->setCurrentIndex(1);
}

void AuctionRoom::addNemItem(){
    ui->stackedWidget_2->setCurrentIndex(2);
}
void AuctionRoom::moveToParticipant(){
    emit callShowMembers();
    ui->stackedWidget_2->setCurrentIndex(3);
}
void AuctionRoom::on_btn_bin_clicked()
{
    QMessageBox::StandardButton reply;
    QMessageBox::question(this, "Confirm message", "Buy this item with BIN price?",
                          QMessageBox::Yes | QMessageBox::No);

}

