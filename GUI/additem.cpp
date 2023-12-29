#include "additem.h"
#include "ui_additem.h"
#include <QMessageBox>
#include <QFileDialog>

addItem::addItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addItem)
{
    ui->setupUi(this);
    ui->btn_back->setIcon(QIcon(":/image/icon_back.jpeg"));

}

addItem::~addItem()
{
    delete ui;
}

void addItem::on_btn_choosePic_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "",tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_image->width(), Qt::SmoothTransformation);
            ui->label_image->setPixmap(QPixmap::fromImage(image));

        }
        else {
            QMessageBox::critical(this, tr("ERROR"), tr("Can not load the image"));
        }
    }
}


void addItem::on_btn_save_clicked()
{
    QMessageBox::information(this, tr("ADD AN ITEM"), tr("Add an item successfully."));
    cancelClicked();

}


void addItem::on_btn_back_clicked()
{
    cancelClicked();
}



void addItem::on_btn_cancel_clicked()
{
    QMessageBox::information(this, tr("Don't save"), tr("Delete this item."));
    emit cancelClicked();

}

