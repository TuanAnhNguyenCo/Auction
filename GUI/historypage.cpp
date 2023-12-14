#include "historypage.h"
#include "ui_historypage.h"

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

void HistoryPage::on_btn_hometab_clicked()
{
     emit HomeClicked();
}

void HistoryPage::on_btn_createtab_clicked()
{
    emit CreateClicked();
}

