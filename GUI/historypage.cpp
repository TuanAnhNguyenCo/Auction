#include "historypage.h"
#include "ui_historypage.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include "config.h"
HistoryPage::HistoryPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryPage)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
}

HistoryPage::~HistoryPage()
{
    delete ui;
}


void HistoryPage::moveHistoryPage(){
    qDebug("Hello");
    GetRoomHistoryMess user;
    user.user_id = MySingleton::instance().getAccount().id;
    send(MySingleton::instance().getValue(), "25", BUFF_SIZE-1, 0);
    send(MySingleton::instance().getValue(), &user, sizeof(GetRoomHistoryMess), 0);

}
void HistoryPage::showJoinedRooms(){

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

        for (std::list<AuctionRoomStruct>::iterator it = MySingleton::instance().joinedRoomList.begin(); it != MySingleton::instance().joinedRoomList.end(); ++it){
            AuctionRoomStruct room = *it;
            // Define a regular expression pattern

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
            QPushButton* item_btn_join = new QPushButton("View");
            groupBoxLayout->addWidget(item_btn_join,0, Qt::AlignRight);

            connect(item_btn_join, &QPushButton::clicked, [this, room]() {
                MySingleton::instance().viewingRoomHistory = room;
                GetParticipateMess rm;
                rm.room_id = room.id;
                send(MySingleton::instance().getValue(), "24", BUFF_SIZE-1, 0);
                send(MySingleton::instance().getValue(), &rm, sizeof(GetParticipateMess), 0);
            });
            scrollLayout->addWidget(item);

        }
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(scrollContent);
}

void HistoryPage::on_btn_hometab_clicked()
{
    emit HomeClicked();
}

void HistoryPage::on_btn_createtab_clicked()
{
    emit CreateClicked();
}
void HistoryPage::viewClicked(){
    emit HistoryDetailClicked();
}
