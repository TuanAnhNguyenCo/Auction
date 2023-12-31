#include "auctionroom.h"
#include "ui_auctionroom.h"
#include "room.h"
#include "config.h"
#include <QPixmap>
#include <QMessageBox>
#include <QScrollArea>



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
    connect(&RoomOverview, SIGNAL(callItemByID(int)), this, SLOT(showItemByID(int)));
    connect(&addItem, SIGNAL(cancelClicked()), this, SLOT(moveToOverview()));
    connect(this, &AuctionRoom::callShowItems, &RoomOverview, &RoomOverview::showItems);
    connect(this, &AuctionRoom::callShowMembers, &joinerManage, &JoinerManage::showParticipents);
    // connect(this, &AuctionRoom::callShowItem, &AuctionRoom, &AuctionRoom::showParticipents);


}

AuctionRoom::~AuctionRoom()
{
    delete ui;

}

void AuctionRoom::on_btn_bid_clicked()
{
    long double bidding = QInputDialog::getDouble(this, tr("New bidding"),"Enter your bidding");
    long double current_prices = ui->new_prices->text().toDouble();
    if (bidding <= current_prices)
    {
        QMessageBox::information(this, tr("Failed"), "The bidding price must be higher than the current price");
    }else{
        BidMess bidMess;
        bidMess.user_id = MySingleton::instance().getAccount().id;
        bidMess.item_id = MySingleton::instance().current_item_id;
        bidMess.price = bidding;
        send(MySingleton::instance().getValue(), "6", BUFF_SIZE-1, 0);
        send(MySingleton::instance().getValue(), &bidMess, sizeof(BidMess), 0);
    }
}

void AuctionRoom::notify(char *message){
    if (strcmp(message,"#OK")==0)
    {
        QMessageBox::information(this, tr("Successful"), message);
    }
}

void AuctionRoom::showItem(){
    int status = 0;
    for (std::list<Item>::iterator it = MySingleton::instance().items.begin(); it != MySingleton::instance().items.end(); ++it){
        // qDebug() << "Room ID "<< MySingleton::instance().joinedRoom.id << "Loop ID " <<  it->room_id << "Status "<< it->status;
        if(it->room_id == MySingleton::instance().joinedRoom.id && it->status == 1 )
        {
            status = 1;
            MySingleton::instance().current_item_id = it->id;
            ui->label_binPrice->setText(QString::number(it->BIN_price, 'f', 2)); // 'f' for normal float notation, 2 for two decimal places
            ui->label_startPrice->setText(QString::number(it->reserve_price, 'f', 2)); // 'f' for normal float notation, 2 for two decimal places
            ui->label_nameItem->setText(it->name);
            ui->label_manufacturerItem->setText("Tuấn Anh");
            ui->label_description->setText(it->description);
            ui->label_description->setWordWrap(true);
            ui->label_nameRoom->setText(MySingleton::instance().joinedRoom.name);
            ui->label_nameOwner->setText(QString("User ID: %1").arg(MySingleton::instance().joinedRoom.proprietor_id));
            ui->btn_bid->setVisible(true);
            ui->btn_bin->setVisible(true);
            ui->new_prices->setText(QString::number(it->reserve_price, 'f', 2));
            ui->label_closed->setVisible(false);
            ui->label_open->setVisible(true);
            if (MySingleton::instance().getAccount().id == MySingleton::instance().joinedRoom.proprietor_id)
            {
                ui->btn_bid->setVisible(false);
                ui->btn_bin->setVisible(false);
            }
            break;
        }
    }
    if (status == 0)
    {
        ui->label_binPrice->setText("");
        ui->label_startPrice->setText("");
        ui->label_nameItem->setText("");
        ui->label_manufacturerItem->setText("");
        ui->label_description->setText("");
        ui->label_description->setWordWrap(true);
        ui->label_nameRoom->setText("");
        ui->label_nameOwner->setText("");
        ui->btn_bid->setVisible(false);
        ui->btn_bin->setVisible(false);
        ui->new_prices->setText("");
        ui->label_closed->setVisible(false);
        ui->label_open->setVisible(false);
    }
}

void AuctionRoom::showItemByID(int ID){

    for (std::list<Item>::iterator it = MySingleton::instance().items.begin(); it != MySingleton::instance().items.end(); ++it){
        // qDebug() << "Room ID "<< MySingleton::instance().joinedRoom.id << "Loop ID " <<  it->room_id << "Status "<< it->status;
        if(it->id == ID )
        {
            ui->label_binPrice->setText(QString::number(it->BIN_price, 'f', 2)); // 'f' for normal float notation, 2 for two decimal places
            ui->label_startPrice->setText(QString::number(it->reserve_price, 'f', 2)); // 'f' for normal float notation, 2 for two decimal places
            ui->label_nameItem->setText(it->name);
            ui->label_manufacturerItem->setText("Tuấn Anh");
            ui->label_description->setText(it->description);
            ui->label_description->setWordWrap(true);
            ui->label_nameRoom->setText(MySingleton::instance().joinedRoom.name);
            ui->label_nameOwner->setText(QString("User ID: %1").arg(MySingleton::instance().joinedRoom.proprietor_id));
            ui->new_prices->setText(QString::number(it->reserve_price, 'f', 2));
            ui->btn_bid->setVisible(false);
            ui->btn_bin->setVisible(false);
            ui->label_closed->setVisible(true);
            ui->label_open->setVisible(false);
            break;
        }
    }
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

    showItem();
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
    reply = QMessageBox::question(this, "Confirm message", "Buy this item with BIN price?",
                          QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        long double bin_prices = ui->label_binPrice->text().toDouble();
        long double current_prices = ui->new_prices->text().toDouble();
        if (bin_prices <=  current_prices)
        {
            QMessageBox::information(this, tr("Failed"), "You just use the bin function when The bin price is higher than the current price");
        }else{
            BinMess binMess;
            binMess.user_id = MySingleton::instance().getAccount().id;
            binMess.item_id = MySingleton::instance().current_item_id;
            send(MySingleton::instance().getValue(), "16", BUFF_SIZE-1, 0);
            send(MySingleton::instance().getValue(), &binMess, sizeof(BinMess), 0);
        }
    }

}

