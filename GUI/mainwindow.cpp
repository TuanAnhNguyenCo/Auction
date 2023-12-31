#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QString>
#include <QThread>
#include "config.h"
#include "worker.h"
#include "room.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    worker = new Worker();
    workerThread = new QThread();

    worker->moveToThread(workerThread);
    MySingleton::instance().worker = worker;

    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->stackedWidget->insertWidget(1, &CreatePage);
    ui->stackedWidget->insertWidget(2, &HistoryPage);
    ui->stackedWidget->insertWidget(3,&AuctionRoom);
    ui->stackedWidget->insertWidget(4,&LogIn);
    ui->stackedWidget->insertWidget(5,&SignUp);
    ui->stackedWidget->setCurrentIndex(4); // set up Login page
    MySingleton::instance().home = ui->stackedWidget;
    connect(&CreatePage, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&CreatePage, SIGNAL(HistoryClicked()), this, SLOT(moveHistoryTab()));
    connect(&HistoryPage, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&AuctionRoom, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&HistoryPage, SIGNAL(CreateClicked()), this, SLOT(moveCreateTab()));
    connect(&LogIn,SIGNAL(SignupClicked()), this, SLOT(moveSignupPage()));
    connect(&LogIn,SIGNAL(LoginOk()), this, SLOT(moveHome()));
    connect(&SignUp,SIGNAL(LoginClicked()), this, SLOT(moveLoginPage()));
    connect(this, &MainWindow::callShowItem,&AuctionRoom, &AuctionRoom::showItem);





    connect(workerThread, &QThread::started, worker, &Worker::doWork);
    connect(worker, &Worker::signUp_dataReceived, &SignUp, &SignUp::update_sign_up);
    connect(worker, &Worker::signIn_dataReceived, &LogIn, &LogIn::update_sign_in);
    connect(worker, &Worker::signout_dataReceived,this, &MainWindow::handleLogout);
    connect(worker, &Worker::join_room_dataRecieved,this, &MainWindow::moveAuctionRoom);
    connect(worker, &Worker::create_room_dataRecieved,&CreatePage, &CreatePage::handleMessageFromRoomCreationRequest);
    connect(worker, &Worker::create_item_dataReceived,&AuctionRoom.addItem, &addItem::handleRoomCreationStatus);
    connect(worker, &Worker::handleKickingMember,&AuctionRoom.joinerManage, &JoinerManage::showParticipents);
    connect(worker, &Worker::sendOff,this, &MainWindow::moveHome);
    connect(worker, &Worker::notifyInfo,this, &MainWindow::notifyInfo);
    connect(worker, &Worker::bid_dataReceived,&AuctionRoom, &AuctionRoom::notify);
    connect(worker, &Worker::updateAuctionItem,&AuctionRoom, &AuctionRoom::showItem);
    connect(worker, &Worker::updateAuctionItemByID,&AuctionRoom, &AuctionRoom::showItemByID);
    connect(worker, &Worker::callShowItems,&AuctionRoom.RoomOverview, &RoomOverview::showItems);
    connect(worker, &Worker::setNewTime,&AuctionRoom, &AuctionRoom::setNewTime);
    connect(worker, &Worker::stopTime,&AuctionRoom, &AuctionRoom::stopTime);
    connect(worker, &Worker::showAlertMessage,&AuctionRoom, &AuctionRoom::showAlertMessage);

    workerThread->start();








}

MainWindow::~MainWindow()
{
    ::close(MySingleton::instance().getValue());

    delete ui;
}

void MainWindow::on_btn_createtab_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_btn_historytab_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::notifyInfo(char *message){
    QMessageBox::information(this, tr("Failed"), message);
}

void MainWindow::moveHome(){

    ui->stackedWidget->setCurrentIndex(0);

    //_______________________
    //scroll area
    // Obtain the scroll area and its content widget
    QScrollArea* scrollArea = ui->scrollArea;
    QWidget* scrollContent = ui->scrollAreaWidgetContents;

    // Clear out any existing widgets in the scrollContent
    QLayout* existingLayout = scrollContent->layout();
    if (existingLayout) {
        // Delete all child widgets of the layout
        QLayoutItem* item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();  // Delete the widget
            delete item;            // Delete the layout item
        }
        delete existingLayout;  // Delete the old layout
    }

    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    int size = MySingleton::instance().auction_rooms.size();

    // show rooms
    std::list<AuctionRoomStruct> rooms = MySingleton::instance().auction_rooms;
    std::list<AuctionRoomStruct>::iterator it = rooms.begin();

    for (int groupIndex = 0; it != rooms.end() && groupIndex < size; ++it, ++groupIndex) {

        AuctionRoomStruct room = *it;
        QGroupBox* item = new QGroupBox();
        QHBoxLayout* groupBoxLayout = new QHBoxLayout(item);
        // Add an image to each group box
        QLabel* item_image = new QLabel;
        QPixmap pixmap(":/image/con-cho.jpeg");
        item_image ->setPixmap(pixmap.scaled(300,200, Qt::KeepAspectRatio));
        groupBoxLayout->addWidget(item_image );

        // Add text label to each group box
        QLabel* item_name = new QLabel(QString("ID %1").arg(room.id));
        groupBoxLayout->addWidget(item_name);
        QLabel* item_room = new QLabel(QString("Name: %1").arg(room.name));
        groupBoxLayout->addWidget(item_room);
        // Add button to join room
        QPushButton* item_btn_join = new QPushButton("Join");
        groupBoxLayout->addWidget(item_btn_join,0, Qt::AlignRight);

        connect(item_btn_join, &QPushButton::clicked, [this, room]() {

            MySingleton::instance().joinedRoom = room;
            send(MySingleton::instance().getValue(), "5", BUFF_SIZE-1, 0);
            JoinMess mess;
            mess.room_id = room.id;
            mess.user_id = MySingleton::instance().getAccount().id;
            send(MySingleton::instance().getValue(), &mess, sizeof(mess), 0);
        });
        scrollLayout->addWidget(item);
    }



    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
}
void MainWindow::moveCreateTab(){
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::moveHistoryTab(){
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::moveAuctionRoom(char *message){
    if (strcmp(message,"#OK")==0){
        ui->stackedWidget->setCurrentIndex(3);
        emit callShowItem();

    }else{
        QMessageBox::information(this, tr("Failed"), QString("Request to join room ID %1 failed").arg(MySingleton::instance().joinedRoom.id));
    }
}

void MainWindow::on_btn_logout_clicked()
{
    LogoutMess mess;
    mess.user_id = MySingleton::instance().getAccount().id;
    send(MySingleton::instance().getValue(), "3", BUFF_SIZE-1, 0);
    send(MySingleton::instance().getValue(), &mess, sizeof(mess), 0);
}
void MainWindow::moveSignupPage(){
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::moveLoginPage(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::handleLogout(char *message){
    ui->stackedWidget->setCurrentIndex(4);
}

