#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "config.h"
#include "account.h"
#include <QtDebug>


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

void LogIn::update_sign_in(char *message){
    qDebug() << message;
    if (strcmp(message,"#OK") == 0)
    {
        // thong bao success, navigate to home
        QMessageBox::information(this, tr("Success"), tr("Sign in successfully "));
        LogIn::LoginOk();
    }
    if (strcmp(message,"#FAIL") == 0){

        QMessageBox::information(this, tr("Failed"), "Your username or password is incorrect ");
    }
    if (strcmp(message,"#ONLINING") == 0){

        QMessageBox::information(this, tr("Failed"), "Your account have been working on another device");
    }
    ui->lineEdit_pass->setText("");
}



void LogIn::on_btn_login_clicked()
{

    std::string userName= ui->lineEdit_username->text().toStdString();
    std::string password = ui->lineEdit_pass->text().toStdString();
    LoginMess accountMess;

    strcpy(accountMess.password, password.c_str());
    strcpy(accountMess.username, userName.c_str());
    send(MySingleton::instance().getValue(),"2",BUFF_SIZE-1 , 0);
    send(MySingleton::instance().getValue(), &accountMess, sizeof(accountMess), 0);



    // if(userName == "cholinh" && passWord == "cholinh"){
    //     QMessageBox::information(this,"Successful", "Login successfully");
    //     emit LoginOk();
    // }
    // else {
    //     QMessageBox::critical(this, tr("Fail"), tr("Login Failed"));
    // }
}
