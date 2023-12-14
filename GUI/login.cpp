#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

LogIn::LogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);
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
    QString userName = ui->lineEdit_username->text();
    QString passWord = ui->lineEdit_pass->text();
    if(userName == "chotuananh" && passWord == "tuananhcho"){
        QMessageBox::information(this,"Successful", "Login successfully");
        emit LoginOk();
    }
    else {
        QMessageBox::critical(this, tr("Fail"), tr("Login Failed"));
    }
}

