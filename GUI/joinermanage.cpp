#include "joinermanage.h"
#include "ui_joinermanage.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QMessageBox>
#include "config.h"

JoinerManage::JoinerManage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JoinerManage)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->btn_back->setIcon(QIcon(":/image/icon_back.jpeg"));


}

JoinerManage::~JoinerManage()
{
    delete ui;
}

void JoinerManage::showParticipents(){
    // Joiner list scroll area
    QWidget* scrollContent = ui->scrollAreaWidgetContents;
    QScrollArea* scrollArea = ui->scrollArea;
    // Clear out any existing widgets in the scrollContent
    QLayout* existingLayout = scrollContent->layout();
    if (existingLayout) {
        // Delete all child widgets of the layout
        QLayoutItem* item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();  // Delete the widget
            delete item;            // Delete the layout item
        }
        delete existingLayout;  // Delete the old layout
    }
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);

    for (std::list<Participents>::iterator it = MySingleton::instance().participents.begin(); it != MySingleton::instance().participents.end(); ++it) {

        // show only participents in joinedRoom.id
        if(it->room_id == MySingleton::instance().joinedRoom.id){

            for (std::list<Account>::iterator account = it->accounts.begin(); account != it->accounts.end(); ++account) {
                if (account->id == MySingleton::instance().joinedRoom.proprietor_id)
                    continue;
                QGroupBox* user= new QGroupBox("User" + QString::number(account->id));
                QHBoxLayout* groupBoxLayout = new QHBoxLayout(user);
                // Add text label to each group box
                QLabel* user_name = new QLabel(QString("<pre>Name: <b>%1</b>        Address: %2         Phone: %3</pre>").arg(account->username,account->address,account->phoneNumber));
                groupBoxLayout->addWidget(user_name);
                if (MySingleton::instance().getAccount().id == MySingleton::instance().joinedRoom.proprietor_id)
                {

                    // Add button to kick an user
                    QPushButton* user_btn_kick = new QPushButton("Kick");
                    user_btn_kick->setCursor(Qt::PointingHandCursor);
                    user_btn_kick->setStyleSheet("background-color: rgb(255, 100, 100);border-radius: 5px;border: 0.5px solid;");
                    user_btn_kick->setFixedWidth(80);
                    groupBoxLayout->addWidget(user_btn_kick,0, Qt::AlignRight);
                    connect(user_btn_kick, &QPushButton::clicked, [this, account]() {
                        KickMess kickMess;
                        kickMess.user_id = account->id;
                        kickMess.proprietor_id = MySingleton::instance().joinedRoom.proprietor_id;
                        kickMess.room_id = MySingleton::instance().joinedRoom.id;
                        send(MySingleton::instance().getValue(), "10", BUFF_SIZE-1, 0);
                        send(MySingleton::instance().getValue(), &kickMess, sizeof(kickMess), 0);
                    });
                }
                scrollLayout->addWidget(user);
            }
        }
    }
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollContent);
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

