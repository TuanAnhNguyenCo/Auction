#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "config.h"


LogIn::LogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
}

LogIn::~LogIn()
{
    delete ui;
}




void LogIn::on_btn_signupPage_clicked()
{
    emit SignupClicked();

}



void LogIn::on_btn_login_clicked()
{

    std::string userName= ui->lineEdit_username->text().toStdString();
    QString passWord = ui->lineEdit_pass->text();
    qInfo() <<  MySingleton::instance().getValue()  << " login\n";
    send(MySingleton::instance().getValue(),"1",BUFF_SIZE-1 , 0);



    if(userName == "cholinh" && passWord == "cholinh"){
        QMessageBox::information(this,"Successful", "Login successfully");
        emit LoginOk();
    }
    else {
        QMessageBox::critical(this, tr("Fail"), tr("Login Failed"));
    }
}
