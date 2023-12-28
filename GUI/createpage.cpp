#include "createpage.h"
#include "ui_createpage.h"
#include <QMessageBox>
CreatePage::CreatePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreatePage)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->stackedWidget->insertWidget(1,&addItemobj);
    connect(&roomOverviewobj, SIGNAL(addItemClicked()), this, SLOT(addNewItem()));

}

CreatePage::~CreatePage()
{
    delete ui;
}

void CreatePage::on_btn_hometab_clicked()
{
    emit HomeClicked();
}

void CreatePage::on_btn_historytab_clicked()
{
    emit HistoryClicked();
}


void CreatePage::on_btn_save_clicked()
{
    QMessageBox::information(this, tr("CREATE A ROOM"), tr("Create an auction room successfully."));
    ui->stackedWidget->setCurrentIndex(1);
}
void CreatePage::addNewItem()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void CreatePage::on_btn_cancel_clicked()
{
    emit HomeClicked();
}


