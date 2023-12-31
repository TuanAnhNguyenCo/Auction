#include "roomoverview.h"
#include "ui_roomoverview.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include "config.h"
#include <QMessageBox>
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

void RoomOverview::showItems()
{
    qDebug("Move to overview");
    if (MySingleton::instance().getAccount().id == MySingleton::instance().joinedRoom.proprietor_id )
    {
      ui->btn_add->setVisible(true);
    }else ui->btn_add->setVisible(false);
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    QScrollArea* scrollArea = ui->scrollArea;
    // Remove any existing layout from scrollContent
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
            // Add button to view item
            QPushButton* item_btn_view = new QPushButton("View");
            groupBoxLayout->addWidget(item_btn_view,0, Qt::AlignRight);
            connect(item_btn_view, &QPushButton::clicked, [this, goods]() {
                int id = goods.id;
                emit callItemByID(id);
                MySingleton::instance().auction_root_ui->setCurrentIndex(0);

            });
            if (MySingleton::instance().getAccount().id == MySingleton::instance().joinedRoom.proprietor_id && goods.status == 1)
            {
                // Add button to delete item
                QPushButton* item_btn_delete = new QPushButton("Delete");
                groupBoxLayout->addWidget(item_btn_delete,0, Qt::AlignRight);
                connect(item_btn_delete, &QPushButton::clicked, [this, goods]() {
                    DeleteItemMess itemMess;
                    itemMess.user_id = MySingleton::instance().getAccount().id;
                    itemMess.item_id = goods.id;
                    itemMess.room_id = MySingleton::instance().joinedRoom.id;
                    send(MySingleton::instance().getValue(), "9",BUFF_SIZE-1, 0);
                    send(MySingleton::instance().getValue(), &itemMess, sizeof(itemMess), 0);
                });
            }


            scrollLayout->addWidget(item);
        }
    }

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
}

void RoomOverview::on_btn_add_clicked()
{
    emit addItemClicked();
}
void RoomOverview::deleteItem()
{
    QMessageBox::StandardButton reply;
    QMessageBox::question(this, "Confirm message", "Delete this item?",
                          QMessageBox::Yes | QMessageBox::No);

}

void RoomOverview::on_pushButton_clicked()
{
    emit participantClicked();
}

