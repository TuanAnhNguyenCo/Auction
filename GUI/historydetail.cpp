#include "historydetail.h"
#include "ui_historydetail.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include "config.h"
HistoryDetail::HistoryDetail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryDetail)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_3->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->btn_back->setIcon(QIcon(":/image/icon_back.jpeg"));
}

HistoryDetail::~HistoryDetail()
{
    delete ui;
}


void HistoryDetail::showItemInfo(){
    MySingleton::instance().home->setCurrentIndex(6);
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

        if (goods.room_id == MySingleton::instance().viewingRoomHistory.id && goods.status == 0)
        {
            QGroupBox* item= new QGroupBox();
            QHBoxLayout* groupBoxLayout = new QHBoxLayout(item);
            // Add an image to each group box
            QLabel* item_image = new QLabel;
            QPixmap pixmap(goods.url);
            item_image ->setPixmap(pixmap.scaled(300,200, Qt::KeepAspectRatio));
            groupBoxLayout->addWidget(item_image );
            // Add text label to each group box
            QLabel* item_name = new QLabel(goods.name);
            groupBoxLayout->addWidget(item_name);
            QLabel* item_price = new QLabel("Latest price: "+QString::number(goods.current_price, 'f', 2));
            groupBoxLayout->addWidget(item_price);
            QLabel* item_buyer;
            for (std::list<Account>::iterator acc = MySingleton::instance().accountsOfRoom.begin(); acc != MySingleton::instance().accountsOfRoom.end(); ++acc){
                if(acc->id == goods.price_maker_id)
                {
                    item_buyer = new QLabel(QString("Purchaser: %1").arg(acc->username));
                    break;
                }
            }

            groupBoxLayout->addWidget(item_buyer);
            QLabel* item_status = new QLabel("Sold");
            groupBoxLayout->addWidget(item_status);
            scrollLayout->addWidget(item);
        }
    }

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
}

void HistoryDetail::on_btn_back_clicked()
{
    emit backHistoryClicked();
}

