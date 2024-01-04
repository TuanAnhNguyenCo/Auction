#include "auctionroom.h"
#include "ui_auctionroom.h"
#include "room.h"
#include "config.h"
#include <QPixmap>
#include <QMessageBox>
#include <QScrollArea>
#include <QElapsedTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QApplication>


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
    // // image minh hoa
    // QPixmap image(":/image/con-cho.jpeg");
    // ui->label_image->setPixmap(image.scaled(ui->label_image->size(),Qt::KeepAspectRatio));
    // navigate
    ui->stackedWidget_2->insertWidget(1, &roomoverview);
    ui->stackedWidget_2->insertWidget(2,&additem);

    ui->stackedWidget_2->insertWidget(3,&joinermanage);
   
    connect(&roomoverview, SIGNAL(participantClicked()), this, SLOT(moveToParticipant()));
    connect(&joinermanage, SIGNAL(backClicked()), this, SLOT(moveToOverview()));

    MySingleton::instance().auction_root_ui = ui->stackedWidget_2;
    connect(&roomoverview, SIGNAL(backtoRoomClicked()), this, SLOT(backfromOverview()));
    connect(&roomoverview, SIGNAL(addItemClicked()), this, SLOT(addNemItem()));
    connect(&roomoverview, SIGNAL(callItemByID(int)), this, SLOT(showItemByID(int)));
    connect(&additem, SIGNAL(cancelClicked()), this, SLOT(moveToOverview()));
    connect(this, &AuctionRoom::callShowItems, &roomoverview, &RoomOverview::showItems);
    connect(this, &AuctionRoom::callShowMembers, &joinermanage, &JoinerManage::showParticipents);
    // connect(this, &AuctionRoom::callShowItem, &AuctionRoom, &AuctionRoom::showParticipents);
    // In your main widget's constructor:

    // Thiết lập màu đỏ cho lcdNumber
    QPalette palette = ui->lcdNumber->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->lcdNumber->setPalette(palette);

    // Thiết lập stylesheet để làm cho nó đẹp hơn
    ui->lcdNumber->setStyleSheet("background-color: black;");

    // Thiết lập kiểu segment cho đẹp hơn
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);


}

AuctionRoom::~AuctionRoom()
{
    delete ui;

}

void AuctionRoom::on_btn_bid_clicked()
{
    long double bidding = QInputDialog::getDouble(this, tr("New bidding"),"Enter your bidding");
    long double current_prices = ui->new_prices->text().toDouble();
    if (bidding - current_prices < 10000 )
    {
        QMessageBox::information(this, tr("Failed"), "Each bid has to be greater than 10000 compared with the current price");
    }else{
        BidMess bidMess;
        bidMess.user_id = MySingleton::instance().getAccount().id;
        bidMess.item_id = MySingleton::instance().current_item_id;
        bidMess.price = bidding;
        send(MySingleton::instance().getValue(), "6", BUFF_SIZE-1, 0);
        send(MySingleton::instance().getValue(), &bidMess, sizeof(BidMess), 0);
    }
}
void AuctionRoom::updateCounter()
{
    // Giảm thời gian còn lại
    remainingTime--;
    MySingleton::instance().count = remainingTime;
    // alert
    if (remainingTime == 30)
    {
        if(MySingleton::instance().getAccount().id == MySingleton::instance().joinedRoom.proprietor_id)
        {
            GetParticipateMess mess;
            mess.room_id = MySingleton::instance().joinedRoom.id;
            send(MySingleton::instance().getValue(), "23", BUFF_SIZE-1, 0);
            send(MySingleton::instance().getValue(), &mess, sizeof(GetParticipateMess), 0);
        }
    }

    // Kiểm tra xem thời gian còn lại có âm không
    if (remainingTime < 0) {
        timer->stop();
        MySingleton::instance().is_auctioning = 0;
        qDebug() << "Countdown finished!";
        if(MySingleton::instance().getAccount().id == MySingleton::instance().joinedRoom.proprietor_id)
        {
            CloseItemMess closeItemMess;
            closeItemMess.item_id = MySingleton::instance().current_item_id;
            send(MySingleton::instance().getValue(), "21", BUFF_SIZE-1, 0);
            send(MySingleton::instance().getValue(), &closeItemMess, sizeof(CloseItemMess), 0);
        }
        return;
    }

    // Chuyển đổi thời gian thành giây và phút
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;

    // Hiển thị thời gian

    // Cập nhật giá trị cho label_timer
    ui->lcdNumber->display(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
}

void AuctionRoom::setNewTime(int duration){
    if (timer){
        // Dừng timer
        timer->stop();
    }
    // Khởi tạo timer
    timer = new QTimer(this);

    // Tạo bộ đếm mới
    // MySingleton::instance().remainingTime = 60;
    remainingTime = duration;
    MySingleton::instance().count = duration;

    // Kết nối sự kiện timeout của timer với hàm updateCounter
    QObject::connect(timer, &QTimer::timeout, this, &AuctionRoom::updateCounter);

    // Đặt khoảng thời gian giữa các sự kiện timeout là 1000 ms (1 giây)
    timer->start(1000);
}

void AuctionRoom::stopTime(){
    if (timer){
        MySingleton::instance().is_auctioning = 0;
        remainingTime = 0;
        // Dừng timer
        timer->stop();
        ui->lcdNumber->display(QString("%1:%2").arg(0, 2, 10, QChar('0')).arg(0, 2, 10, QChar('0')));
    }
}

void AuctionRoom::showAlertMessage(){
    QLabel *notification = new QLabel("!Important: Remaining Time: 30 s", this);
    notification->setMinimumSize(QSize(400, 40));
    notification->setStyleSheet("background-color: black; color: red; padding: 10px; border-radius: 10px;");
    notification->setWindowFlags(Qt::SubWindow);  // Make it a child of the main window

    QPropertyAnimation *animation = new QPropertyAnimation(notification, "geometry");
    animation->setDuration(3000); // 5 seconds

    int startPosX = this->width(); // Start from the right inside the main window
    int endPosX = this->width()/2; // End off the left edge of the main window

    animation->setStartValue(QRect(startPosX, 50, notification->width(), notification->height()));
    animation->setEndValue(QRect(endPosX, 50, notification->width(), notification->height()));

    // Timer to control the lifetime of the notification
    QTimer *lifetimeTimer = new QTimer(this);
    lifetimeTimer->setSingleShot(true); // Trigger only once

    connect(lifetimeTimer, &QTimer::timeout, this, [notification, lifetimeTimer]() {
        notification->hide(); // Hide the notification
        notification->deleteLater(); // Schedule the notification for deletion
        lifetimeTimer->deleteLater(); // Schedule the timer for deletion
    });

    notification->show();
    animation->start();
    lifetimeTimer->start(6000);
}


void AuctionRoom::notify(char *message){

    QMessageBox::information(this, tr("Notification"), message);


}

void AuctionRoom::showItem(){
    int status = 0;
    qDebug() << "Show item" << MySingleton::instance().is_auctioning;

    for (std::list<Item>::iterator it = MySingleton::instance().items.begin(); it != MySingleton::instance().items.end(); ++it){
        // qDebug() << "Room ID "<< MySingleton::instance().joinedRoom.id << "Loop ID " <<  it->room_id << "Status "<< it->status;
        if(it->room_id == MySingleton::instance().joinedRoom.id && it->status == 1 )
        {
            status = 1;
            MySingleton::instance().remainingTime = it->end;

            QPixmap image(it->url);  // ":/" đại diện cho đường dẫn trong tài nguyên Qt

            // Kiểm tra xem ảnh có được load thành công không
            if (image.isNull()) {
                qWarning("Cannot load image");

            }
            ui->label_image->setPixmap(image.scaled(ui->label_image->size(),Qt::KeepAspectRatio));
            MySingleton::instance().current_item_id = it->id;
            ui->label_binPrice->setText(QString::number(it->BIN_price, 'f', 2)); // 'f' for normal float notation, 2 for two decimal places
            ui->label_startPrice->setText(QString::number(it->reserve_price, 'f', 2)); // 'f' for normal float notation, 2 for two decimal places
            ui->label_nameItem->setText(it->name);
            ui->label_manufacturerItem->setText("Tuấn Anh");
            ui->label_description->setText(it->description);
            ui->label_description->setWordWrap(true);
            ui->label_nameRoom->setText(MySingleton::instance().joinedRoom.name);
            ui->label_nameOwner->setText(QString("Room owner ID: %1").arg(MySingleton::instance().joinedRoom.proprietor_id));
            ui->btn_bid->setVisible(true);
            ui->btn_bin->setVisible(true);
            ui->new_prices->setText(QString::number(it->current_price, 'f', 2));
            ui->label_closed->setVisible(false);
            ui->label_open->setVisible(true);
            ui->startAuction->setVisible(false);
            if (MySingleton::instance().getAccount().id == MySingleton::instance().joinedRoom.proprietor_id)
            {
                ui->btn_bid->setVisible(false);
                ui->btn_bin->setVisible(false);
                if (MySingleton::instance().is_auctioning == 1)
                {
                    ui->startAuction->setVisible(false);
                }else ui->startAuction->setVisible(true);
            }
            if (MySingleton::instance().is_auctioning == 0){
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
        ui->startAuction->setVisible(false);
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
            ui->new_prices->setText(QString::number(it->current_price, 'f', 2));
            ui->btn_bid->setVisible(false);
            ui->btn_bin->setVisible(false);
            if (it->status == 0)
            {
                ui->label_closed->setVisible(true);
                ui->label_open->setVisible(false);
            }else {
                ui->label_closed->setVisible(false);
                ui->label_open->setVisible(true);
            }

            ui->startAuction->setVisible(false);
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
    stopTime();

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


void AuctionRoom::on_startAuction_clicked()
{
    send(MySingleton::instance().getValue(), "22", BUFF_SIZE-1, 0);
    GetParticipateMess mess;
    mess.room_id = MySingleton::instance().joinedRoom.id;
    send(MySingleton::instance().getValue(), &mess, sizeof(GetParticipateMess), 0);
    size_t duration = MySingleton::instance().remainingTime;
    qDebug() << "Duration " << duration;
    send(MySingleton::instance().getValue(),&duration, sizeof(size_t), 0);
}

