/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.10
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
    QTextEdit *search;
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 801, 601));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_logo_2 = new QLabel(page);
        label_logo_2->setObjectName(QString::fromUtf8("label_logo_2"));
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        btn_historytab = new QPushButton(page);
        btn_historytab->setObjectName(QString::fromUtf8("btn_historytab"));
        btn_historytab->setGeometry(QRect(410, 0, 151, 61));
        btn_historytab->setCursor(QCursor(Qt::PointingHandCursor));
        btn_historytab->setStyleSheet(QString::fromUtf8("QPushButton{border: none;\n"
"    padding: 0;\n"
"    background: none;\n"
"  font-weight: bold;\n"
"font-size :15px;\n"
"   background-color: transparent; \n"
"    margin: 0 10px;\n"
"\n"
" }\n"
"QPushButton:hover {\n"
" background-color: rgb(37, 153, 255);\n"
" color: white;\n"
" }\n"
"\n"
""));
        btn_createtab = new QPushButton(page);
        btn_createtab->setObjectName(QString::fromUtf8("btn_createtab"));
        btn_createtab->setGeometry(QRect(210, 0, 221, 61));
        btn_createtab->setCursor(QCursor(Qt::PointingHandCursor));
        btn_createtab->setMouseTracking(true);
        btn_createtab->setStyleSheet(QString::fromUtf8("QPushButton{border: none;\n"
"    padding: 0;\n"
"    background: none;\n"
"  font-weight: bold;\n"
"font-size :15px;\n"
"   background-color: transparent; \n"
"    margin: 0 10px;\n"
" }\n"
"QPushButton:hover {\n"
" background-color: rgb(37, 153, 255);\n"
" color: white;\n"
" }\n"
"\n"
""));
        btn_hometab = new QPushButton(page);
        btn_hometab->setObjectName(QString::fromUtf8("btn_hometab"));
        btn_hometab->setGeometry(QRect(100, 0, 131, 61));
        btn_hometab->setCursor(QCursor(Qt::PointingHandCursor));
        btn_hometab->setStyleSheet(QString::fromUtf8("QPushButton{border: none;\n"
"    padding: 0;\n"
"    background: none;\n"
"  font-weight: bold;\n"
"font-size :15px;\n"
"   background-color: transparent; \n"
"    margin: 0 10px;\n"
" background-color: ;\n"
"	background-color: rgba(105, 183, 255, 176);\n"
"\n"
" }\n"
"QPushButton:hover {\n"
" background-color: rgb(37, 153, 255);\n"
" color: white;\n"
" }\n"
"QPushButton:focus {\n"
" background-color: rgb(37, 153, 255);\n"
" color: white;\n"
" }\n"
"\n"
""));
        line = new QFrame(page);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(100, 160, 641, 431));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 639, 429));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 70, 641, 80));
        search = new QTextEdit(groupBox);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(40, 10, 481, 31));
        search->setStyleSheet(QString::fromUtf8("border: 0.5px solid  rgba(105, 183, 255, 176);\n"
"border-radius: 5px;"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 50, 353, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        time_from = new QDateTimeEdit(layoutWidget);
        time_from->setObjectName(QString::fromUtf8("time_from"));

        horizontalLayout->addWidget(time_from);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(20);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        time_to = new QDateTimeEdit(layoutWidget);
        time_to->setObjectName(QString::fromUtf8("time_to"));

        horizontalLayout->addWidget(time_to);

        btn_logout = new QPushButton(page);
        btn_logout->setObjectName(QString::fromUtf8("btn_logout"));
        btn_logout->setGeometry(QRect(700, 20, 81, 21));
        btn_logout->setCursor(QCursor(Qt::PointingHandCursor));
        btn_logout->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(105, 183, 255, 176);\n"
" border-radius: 5px;\n"
"border: 0.5px solid;\n"
" }"));
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
        search->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search ...", nullptr));
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
