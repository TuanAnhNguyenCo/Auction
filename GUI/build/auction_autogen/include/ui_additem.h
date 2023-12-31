/********************************************************************************
** Form generated from reading UI file 'additem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEM_H
#define UI_ADDITEM_H

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

class Ui_addItem
{
public:
    QStackedWidget *stackedWidget_2;
    QWidget *itemdetailPage;
    QLabel *label_image;
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
    QPushButton *btn_back;
    QLabel *label_1;
    QPushButton *btn_choosePic;
    QPushButton *btn_cancel;
    QPushButton *btn_save;

    void setupUi(QWidget *addItem)
    {
        if (addItem->objectName().isEmpty())
            addItem->setObjectName("addItem");
        addItem->resize(800, 600);
        stackedWidget_2 = new QStackedWidget(addItem);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 801, 601));
        itemdetailPage = new QWidget();
        itemdetailPage->setObjectName("itemdetailPage");
        label_image = new QLabel(itemdetailPage);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(520, 160, 221, 231));
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
        btn_back = new QPushButton(itemdetailPage);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(20, 80, 21, 31));
        label_1 = new QLabel(itemdetailPage);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(60, 70, 151, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(24);
        font.setBold(true);
        label_1->setFont(font);
        btn_choosePic = new QPushButton(itemdetailPage);
        btn_choosePic->setObjectName("btn_choosePic");
        btn_choosePic->setGeometry(QRect(570, 430, 141, 32));
        btn_cancel = new QPushButton(itemdetailPage);
        btn_cancel->setObjectName("btn_cancel");
        btn_cancel->setGeometry(QRect(460, 520, 91, 41));
        btn_save = new QPushButton(itemdetailPage);
        btn_save->setObjectName("btn_save");
        btn_save->setGeometry(QRect(330, 520, 91, 41));
        stackedWidget_2->addWidget(itemdetailPage);

        retranslateUi(addItem);

        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(addItem);
    } // setupUi

    void retranslateUi(QWidget *addItem)
    {
        addItem->setWindowTitle(QCoreApplication::translate("addItem", "Form", nullptr));
        label_image->setText(QString());
        label_logo_2->setText(QString());
        info_item->setTitle(QString());
        label_8->setText(QCoreApplication::translate("addItem", "Name:", nullptr));
        label_9->setText(QCoreApplication::translate("addItem", "Manufacturer:", nullptr));
        label_10->setText(QCoreApplication::translate("addItem", "Starting price:", nullptr));
        label_11->setText(QCoreApplication::translate("addItem", "BIN price:", nullptr));
        label_12->setText(QCoreApplication::translate("addItem", "Auction time:", nullptr));
        label_13->setText(QCoreApplication::translate("addItem", "Description:", nullptr));
        timeEdit_auctiontime->setDisplayFormat(QCoreApplication::translate("addItem", "HH:mm:ss", nullptr));
        btn_back->setText(QString());
        label_1->setText(QCoreApplication::translate("addItem", "Sell an item", nullptr));
        btn_choosePic->setText(QCoreApplication::translate("addItem", "Choose a picture", nullptr));
        btn_cancel->setText(QCoreApplication::translate("addItem", "Cancel", nullptr));
        btn_save->setText(QCoreApplication::translate("addItem", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addItem: public Ui_addItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEM_H
