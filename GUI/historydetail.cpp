#include "historydetail.h"
#include "ui_historydetail.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>

HistoryDetail::HistoryDetail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryDetail)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_3->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->btn_back->setIcon(QIcon(":/image/icon_back.jpeg"));
    // scroll area
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    for (int groupIndex = 0; groupIndex < 5; ++groupIndex) {
        QGroupBox* item= new QGroupBox;
        QHBoxLayout* groupBoxLayout = new QHBoxLayout(item);
        // Add an image to each group box
        QLabel* item_image = new QLabel;
        QPixmap pixmap(":/image/con-cho.jpeg");
        item_image ->setPixmap(pixmap.scaled(300,200, Qt::KeepAspectRatio));
        groupBoxLayout->addWidget(item_image );
        // Add text label to each group box
        QLabel* item_name = new QLabel("Con mèo");
        groupBoxLayout->addWidget(item_name);
        QLabel* item_price = new QLabel("300.000");
        groupBoxLayout->addWidget(item_price);
        QLabel* item_buyer = new QLabel("Tuan Anh");
        groupBoxLayout->addWidget(item_buyer);
        QLabel* item_status = new QLabel("Sold");
        groupBoxLayout->addWidget(item_status);
        scrollLayout->addWidget(item);
    }
    QScrollArea* scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
}

HistoryDetail::~HistoryDetail()
{
    delete ui;
}

void HistoryDetail::on_btn_back_clicked()
{
    emit backHistoryClicked();
}

