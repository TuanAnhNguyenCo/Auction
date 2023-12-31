/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLabel *label_logo_2;
    QFrame *line;
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_phonenum;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_pass;
    QPushButton *btn_signup;
    QPushButton *btn_loginPage;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(800, 600);
        label_logo_2 = new QLabel(SignUp);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        line = new QFrame(SignUp);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(SignUp);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 131, 61));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        label->setFont(font);
        frame = new QFrame(SignUp);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(120, 160, 561, 361));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 40, 191, 16));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(61, 91, 91, 16));
        label_3->setFont(font1);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 180, 81, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 120, 111, 21));
        label_5->setFont(font1);
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(61, 151, 59, 18));
        label_6->setFont(font1);
        lineEdit_username = new QLineEdit(frame);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(170, 90, 361, 21));
        lineEdit_phonenum = new QLineEdit(frame);
        lineEdit_phonenum->setObjectName("lineEdit_phonenum");
        lineEdit_phonenum->setGeometry(QRect(170, 120, 361, 21));
        lineEdit_address = new QLineEdit(frame);
        lineEdit_address->setObjectName("lineEdit_address");
        lineEdit_address->setGeometry(QRect(170, 150, 361, 21));
        lineEdit_pass = new QLineEdit(frame);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(170, 180, 361, 21));
        btn_signup = new QPushButton(frame);
        btn_signup->setObjectName("btn_signup");
        btn_signup->setGeometry(QRect(210, 220, 111, 41));
        btn_loginPage = new QPushButton(frame);
        btn_loginPage->setObjectName("btn_loginPage");
        btn_loginPage->setGeometry(QRect(290, 260, 171, 31));
        btn_loginPage->setStyleSheet(QString::fromUtf8("border:none;\n"
"font-style: italic;\n"
"text-decoration: underline;\n"
"\n"
""));

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Form", nullptr));
        label_logo_2->setText(QString());
        label->setText(QCoreApplication::translate("SignUp", "Sign up", nullptr));
        label_2->setText(QCoreApplication::translate("SignUp", "Create your own account", nullptr));
        label_3->setText(QCoreApplication::translate("SignUp", "User's name:", nullptr));
        label_4->setText(QCoreApplication::translate("SignUp", "Password:", nullptr));
        label_5->setText(QCoreApplication::translate("SignUp", "Phone number:", nullptr));
        label_6->setText(QCoreApplication::translate("SignUp", "Address:", nullptr));
        btn_signup->setText(QCoreApplication::translate("SignUp", "Sign up", nullptr));
        btn_loginPage->setText(QCoreApplication::translate("SignUp", "Already had an account...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
