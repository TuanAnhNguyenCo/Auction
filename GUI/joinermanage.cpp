#include "joinermanage.h"
#include "ui_joinermanage.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QMessageBox>


JoinerManage::JoinerManage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JoinerManage)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->btn_back->setIcon(QIcon(":/image/icon_back.jpeg"));
    // Joiner list scroll area
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    for (int groupIndex = 0; groupIndex < 5; ++groupIndex) {
        QGroupBox* user= new QGroupBox("User" + QString::number(groupIndex + 1));
        QHBoxLayout* groupBoxLayout = new QHBoxLayout(user);
        // Add text label to each group box
        QLabel* user_name = new QLabel("Tuan Anh chó");
        groupBoxLayout->addWidget(user_name);
        // Add button to kick an user
        QPushButton* user_btn_kick = new QPushButton("Kick");
        groupBoxLayout->addWidget(user_btn_kick,0, Qt::AlignRight);
        connect(user_btn_kick, &QPushButton::clicked, this, &JoinerManage::kickUser);
        scrollLayout->addWidget(user);
    }
    QScrollArea* scrollArea = ui->scrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);

}

JoinerManage::~JoinerManage()
{
    delete ui;
}
void JoinerManage::kickUser(){
    QMessageBox::StandardButton reply;
    QMessageBox::question(this, "Confirm message", "Kick this user?",
        QMessageBox::Yes | QMessageBox::No);
}

void JoinerManage::on_btn_back_clicked()
{
    emit backClicked();
}

