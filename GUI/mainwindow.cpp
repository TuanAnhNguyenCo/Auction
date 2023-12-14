#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap logo("/Users/dieulinh/auction/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->stackedWidget->insertWidget(1, &CreatePage);
    ui->stackedWidget->insertWidget(2, &HistoryPage);
    ui->stackedWidget->insertWidget(3,&AuctionRoom);
    connect(&CreatePage, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&CreatePage, SIGNAL(HistoryClicked()), this, SLOT(moveHistoryTab()));
    connect(&HistoryPage, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&AuctionRoom, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&HistoryPage, SIGNAL(CreateClicked()), this, SLOT(moveCreateTab()));
    //_______________________
    //scroll area
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
        // Add button to join room
        QPushButton* item_btn_join = new QPushButton("Join");
        groupBoxLayout->addWidget(item_btn_join,0, Qt::AlignRight);
        connect(item_btn_join, &QPushButton::clicked, this, &MainWindow::moveAuctionRoom);
        groupBoxLayout->addWidget(item_room);
        scrollLayout->addWidget(item);
    }


    QScrollArea* scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);

}

MainWindow::~MainWindow()
{
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
void MainWindow::moveHome(){
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::moveCreateTab(){
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::moveHistoryTab(){
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::moveAuctionRoom(){
    ui->stackedWidget->setCurrentIndex(3);
}