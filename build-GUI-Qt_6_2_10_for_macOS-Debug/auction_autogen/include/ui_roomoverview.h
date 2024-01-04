/********************************************************************************
** Form generated from reading UI file 'roomoverview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMOVERVIEW_H
#define UI_ROOMOVERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomOverview
{
public:
    QLabel *label_logo_2;
    QLabel *label_nameRoom;
    QLabel *label_logo_3;
    QPushButton *btn_backAuctionroom;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btn_add;
    QPushButton *pushButton;

    void setupUi(QWidget *RoomOverview)
    {
        if (RoomOverview->objectName().isEmpty())
            RoomOverview->setObjectName(QString::fromUtf8("RoomOverview"));
        RoomOverview->resize(800, 600);
        label_logo_2 = new QLabel(RoomOverview);
        label_logo_2->setObjectName(QString::fromUtf8("label_logo_2"));
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        label_nameRoom = new QLabel(RoomOverview);
        label_nameRoom->setObjectName(QString::fromUtf8("label_nameRoom"));
        label_nameRoom->setGeometry(QRect(60, 70, 151, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(24);
        font.setBold(true);
        label_nameRoom->setFont(font);
        label_logo_3 = new QLabel(RoomOverview);
        label_logo_3->setObjectName(QString::fromUtf8("label_logo_3"));
        label_logo_3->setGeometry(QRect(10, 10, 61, 51));
        btn_backAuctionroom = new QPushButton(RoomOverview);
        btn_backAuctionroom->setObjectName(QString::fromUtf8("btn_backAuctionroom"));
        btn_backAuctionroom->setGeometry(QRect(20, 80, 21, 31));
        btn_backAuctionroom->setCursor(QCursor(Qt::PointingHandCursor));
        line = new QFrame(RoomOverview);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setStyleSheet(QString::fromUtf8("color:  rgba(105, 183, 255, 176);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(RoomOverview);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(60, 120, 711, 461));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 459));
        scrollArea->setWidget(scrollAreaWidgetContents);
        btn_add = new QPushButton(RoomOverview);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(670, 80, 101, 21));
        btn_add->setCursor(QCursor(Qt::PointingHandCursor));
        btn_add->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" border-radius: 5px;\n"
"	background-color: rgb(255, 255, 255);\n"
"border: 0.5px solid;\n"
" }"));
        btn_add->setAutoDefault(false);
        btn_add->setFlat(false);
        pushButton = new QPushButton(RoomOverview);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 80, 101, 21));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
" border-radius: 5px;\n"
"border: 0.5px solid;\n"
" }"));

        retranslateUi(RoomOverview);

        btn_add->setDefault(false);


        QMetaObject::connectSlotsByName(RoomOverview);
    } // setupUi

    void retranslateUi(QWidget *RoomOverview)
    {
        RoomOverview->setWindowTitle(QCoreApplication::translate("RoomOverview", "Form", nullptr));
        label_logo_2->setText(QString());
        label_nameRoom->setText(QCoreApplication::translate("RoomOverview", "Room 1", nullptr));
        label_logo_3->setText(QString());
        btn_backAuctionroom->setText(QString());
        btn_add->setText(QCoreApplication::translate("RoomOverview", "Add an item", nullptr));
        pushButton->setText(QCoreApplication::translate("RoomOverview", "Participants", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomOverview: public Ui_RoomOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMOVERVIEW_H
