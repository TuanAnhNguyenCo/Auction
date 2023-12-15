#include "signup.h"
#include "ui_signup.h"
#include "config.h"
#include "account.h"

SignUp::SignUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_btn_loginPage_clicked()
{
    emit LoginClicked();
}

void SignUp::demoupdate(){
    qDebug() << "Dữ liệu đã được cập nhật";
}


void SignUp::on_btn_signup_clicked()
{
    char ResponedMessage[BUFF_SIZE];
    std::string userName= ui->lineEdit_username->text().toStdString();
    std::string password= ui->lineEdit_pass->text().toStdString();
    std::string address= ui->lineEdit_address->text().toStdString();
    std::string phone_number= ui->lineEdit_phonenum->text().toStdString();
    send(MySingleton::instance().getValue(),"1",BUFF_SIZE-1 , 0);
    SignupMess accountMess;
    strcpy(accountMess.address, address.c_str());
    strcpy(accountMess.password, password.c_str());
    strcpy(accountMess.phoneNumber, phone_number.c_str());
    strcpy(accountMess.username, userName.c_str());
    send(MySingleton::instance().getValue(), &accountMess, sizeof(accountMess), 0);
    recv(MySingleton::instance().getValue(), &ResponedMessage, BUFF_SIZE-1, 0);
    qInfo() << ResponedMessage  << " signout";
    if (strcmp(ResponedMessage,"#OK") == 0)
    {

        ui->lineEdit_username->setText("");
        ui->lineEdit_pass->setText("");
        ui->lineEdit_address->setText("");
        ui->lineEdit_phonenum->setText("");
    }else{

    }
}

