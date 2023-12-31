/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_logo_2;
    QPushButton *btn_historytab;
    QPushButton *btn_createtab;
    QPushButton *btn_hometab;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QPushButton *btn_search;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *time_from;
    QLabel *label_2;
    QDateTimeEdit *time_to;
    QPushButton *btn_logout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 601));
        page = new QWidget();
        page->setObjectName("page");
        label_logo_2 = new QLabel(page);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        btn_historytab = new QPushButton(page);
        btn_historytab->setObjectName("btn_historytab");
        btn_historytab->setGeometry(QRect(390, 10, 111, 41));
        btn_createtab = new QPushButton(page);
        btn_createtab->setObjectName("btn_createtab");
        btn_createtab->setGeometry(QRect(230, 10, 141, 41));
        btn_hometab = new QPushButton(page);
        btn_hometab->setObjectName("btn_hometab");
        btn_hometab->setGeometry(QRect(100, 10, 111, 41));
        btn_hometab->setStyleSheet(QString::fromUtf8("border: none;\n"
"    padding: 0;\n"
"    background: none;\n"
" background-color: transparent; \n"
"    text-decoration: underline;\n"
"    margin: 0 10px;\n"
"\n"
""));
        line = new QFrame(page);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(100, 160, 641, 431));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 639, 429));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 70, 641, 80));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 10, 481, 31));
        btn_search = new QPushButton(groupBox);
        btn_search->setObjectName("btn_search");
        btn_search->setGeometry(QRect(530, 30, 101, 31));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(110, 50, 353, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        time_from = new QDateTimeEdit(layoutWidget);
        time_from->setObjectName("time_from");

        horizontalLayout->addWidget(time_from);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(20);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        time_to = new QDateTimeEdit(layoutWidget);
        time_to->setObjectName("time_to");

        horizontalLayout->addWidget(time_to);

        btn_logout = new QPushButton(page);
        btn_logout->setObjectName("btn_logout");
        btn_logout->setGeometry(QRect(720, 20, 81, 32));
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_logo_2->setText(QString());
        btn_historytab->setText(QCoreApplication::translate("MainWindow", "Auction history", nullptr));
        btn_createtab->setText(QCoreApplication::translate("MainWindow", "Create auction room", nullptr));
        btn_hometab->setText(QCoreApplication::translate("MainWindow", "Home ", nullptr));
        groupBox->setTitle(QString());
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search ...", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Time slot: ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btn_logout->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
