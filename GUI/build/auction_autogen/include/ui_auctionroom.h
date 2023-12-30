/********************************************************************************
** Form generated from reading UI file 'auctionroom.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUCTIONROOM_H
#define UI_AUCTIONROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuctionRoom
{
public:
    QStackedWidget *stackedWidget_2;
    QWidget *itemdetailPage;
    QFrame *frame_bid;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_image;
    QPushButton *btn_overview;
    QFrame *line;
    QLabel *label_logo_2;
    QGroupBox *info_item;
    QLineEdit *lineEdit_name;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_manufacturer;
    QLineEdit *lineEdit_startingPrice;
    QLineEdit *lineEdit_binprice;
    QTimeEdit *timeEdit_auctiontime;
    QTextEdit *textEdit_description;
    QLabel *label_timer;
    QPushButton *btn_backHome;
    QPushButton *btn_bid;
    QLabel *label_nameRoom;
    QLabel *label_nameOwner;
    QPushButton *btn_bin;

    void setupUi(QWidget *AuctionRoom)
    {
        if (AuctionRoom->objectName().isEmpty())
            AuctionRoom->setObjectName("AuctionRoom");
        AuctionRoom->resize(800, 600);
        stackedWidget_2 = new QStackedWidget(AuctionRoom);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 801, 601));
        itemdetailPage = new QWidget();
        itemdetailPage->setObjectName("itemdetailPage");
        frame_bid = new QFrame(itemdetailPage);
        frame_bid->setObjectName("frame_bid");
        frame_bid->setGeometry(QRect(500, 450, 251, 41));
        frame_bid->setFrameShape(QFrame::StyledPanel);
        frame_bid->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_bid);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 10, 58, 16));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_5->setFont(font);
        label_4 = new QLabel(frame_bid);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 10, 131, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_4->setFont(font1);
        label_2 = new QLabel(itemdetailPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(560, 410, 58, 16));
        label_2->setFont(font);
        label_image = new QLabel(itemdetailPage);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(500, 160, 221, 231));
        btn_overview = new QPushButton(itemdetailPage);
        btn_overview->setObjectName("btn_overview");
        btn_overview->setGeometry(QRect(500, 90, 111, 41));
        line = new QFrame(itemdetailPage);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_logo_2 = new QLabel(itemdetailPage);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        info_item = new QGroupBox(itemdetailPage);
        info_item->setObjectName("info_item");
        info_item->setGeometry(QRect(20, 130, 431, 371));
        lineEdit_name = new QLineEdit(info_item);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(120, 40, 181, 21));
        lineEdit_name->setStyleSheet(QString::fromUtf8("border-radius: 10px; padding: 2px; border: 1px solid gray; "));
        label_8 = new QLabel(info_item);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(21, 41, 39, 16));
        label_9 = new QLabel(info_item);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 80, 91, 16));
        label_10 = new QLabel(info_item);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 110, 91, 16));
        label_11 = new QLabel(info_item);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 140, 58, 16));
        label_12 = new QLabel(info_item);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 170, 81, 16));
        label_13 = new QLabel(info_item);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 200, 71, 16));
        lineEdit_manufacturer = new QLineEdit(info_item);
        lineEdit_manufacturer->setObjectName("lineEdit_manufacturer");
        lineEdit_manufacturer->setGeometry(QRect(120, 80, 221, 21));
        lineEdit_manufacturer->setStyleSheet(QString::fromUtf8("border-radius: 10px; padding: 2px; border: 1px solid gray; \n"
""));
        lineEdit_startingPrice = new QLineEdit(info_item);
        lineEdit_startingPrice->setObjectName("lineEdit_startingPrice");
        lineEdit_startingPrice->setGeometry(QRect(120, 110, 111, 21));
        lineEdit_startingPrice->setStyleSheet(QString::fromUtf8("border-radius: 10px; padding: 2px; border: 1px solid gray; "));
        lineEdit_binprice = new QLineEdit(info_item);
        lineEdit_binprice->setObjectName("lineEdit_binprice");
        lineEdit_binprice->setGeometry(QRect(120, 140, 111, 21));
        lineEdit_binprice->setStyleSheet(QString::fromUtf8("border-radius: 10px; padding: 2px; border: 1px solid gray; "));
        timeEdit_auctiontime = new QTimeEdit(info_item);
        timeEdit_auctiontime->setObjectName("timeEdit_auctiontime");
        timeEdit_auctiontime->setGeometry(QRect(120, 170, 121, 22));
        timeEdit_auctiontime->setCurrentSection(QDateTimeEdit::HourSection);
        textEdit_description = new QTextEdit(info_item);
        textEdit_description->setObjectName("textEdit_description");
        textEdit_description->setGeometry(QRect(120, 210, 291, 141));
        textEdit_description->setStyleSheet(QString::fromUtf8("border-radius: 10px; padding: 2px; border: 1px solid gray; "));
        label_timer = new QLabel(itemdetailPage);
        label_timer->setObjectName("label_timer");
        label_timer->setGeometry(QRect(630, 410, 58, 16));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(false);
        label_timer->setFont(font2);
        btn_backHome = new QPushButton(itemdetailPage);
        btn_backHome->setObjectName("btn_backHome");
        btn_backHome->setGeometry(QRect(20, 80, 21, 31));
        btn_bid = new QPushButton(itemdetailPage);
        btn_bid->setObjectName("btn_bid");
        btn_bid->setGeometry(QRect(520, 500, 91, 41));
        label_nameRoom = new QLabel(itemdetailPage);
        label_nameRoom->setObjectName("label_nameRoom");
        label_nameRoom->setGeometry(QRect(60, 70, 151, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(24);
        font3.setBold(true);
        label_nameRoom->setFont(font3);
        label_nameOwner = new QLabel(itemdetailPage);
        label_nameOwner->setObjectName("label_nameOwner");
        label_nameOwner->setGeometry(QRect(170, 90, 71, 16));
        QFont font4;
        font4.setPointSize(15);
        font4.setItalic(true);
        label_nameOwner->setFont(font4);
        btn_bin = new QPushButton(itemdetailPage);
        btn_bin->setObjectName("btn_bin");
        btn_bin->setGeometry(QRect(650, 500, 91, 41));
        stackedWidget_2->addWidget(itemdetailPage);

        retranslateUi(AuctionRoom);

        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AuctionRoom);
    } // setupUi

    void retranslateUi(QWidget *AuctionRoom)
    {
        AuctionRoom->setWindowTitle(QCoreApplication::translate("AuctionRoom", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("AuctionRoom", "300", nullptr));
        label_4->setText(QCoreApplication::translate("AuctionRoom", "Newest bidding", nullptr));
        label_2->setText(QCoreApplication::translate("AuctionRoom", "Time:", nullptr));
        label_image->setText(QString());
        btn_overview->setText(QCoreApplication::translate("AuctionRoom", "Overview", nullptr));
        label_logo_2->setText(QString());
        info_item->setTitle(QString());
        label_8->setText(QCoreApplication::translate("AuctionRoom", "Name:", nullptr));
        label_9->setText(QCoreApplication::translate("AuctionRoom", "Manufacturer:", nullptr));
        label_10->setText(QCoreApplication::translate("AuctionRoom", "Starting price:", nullptr));
        label_11->setText(QCoreApplication::translate("AuctionRoom", "BIN price:", nullptr));
        label_12->setText(QCoreApplication::translate("AuctionRoom", "Auction time:", nullptr));
        label_13->setText(QCoreApplication::translate("AuctionRoom", "Description:", nullptr));
        timeEdit_auctiontime->setDisplayFormat(QCoreApplication::translate("AuctionRoom", "HH:mm:ss", nullptr));
        label_timer->setText(QCoreApplication::translate("AuctionRoom", "05:00", nullptr));
        btn_backHome->setText(QString());
        btn_bid->setText(QCoreApplication::translate("AuctionRoom", "Bid", nullptr));
        label_nameRoom->setText(QCoreApplication::translate("AuctionRoom", "Room 1", nullptr));
        label_nameOwner->setText(QCoreApplication::translate("AuctionRoom", "abc@xyz", nullptr));
        btn_bin->setText(QCoreApplication::translate("AuctionRoom", "BIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuctionRoom: public Ui_AuctionRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUCTIONROOM_H
