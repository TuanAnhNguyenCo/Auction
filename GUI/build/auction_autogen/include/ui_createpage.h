/********************************************************************************
** Form generated from reading UI file 'createpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPAGE_H
#define UI_CREATEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatePage
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_logo_2;
    QPushButton *btn_createtab;
    QPushButton *btn_hometab;
    QPushButton *btn_historytab;
    QFrame *line;
    QLabel *label;
    QGroupBox *info_item;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QPushButton *btn_save;
    QPushButton *btn_cancel;

    void setupUi(QWidget *CreatePage)
    {
        if (CreatePage->objectName().isEmpty())
            CreatePage->setObjectName("CreatePage");
        CreatePage->resize(800, 600);
        stackedWidget = new QStackedWidget(CreatePage);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 601));
        page = new QWidget();
        page->setObjectName("page");
        label_logo_2 = new QLabel(page);
        label_logo_2->setObjectName("label_logo_2");
        label_logo_2->setGeometry(QRect(10, 10, 61, 51));
        btn_createtab = new QPushButton(page);
        btn_createtab->setObjectName("btn_createtab");
        btn_createtab->setGeometry(QRect(230, 10, 141, 41));
        btn_createtab->setStyleSheet(QString::fromUtf8("border: none;\n"
"    padding: 0;\n"
"    background: none;\n"
" background-color: transparent; \n"
"    text-decoration: underline;\n"
"    margin: 0 10px;\n"
"\n"
"\n"
""));
        btn_hometab = new QPushButton(page);
        btn_hometab->setObjectName("btn_hometab");
        btn_hometab->setGeometry(QRect(100, 10, 111, 41));
        btn_historytab = new QPushButton(page);
        btn_historytab->setObjectName("btn_historytab");
        btn_historytab->setGeometry(QRect(390, 10, 111, 41));
        line = new QFrame(page);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 60, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 221, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(24);
        font.setBold(true);
        label->setFont(font);
        info_item = new QGroupBox(page);
        info_item->setObjectName("info_item");
        info_item->setGeometry(QRect(20, 130, 751, 131));
        lineEdit_name = new QLineEdit(info_item);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(120, 40, 531, 31));
        lineEdit_name->setStyleSheet(QString::fromUtf8("border-radius: 10px; padding: 2px; border: 1px solid gray; "));
        label_2 = new QLabel(info_item);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(21, 41, 39, 16));
        btn_save = new QPushButton(page);
        btn_save->setObjectName("btn_save");
        btn_save->setGeometry(QRect(240, 290, 91, 41));
        btn_cancel = new QPushButton(page);
        btn_cancel->setObjectName("btn_cancel");
        btn_cancel->setGeometry(QRect(360, 290, 101, 41));
        stackedWidget->addWidget(page);

        retranslateUi(CreatePage);

        QMetaObject::connectSlotsByName(CreatePage);
    } // setupUi

    void retranslateUi(QWidget *CreatePage)
    {
        CreatePage->setWindowTitle(QCoreApplication::translate("CreatePage", "Form", nullptr));
        label_logo_2->setText(QString());
        btn_createtab->setText(QCoreApplication::translate("CreatePage", "Create auction room", nullptr));
        btn_hometab->setText(QCoreApplication::translate("CreatePage", "Home ", nullptr));
        btn_historytab->setText(QCoreApplication::translate("CreatePage", "Auction history", nullptr));
        label->setText(QCoreApplication::translate("CreatePage", "Create new room", nullptr));
        info_item->setTitle(QString());
        label_2->setText(QCoreApplication::translate("CreatePage", "Name:", nullptr));
        btn_save->setText(QCoreApplication::translate("CreatePage", "Save", nullptr));
        btn_cancel->setText(QCoreApplication::translate("CreatePage", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatePage: public Ui_CreatePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPAGE_H
