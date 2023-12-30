#include "roomoverview.h"
#include "ui_roomoverview.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include "config.h"

RoomOverview::RoomOverview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RoomOverview)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->btn_backAuctionroom->setIcon(QIcon(":/image/icon_back.jpeg"));
    // scroll area

}

RoomOverview::~RoomOverview()
{
    delete ui;
}

void RoomOverview::on_btn_backAuctionroom_clicked()
{
    emit backtoRoomClicked();
}

void RoomOverview::showItems()
{
    qDebug("Move to overview");
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    // Remove any existing layout from scrollContent
    QLayout* existingLayout = scrollContent->layout();
    if (existingLayout) {
        delete existingLayout;
    }
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    int size = MySingleton::instance().items.size();
    // show rooms
    std::list<Item> items = MySingleton::instance().items;
    std::list<Item>::iterator it = items.begin();
    for (int groupIndex = 0; it != items.end() && groupIndex < size; ++it, ++groupIndex) {
        Item goods = *it;
        if (goods.room_id == MySingleton::instance().joinedRoom.id)
        {
            QGroupBox* item = new QGroupBox();
            QHBoxLayout* groupBoxLayout = new QHBoxLayout(item);
            // Add an image to each group box
            QLabel* item_image = new QLabel;
            QPixmap pixmap(":/image/con-cho.jpeg");
            item_image ->setPixmap(pixmap.scaled(300,200, Qt::KeepAspectRatio));
            groupBoxLayout->addWidget(item_image );
            // Add text label to each group box
            // Add text label to each group box
            QLabel* item_name = new QLabel(QString("Name: %1").arg(goods.name));
            groupBoxLayout->addWidget(item_name);
            QLabel* item_status;
            if (goods.status == 1)
            {
                item_status = new QLabel("Waiting for auction");
            }else  item_status = new QLabel("Sold");

            groupBoxLayout->addWidget(item_status);
            // Add button to join room
            QPushButton* item_btn_view = new QPushButton("View");
            groupBoxLayout->addWidget(item_btn_view,0, Qt::AlignRight);
            connect(item_btn_view, &QPushButton::clicked, this, &RoomOverview::on_btn_backAuctionroom_clicked);
            scrollLayout->addWidget(item);
        }
    }
    QScrollArea* scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
}

void RoomOverview::on_btn_add_clicked()
{
    emit addItemClicked();
    qDebug(":)");
}

