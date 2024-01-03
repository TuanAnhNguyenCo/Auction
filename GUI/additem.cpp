#include "additem.h"
#include "ui_additem.h"
#include <QMessageBox>
#include <QFileDialog>
#include "config.h"
#include "string.h"

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
    std::strcpy(MySingleton::instance().img_url, filename.toStdString().c_str());
}


void addItem::on_btn_save_clicked()
{
    CreateItemMess item;
    std::string item_name= ui->lineEdit_name->text().toStdString();
    std::string manufacturer= ui->lineEdit_manufacturer->text().toStdString();
    long double staring_price = ui->lineEdit_startingPrice->text().toDouble();
    long double bin_price = ui->lineEdit_binprice->text().toDouble();
    std::string description= ui->textEdit_description->toPlainText().toStdString();
    // Lấy thời gian từ QTimeEdit
    QTime selectedTime = ui->timeEdit_auctiontime->time();

    int hours = selectedTime.hour();
    int minutes = selectedTime.minute();
    int seconds = selectedTime.second();

    // Convert to seconds
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;

    item.BIN_price = bin_price;
    item.user_id = MySingleton::instance().joinedRoom.proprietor_id;
    item.price = staring_price;
    item.created_at =  std::time(nullptr);
    item.end =  totalSeconds;
    item.room_id = MySingleton::instance().joinedRoom.id;
    strcpy(item.name,item_name.c_str());
    strcpy(item.description,description.c_str());

    send(MySingleton::instance().getValue(), "11", BUFF_SIZE-1, 0);
    send(MySingleton::instance().getValue(), &item, sizeof(CreateItemMess), 0);

}
void addItem::sendImg(int id)
{
    // read img
    Image image;
    FILE *fp;
    fp = fopen(MySingleton::instance().img_url, "rb");
    if (fp == NULL)
    {
        qDebug() << "Can't read img";
        return;
    }
    int n = fread(image.buff, 1, sizeof(image.buff), fp);
    if (n <= 0)
    {
        qDebug() << "IMG Error";
        return;
    }
    // status == 2: carry out function 2
    image.status = 2;
    image.isFirst = 1;
    image.item_id = id;
    send(MySingleton::instance().getValue(), "26", BUFF_SIZE-1, 0);
    send(MySingleton::instance().getValue(), &image, sizeof(Image), 0);

    // read and send to server
    while (1)
    {
        int n = fread(image.buff, 1, sizeof(image.buff), fp);
        if (n <= 0)
        {
            break;
        }
        // status == 2: carry out function 2
        image.status = 2;
        image.isFirst = 0;
        send(MySingleton::instance().getValue(), "26", BUFF_SIZE - 1, 0);
        send(MySingleton::instance().getValue(), &image, sizeof(Image), 0);
    }
    fclose(fp);
    // notify to server that sending image has done
    image.status = 3;
    send(MySingleton::instance().getValue(), "26", BUFF_SIZE - 1, 0);
    send(MySingleton::instance().getValue(), &image, sizeof(Image), 0);
}


void addItem::on_btn_back_clicked()
{
    cancelClicked();
}

void addItem::handleRoomCreationStatus(char *message){
    qDebug() << "add item " << message;
    if (strcmp(message,"#OK")==0){
        QMessageBox::information(this, tr("ADD AN ITEM"), tr("Add an item successfully."));

        ui->lineEdit_name->setText("");
        ui->lineEdit_manufacturer->setText("");
        ui->lineEdit_startingPrice->setText("");
        ui->lineEdit_binprice->setText("");
        ui->textEdit_description->setText("");
        cancelClicked();
    }else{
        QMessageBox::information(this, tr("Permission Denied"), tr("You don't have any permissions to add new item."));

    }
}



void addItem::on_btn_cancel_clicked()
{
    ui->lineEdit_name->setText("");
    ui->lineEdit_manufacturer->setText("");
    ui->lineEdit_startingPrice->setText("");
    ui->lineEdit_binprice->setText("");
    ui->textEdit_description->setText("");
    emit cancelClicked();

}

