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
        QGroupBox* room= new QGroupBox;
        QHBoxLayout* groupBoxLayout = new QHBoxLayout(room);
        // Add an image to each group box
        QLabel* room_image = new QLabel;
        QPixmap pixmap(":/image/con-cho.jpeg");
        room_image ->setPixmap(pixmap.scaled(300,200, Qt::KeepAspectRatio));
        groupBoxLayout->addWidget(room_image);

        // Add text label to each group box
        QLabel* room_info = new QLabel("Room 1 - abc@xyz");
        groupBoxLayout->addWidget(room_info);
        // Add button to view room
        QPushButton* item_btn_view = new QPushButton("View");
        groupBoxLayout->addWidget(item_btn_view,0, Qt::AlignRight);
        connect(item_btn_view, &QPushButton::clicked, this, &HistoryPage::viewClicked);
        scrollLayout->addWidget(room);

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
void HistoryPage::viewClicked(){
    emit HistoryDetailClicked();
}
