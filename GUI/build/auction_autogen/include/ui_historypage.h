/********************************************************************************
** Form generated from reading UI file 'historypage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYPAGE_H
#define UI_HISTORYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryPage
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QLabel *label_logo_2;
    QPushButton *btn_createtab;
    QPushButton *btn_hometab;
    QPushButton *btn_historytab;
    QFrame *line;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *HistoryPage)
    {
        if (HistoryPage->objectName().isEmpty())
            HistoryPage->setObjectName("HistoryPage");
        HistoryPage->resize(800, 600);
        stackedWidget = new QStackedWidget(HistoryPage);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 601));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_logo_2 = new QLabel(page_2);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        btn_createtab = new QPushButton(page_2);
        btn_createtab->setObjectName("btn_createtab");
        btn_createtab->setGeometry(QRect(230, 10, 141, 41));
        btn_hometab = new QPushButton(page_2);
        btn_hometab->setObjectName("btn_hometab");
        btn_hometab->setGeometry(QRect(100, 10, 111, 41));
        btn_historytab = new QPushButton(page_2);
        btn_historytab->setObjectName("btn_historytab");
        btn_historytab->setGeometry(QRect(390, 10, 111, 41));
        btn_historytab->setStyleSheet(QString::fromUtf8("border: none;\n"
"    padding: 0;\n"
"    background: none;\n"
" background-color: transparent; \n"
"    text-decoration: underline;\n"
"    margin: 0 10px;\n"
"\n"
"\n"
""));
        line = new QFrame(page_2);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, 70, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 90, 151, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(24);
        font.setBold(true);
        label->setFont(font);
        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(60, 140, 711, 441));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 439));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_2);

        retranslateUi(HistoryPage);

        QMetaObject::connectSlotsByName(HistoryPage);
    } // setupUi

    void retranslateUi(QWidget *HistoryPage)
    {
        HistoryPage->setWindowTitle(QCoreApplication::translate("HistoryPage", "Form", nullptr));
        label_logo_2->setText(QString());
        btn_createtab->setText(QCoreApplication::translate("HistoryPage", "Create auction room", nullptr));
        btn_hometab->setText(QCoreApplication::translate("HistoryPage", "Home ", nullptr));
        btn_historytab->setText(QCoreApplication::translate("HistoryPage", "Auction history", nullptr));
        label->setText(QCoreApplication::translate("HistoryPage", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryPage: public Ui_HistoryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYPAGE_H
