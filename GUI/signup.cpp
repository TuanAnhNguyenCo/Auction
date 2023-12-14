#include "signup.h"
#include "ui_signup.h"

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

