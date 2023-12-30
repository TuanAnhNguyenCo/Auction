/********************************************************************************
** Form generated from reading UI file 'joinermanage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINERMANAGE_H
#define UI_JOINERMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JoinerManage
{
public:
    QLabel *label_nameRoom;
    QLabel *label_logo_2;
    QLabel *label_logo_3;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btn_back;

    void setupUi(QWidget *JoinerManage)
    {
        if (JoinerManage->objectName().isEmpty())
            JoinerManage->setObjectName("JoinerManage");
        JoinerManage->resize(800, 600);
        label_nameRoom = new QLabel(JoinerManage);
        label_nameRoom->setObjectName("label_nameRoom");
        label_nameRoom->setGeometry(QRect(60, 70, 151, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(24);
        font.setBold(true);
        label_nameRoom->setFont(font);
        label_logo_2 = new QLabel(JoinerManage);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        label_logo_3 = new QLabel(JoinerManage);
        label_logo_3->setObjectName("label_logo_3");
        label_logo_3->setGeometry(QRect(10, 10, 61, 51));
        line = new QFrame(JoinerManage);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(JoinerManage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(60, 120, 711, 461));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 459));
        scrollArea->setWidget(scrollAreaWidgetContents);
        btn_back = new QPushButton(JoinerManage);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(20, 80, 21, 31));

        retranslateUi(JoinerManage);

        QMetaObject::connectSlotsByName(JoinerManage);
    } // setupUi

    void retranslateUi(QWidget *JoinerManage)
    {
        JoinerManage->setWindowTitle(QCoreApplication::translate("JoinerManage", "Form", nullptr));
        label_nameRoom->setText(QCoreApplication::translate("JoinerManage", "Room 1", nullptr));
        label_logo_2->setText(QString());
        label_logo_3->setText(QString());
        btn_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JoinerManage: public Ui_JoinerManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINERMANAGE_H
