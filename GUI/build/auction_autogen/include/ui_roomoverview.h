/********************************************************************************
** Form generated from reading UI file 'roomoverview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
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
            RoomOverview->setObjectName("RoomOverview");
        RoomOverview->resize(800, 600);
        label_logo_2 = new QLabel(RoomOverview);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        label_nameRoom = new QLabel(RoomOverview);
        label_nameRoom->setObjectName("label_nameRoom");
        label_nameRoom->setGeometry(QRect(60, 70, 151, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(24);
        font.setBold(true);
        label_nameRoom->setFont(font);
        label_logo_3 = new QLabel(RoomOverview);
        label_logo_3->setObjectName("label_logo_3");
        label_logo_3->setGeometry(QRect(10, 10, 61, 51));
        btn_backAuctionroom = new QPushButton(RoomOverview);
        btn_backAuctionroom->setObjectName("btn_backAuctionroom");
        btn_backAuctionroom->setGeometry(QRect(20, 80, 21, 31));
        line = new QFrame(RoomOverview);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(RoomOverview);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(60, 120, 711, 461));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 459));
        scrollArea->setWidget(scrollAreaWidgetContents);
        btn_add = new QPushButton(RoomOverview);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(670, 80, 101, 31));
        pushButton = new QPushButton(RoomOverview);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 80, 100, 32));

        retranslateUi(RoomOverview);

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
