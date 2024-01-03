/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QLabel *label;
    QLabel *label_logo_2;
    QFrame *line;
    QFrame *frame;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_pass;
    QPushButton *btn_login;
    QPushButton *btn_signupPage;

    void setupUi(QWidget *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName(QString::fromUtf8("LogIn"));
        LogIn->resize(800, 600);
        label = new QLabel(LogIn);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 261, 61));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:rgb(37, 153, 255);"));
        label_logo_2 = new QLabel(LogIn);
        label_logo_2->setObjectName(QString::fromUtf8("label_logo_2"));
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        line = new QFrame(LogIn);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(LogIn);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(110, 160, 581, 321));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(61, 91, 91, 16));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_3->setFont(font1);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 130, 81, 16));
        label_4->setFont(font1);
        lineEdit_username = new QLineEdit(frame);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(160, 90, 191, 21));
        lineEdit_pass = new QLineEdit(frame);
        lineEdit_pass->setObjectName(QString::fromUtf8("lineEdit_pass"));
        lineEdit_pass->setGeometry(QRect(160, 130, 191, 21));
        lineEdit_pass->setEchoMode(QLineEdit::Password);
        btn_login = new QPushButton(frame);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setGeometry(QRect(220, 180, 111, 31));
        btn_login->setCursor(QCursor(Qt::PointingHandCursor));
        btn_login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(105, 183, 255, 176);\n"
" border-radius: 5px;\n"
"border: 1px solid;\n"
" }"));
        btn_signupPage = new QPushButton(frame);
        btn_signupPage->setObjectName(QString::fromUtf8("btn_signupPage"));
        btn_signupPage->setGeometry(QRect(300, 220, 171, 31));
        btn_signupPage->setCursor(QCursor(Qt::PointingHandCursor));
        btn_signupPage->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-style: italic;\n"
"text-decoration: underline;\n"
"color:rgba(105, 183, 255, 176);\n"
"\n"
""));

        retranslateUi(LogIn);

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QWidget *LogIn)
    {
        LogIn->setWindowTitle(QCoreApplication::translate("LogIn", "Form", nullptr));
        label->setText(QCoreApplication::translate("LogIn", "Auction online", nullptr));
        label_logo_2->setText(QString());
        label_3->setText(QCoreApplication::translate("LogIn", "Username:", nullptr));
        label_4->setText(QCoreApplication::translate("LogIn", "Password:", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("LogIn", "Username", nullptr));
        lineEdit_pass->setPlaceholderText(QCoreApplication::translate("LogIn", " Password", nullptr));
        btn_login->setText(QCoreApplication::translate("LogIn", "Log in", nullptr));
        btn_signupPage->setText(QCoreApplication::translate("LogIn", "Create an account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
