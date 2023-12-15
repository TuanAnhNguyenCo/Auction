#include "historypage.h"
#include "ui_historypage.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
HistoryPage::HistoryPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryPage)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    for (int groupIndex = 0; groupIndex < 5; ++groupIndex) {
        QGroupBox* item= new QGroupBox("Item" + QString::number(groupIndex + 1));
        QHBoxLayout* groupBoxLayout = new QHBoxLayout(item);
        // Add an image to each group box
        QLabel* item_image = new QLabel;
        QPixmap pixmap("/Users/dieulinh/auction/con-cho.jpeg");
        item_image ->setPixmap(pixmap.scaled(300,200, Qt::KeepAspectRatio));
        groupBoxLayout->addWidget(item_image );

        // Add text label to each group box
        QLabel* item_name = new QLabel("Con mèo");
                            groupBoxLayout->addWidget(item_name);
        QLabel* item_room = new QLabel("Room 1 - abc@xyz");
        QLabel* item_info = new QLabel("Buyer: baa@zzz -  Price: 300");
        QLabel* date = new QLabel("Date: 10:30 20/11/2023");
        groupBoxLayout->addWidget(item_room);
        groupBoxLayout->addWidget(date);
        scrollLayout->addWidget(item);
}
    QScrollArea* scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
}

HistoryPage::~HistoryPage()
{
    delete ui;
}

void HistoryPage::on_btn_hometab_clicked()
{
     emit HomeClicked();
}

void HistoryPage::on_btn_createtab_clicked()
{
    emit CreateClicked();
}

