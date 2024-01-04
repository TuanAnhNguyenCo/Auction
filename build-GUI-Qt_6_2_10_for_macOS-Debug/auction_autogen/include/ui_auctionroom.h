/********************************************************************************
** Form generated from reading UI file 'auctionroom.ui'
**
** Created by: Qt User Interface Compiler version 6.2.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUCTIONROOM_H
#define UI_AUCTIONROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuctionRoom
{
public:
    QStackedWidget *stackedWidget_2;
    QWidget *itemdetailPage;
    QFrame *frame_bid;
    QLabel *new_prices;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_image;
    QPushButton *btn_overview;
    QFrame *line;
    QLabel *label_logo_2;
    QGroupBox *info_item;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_nameItem;
    QLabel *label_manufacturerItem;
    QLabel *label_startPrice;
    QLabel *label_binPrice;
    QLabel *label_description;
    QPushButton *btn_backHome;
    QPushButton *btn_bid;
    QLabel *label_nameRoom;
    QLabel *label_nameOwner;
    QPushButton *btn_bin;
    QLabel *label_closed;
    QLabel *label_open;
    QLCDNumber *lcdNumber;
    QPushButton *startAuction;

    void setupUi(QWidget *AuctionRoom)
    {
        if (AuctionRoom->objectName().isEmpty())
            AuctionRoom->setObjectName(QString::fromUtf8("AuctionRoom"));
        AuctionRoom->resize(800, 600);
        stackedWidget_2 = new QStackedWidget(AuctionRoom);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 0, 801, 601));
        itemdetailPage = new QWidget();
        itemdetailPage->setObjectName(QString::fromUtf8("itemdetailPage"));
        frame_bid = new QFrame(itemdetailPage);
        frame_bid->setObjectName(QString::fromUtf8("frame_bid"));
        frame_bid->setGeometry(QRect(460, 450, 331, 41));
        frame_bid->setFrameShape(QFrame::StyledPanel);
        frame_bid->setFrameShadow(QFrame::Raised);
        new_prices = new QLabel(frame_bid);
        new_prices->setObjectName(QString::fromUtf8("new_prices"));
        new_prices->setGeometry(QRect(160, 10, 171, 20));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        new_prices->setFont(font);
        label_4 = new QLabel(frame_bid);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 10, 131, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_4->setFont(font1);
        label_2 = new QLabel(itemdetailPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 410, 58, 16));
        label_2->setFont(font);
        label_image = new QLabel(itemdetailPage);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(500, 160, 221, 231));
        btn_overview = new QPushButton(itemdetailPage);
        btn_overview->setObjectName(QString::fromUtf8("btn_overview"));
        btn_overview->setGeometry(QRect(500, 90, 111, 41));
        btn_overview->setCursor(QCursor(Qt::PointingHandCursor));
        btn_overview->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
" border-radius: 5px;\n"
"border: 1px solid;\n"
" }"));
        line = new QFrame(itemdetailPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_logo_2 = new QLabel(itemdetailPage);
        label_logo_2->setObjectName(QString::fromUtf8("label_logo_2"));
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        info_item = new QGroupBox(itemdetailPage);
        info_item->setObjectName(QString::fromUtf8("info_item"));
        info_item->setGeometry(QRect(20, 130, 431, 371));
        label_8 = new QLabel(info_item);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(21, 41, 39, 16));
        label_9 = new QLabel(info_item);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 80, 91, 16));
        label_10 = new QLabel(info_item);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 110, 91, 16));
        label_11 = new QLabel(info_item);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 140, 58, 16));
        label_13 = new QLabel(info_item);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 170, 71, 16));
        label_nameItem = new QLabel(info_item);
        label_nameItem->setObjectName(QString::fromUtf8("label_nameItem"));
        label_nameItem->setGeometry(QRect(120, 40, 301, 16));
        QFont font2;
        font2.setBold(true);
        label_nameItem->setFont(font2);
        label_manufacturerItem = new QLabel(info_item);
        label_manufacturerItem->setObjectName(QString::fromUtf8("label_manufacturerItem"));
        label_manufacturerItem->setGeometry(QRect(120, 80, 301, 16));
        label_manufacturerItem->setFont(font2);
        label_startPrice = new QLabel(info_item);
        label_startPrice->setObjectName(QString::fromUtf8("label_startPrice"));
        label_startPrice->setGeometry(QRect(120, 110, 301, 16));
        label_startPrice->setFont(font2);
        label_binPrice = new QLabel(info_item);
        label_binPrice->setObjectName(QString::fromUtf8("label_binPrice"));
        label_binPrice->setGeometry(QRect(120, 140, 301, 16));
        label_binPrice->setFont(font2);
        label_description = new QLabel(info_item);
        label_description->setObjectName(QString::fromUtf8("label_description"));
        label_description->setGeometry(QRect(110, 170, 251, 181));
        QFont font3;
        font3.setBold(false);
        font3.setItalic(true);
        font3.setKerning(true);
        label_description->setFont(font3);
        label_description->setCursor(QCursor(Qt::ArrowCursor));
        label_description->setStyleSheet(QString::fromUtf8("padding : 2px;"));
        label_description->setFrameShape(QFrame::Box);
        label_description->setFrameShadow(QFrame::Plain);
        label_description->setLineWidth(2);
        label_description->setScaledContents(false);
        label_description->setWordWrap(true);
        label_description->setMargin(0);
        btn_backHome = new QPushButton(itemdetailPage);
        btn_backHome->setObjectName(QString::fromUtf8("btn_backHome"));
        btn_backHome->setGeometry(QRect(20, 80, 21, 31));
        btn_backHome->setCursor(QCursor(Qt::PointingHandCursor));
        btn_bid = new QPushButton(itemdetailPage);
        btn_bid->setObjectName(QString::fromUtf8("btn_bid"));
        btn_bid->setGeometry(QRect(520, 500, 91, 41));
        btn_bid->setCursor(QCursor(Qt::PointingHandCursor));
        btn_bid->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(105, 183, 255, 176);\n"
" border-radius: 5px;\n"
"border: 1px solid;\n"
" }"));
        label_nameRoom = new QLabel(itemdetailPage);
        label_nameRoom->setObjectName(QString::fromUtf8("label_nameRoom"));
        label_nameRoom->setGeometry(QRect(60, 70, 151, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(24);
        font4.setBold(true);
        label_nameRoom->setFont(font4);
        label_nameOwner = new QLabel(itemdetailPage);
        label_nameOwner->setObjectName(QString::fromUtf8("label_nameOwner"));
        label_nameOwner->setGeometry(QRect(170, 90, 71, 16));
        QFont font5;
        font5.setPointSize(15);
        font5.setItalic(true);
        label_nameOwner->setFont(font5);
        btn_bin = new QPushButton(itemdetailPage);
        btn_bin->setObjectName(QString::fromUtf8("btn_bin"));
        btn_bin->setGeometry(QRect(650, 500, 91, 41));
        btn_bin->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(255, 100, 100);\n"
" border-radius: 5px;\n"
"border: 1px solid;\n"
" }"));
        label_closed = new QLabel(itemdetailPage);
        label_closed->setObjectName(QString::fromUtf8("label_closed"));
        label_closed->setGeometry(QRect(260, 80, 61, 31));
        label_closed->setFont(font3);
        label_closed->setStyleSheet(QString::fromUtf8("padding : 2px;\n"
"color:'red'"));
        label_closed->setFrameShape(QFrame::Box);
        label_closed->setFrameShadow(QFrame::Plain);
        label_closed->setLineWidth(2);
        label_closed->setScaledContents(false);
        label_closed->setWordWrap(true);
        label_closed->setMargin(0);
        label_open = new QLabel(itemdetailPage);
        label_open->setObjectName(QString::fromUtf8("label_open"));
        label_open->setGeometry(QRect(260, 80, 61, 31));
        label_open->setFont(font3);
        label_open->setStyleSheet(QString::fromUtf8("padding : 2px;\n"
"color:'green'"));
        label_open->setFrameShape(QFrame::Box);
        label_open->setFrameShadow(QFrame::Plain);
        label_open->setLineWidth(2);
        label_open->setScaledContents(false);
        label_open->setWordWrap(true);
        label_open->setMargin(0);
        lcdNumber = new QLCDNumber(itemdetailPage);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(620, 400, 81, 41));
        startAuction = new QPushButton(itemdetailPage);
        startAuction->setObjectName(QString::fromUtf8("startAuction"));
        startAuction->setGeometry(QRect(570, 500, 121, 41));
        startAuction->setCursor(QCursor(Qt::PointingHandCursor));
        startAuction->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(105, 183, 255, 176);\n"
" border-radius: 5px;\n"
"border: 1px solid;\n"
" }"));
        stackedWidget_2->addWidget(itemdetailPage);

        retranslateUi(AuctionRoom);

        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AuctionRoom);
    } // setupUi

    void retranslateUi(QWidget *AuctionRoom)
    {
        AuctionRoom->setWindowTitle(QCoreApplication::translate("AuctionRoom", "Form", nullptr));
        new_prices->setText(QCoreApplication::translate("AuctionRoom", "300", nullptr));
        label_4->setText(QCoreApplication::translate("AuctionRoom", "Newest bidding:", nullptr));
        label_2->setText(QCoreApplication::translate("AuctionRoom", "Time:", nullptr));
        label_image->setText(QString());
        btn_overview->setText(QCoreApplication::translate("AuctionRoom", "Overview", nullptr));
        label_logo_2->setText(QString());
        info_item->setTitle(QString());
        label_8->setText(QCoreApplication::translate("AuctionRoom", "Name:", nullptr));
        label_9->setText(QCoreApplication::translate("AuctionRoom", "Manufacturer:", nullptr));
        label_10->setText(QCoreApplication::translate("AuctionRoom", "Starting price:", nullptr));
        label_11->setText(QCoreApplication::translate("AuctionRoom", "BIN price:", nullptr));
        label_13->setText(QCoreApplication::translate("AuctionRoom", "Description:", nullptr));
        label_nameItem->setText(QCoreApplication::translate("AuctionRoom", "Con m\303\250o", nullptr));
        label_manufacturerItem->setText(QCoreApplication::translate("AuctionRoom", "N/A", nullptr));
        label_startPrice->setText(QCoreApplication::translate("AuctionRoom", "100.000", nullptr));
        label_binPrice->setText(QCoreApplication::translate("AuctionRoom", "400.000", nullptr));
        label_description->setText(QCoreApplication::translate("AuctionRoom", "Tr\303\252n b\303\240n l\303\240 m\341\273\231t ch\303\272 m\303\250o xinh x\341\272\257n, \304\221en tr\341\272\257ng nh\306\260 b\341\273\251c tranh h\341\273\215a v\341\273\233i b\341\273\231 l\303\264ng m\341\273\201m m\341\272\241i v\303\240 m\341\272\257t to tr\303\262n nh\303\254n \304\221\341\272\247y t\303\262 m\303\262. B\341\273\231 l\303\264ng m\303\240u \304\221en huy\341\273\201n b\303\255 xen k\341\272\275 v\341\273\233i nh\341\273\257ng v\341\272\241ch tr\341\272\257ng tinh t\341\272\277, t\341\272\241o n\303\252n m\341\273\231t v\341\272\273 \304\221\341\272\271p n\341\273\225i b\341\272\255t v\303\240 \304\221\341\273\231c \304\221\303\241o.\n"
"\n"
"Ch\303\272 m\303\250o n\303\240y kh\303\264ng ch\341\273\211 l\303\240 m\341\273\231t \304\221\341\273\221i t\306\260\341\273\243ng d\341\273\205 th\306\260\306\241ng m\303\240 c\303\262n tr\341\273\237 th\303\240nh m\341\273\231t \304\221\341\273\221i t\303\241c tuy\341\273\207t v\341\273\235i trong vi\341\273\207c qu\341\272\243ng c\303\241o v\303"
                        "\240 b\303\241n h\303\240ng. Khi \304\221\306\260\341\273\243c \304\221\341\272\267t tr\303\252n c\303\241c s\341\272\243n ph\341\272\251m, h\303\254nh \341\272\243nh c\341\273\247a ch\303\272 m\303\250o t\341\273\217a ra s\341\273\261 tho\341\272\243i m\303\241i v\303\240 an ninh, t\341\272\241o n\303\252n m\341\273\231t c\341\272\243m gi\303\241c th\303\242n thi\341\273\207n v\303\240 g\341\272\247n g\305\251i.\n"
"\n"
"Kh\341\272\243 n\304\203ng m\303\264 ph\341\273\217ng \304\221\341\273\231ng c\341\273\247a ch\303\272 m\303\250o kh\303\264ng gi\341\273\233i h\341\272\241n. T\341\273\253 c\341\273\255 \304\221\341\273\231ng nh\341\273\217 nh\306\260 l\303\240m \304\221\341\272\247u v\303\272t l\303\252n hay vu\341\273\221t \304\221u\303\264i, \304\221\341\272\277n nh\341\273\257ng t\306\260 th\341\272\277 \304\221\303\241ng y\303\252u nh\306\260 quay m\303\254nh hay nh\341\272\243y l\303\252n kh\341\273\217i m\341\273\231t chi\341\272\277c h\341\273\231p nh\341\273\217, ch\303\272 m\303\250o mang l\341\272"
                        "\241i kh\303\264ng kh\303\255 vui v\341\272\273 v\303\240 d\341\273\205 ch\341\273\213u. Nh\341\273\257ng h\303\254nh \341\272\243nh n\303\240y kh\303\264ng ch\341\273\211 t\341\272\241o ra s\341\273\261 k\341\272\277t n\341\273\221i v\341\273\233i \304\221\341\273\221i t\306\260\341\273\243ng m\303\240 c\303\262n k\303\255ch th\303\255ch s\341\273\261 quan t\303\242m t\341\273\253 ph\303\255a kh\303\241ch h\303\240ng.", nullptr));
        btn_backHome->setText(QString());
        btn_bid->setText(QCoreApplication::translate("AuctionRoom", "Bid", nullptr));
        label_nameRoom->setText(QCoreApplication::translate("AuctionRoom", "Room 1", nullptr));
        label_nameOwner->setText(QCoreApplication::translate("AuctionRoom", "abc@xyz", nullptr));
        btn_bin->setText(QCoreApplication::translate("AuctionRoom", "BIN", nullptr));
        label_closed->setText(QCoreApplication::translate("AuctionRoom", "CLOSED", nullptr));
        label_open->setText(QCoreApplication::translate("AuctionRoom", "OPEN", nullptr));
        startAuction->setText(QCoreApplication::translate("AuctionRoom", "Start bidding", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuctionRoom: public Ui_AuctionRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUCTIONROOM_H
