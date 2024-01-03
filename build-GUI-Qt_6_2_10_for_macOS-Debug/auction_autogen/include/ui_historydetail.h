/********************************************************************************
** Form generated from reading UI file 'historydetail.ui'
**
** Created by: Qt User Interface Compiler version 6.2.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYDETAIL_H
#define UI_HISTORYDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryDetail
{
public:
    QLabel *label_nameRoom;
    QFrame *line;
    QPushButton *btn_back;
    QLabel *label_logo_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *HistoryDetail)
    {
        if (HistoryDetail->objectName().isEmpty())
            HistoryDetail->setObjectName(QString::fromUtf8("HistoryDetail"));
        HistoryDetail->resize(800, 600);
        label_nameRoom = new QLabel(HistoryDetail);
        label_nameRoom->setObjectName(QString::fromUtf8("label_nameRoom"));
        label_nameRoom->setGeometry(QRect(60, 70, 151, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(24);
        font.setBold(true);
        label_nameRoom->setFont(font);
        line = new QFrame(HistoryDetail);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btn_back = new QPushButton(HistoryDetail);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(20, 80, 21, 31));
        btn_back->setCursor(QCursor(Qt::PointingHandCursor));
        label_logo_3 = new QLabel(HistoryDetail);
        label_logo_3->setObjectName(QString::fromUtf8("label_logo_3"));
        label_logo_3->setGeometry(QRect(10, 10, 61, 51));
        scrollArea = new QScrollArea(HistoryDetail);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(60, 120, 711, 461));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 459));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(HistoryDetail);

        QMetaObject::connectSlotsByName(HistoryDetail);
    } // setupUi

    void retranslateUi(QWidget *HistoryDetail)
    {
        HistoryDetail->setWindowTitle(QCoreApplication::translate("HistoryDetail", "Form", nullptr));
        label_nameRoom->setText(QCoreApplication::translate("HistoryDetail", "Room 1", nullptr));
        btn_back->setText(QString());
        label_logo_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HistoryDetail: public Ui_HistoryDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYDETAIL_H
