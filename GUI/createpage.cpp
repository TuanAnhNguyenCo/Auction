#include "createpage.h"
#include "ui_createpage.h"
#include <QMessageBox>
#include "config.h"
CreatePage::CreatePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreatePage)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
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

    //create room
    send(MySingleton::instance().getValue(), "4", BUFF_SIZE-1, 0);
    AuctionRoomCreationMess roomMess;
    roomMess.proprietor_id = MySingleton::instance().getAccount().id;
    strcpy(roomMess.name,ui->lineEdit_name->text().toStdString().c_str());
    // Get the current time
    roomMess.created_at = std::time(nullptr);
    send(MySingleton::instance().getValue(), &roomMess, sizeof(roomMess), 0);
}
void CreatePage::handleMessageFromRoomCreationRequest(char *message){
    if (strcmp(message,"#OK")==0)
    {

        ui->lineEdit_name->setText("");
        QMessageBox::information(this, tr("CREATE A ROOM"), tr("Create an auction room successfully."));
        emit HomeClicked();
    }else{
        QMessageBox::information(this, tr("FAILED"), tr("Creating an auction room failed."));
    }

}


void CreatePage::on_btn_cancel_clicked()
{
    emit HomeClicked();
}
void CreatePage::on_btn_createtab_clicked(){

}


