#include "roomoverview.h"
#include "ui_roomoverview.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>

RoomOverview::RoomOverview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RoomOverview)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->btn_backAuctionroom->setIcon(QIcon(":/image/icon_back.jpeg"));
    // Item list scroll area
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    for (int groupIndex = 0; groupIndex < 5; ++groupIndex) {
        QGroupBox* item= new QGroupBox("Item" + QString::number(groupIndex + 1));
        QHBoxLayout* groupBoxLayout = new QHBoxLayout(item);
        // Add an image to each group box
        QLabel* item_image = new QLabel;
        QPixmap pixmap(":/image/con-cho.jpeg");
        item_image ->setPixmap(pixmap.scaled(300,200, Qt::KeepAspectRatio));
        groupBoxLayout->addWidget(item_image );
        // Add text label to each group box
        QLabel* item_name = new QLabel("Con mèo");
        groupBoxLayout->addWidget(item_name);
        QLabel* item_status = new QLabel("Sold");
        groupBoxLayout->addWidget(item_status);
        // Add button to join room
        QPushButton* item_btn_view = new QPushButton("View");
        groupBoxLayout->addWidget(item_btn_view,0, Qt::AlignRight);
        connect(item_btn_view, &QPushButton::clicked, this, &RoomOverview::on_btn_backAuctionroom_clicked);
        QPushButton* item_btn_delete = new QPushButton("Delete");
        groupBoxLayout->addWidget(item_btn_delete,0, Qt::AlignRight);
        scrollLayout->addWidget(item);
    }
    QScrollArea* scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);

}

RoomOverview::~RoomOverview()
{
    delete ui;
}

void RoomOverview::on_btn_backAuctionroom_clicked()
{
    emit backtoRoomClicked();
}

void RoomOverview::on_btn_add_clicked()
{
    emit addItemClicked();
    qDebug(":)");
}


void RoomOverview::on_pushButton_clicked()
{
    emit participantClicked();
}

