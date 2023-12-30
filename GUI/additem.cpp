#include "additem.h"
#include "ui_additem.h"
#include <QMessageBox>
#include <QFileDialog>
#include "config.h"

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
    CreateItemMess item;
    std::string item_name= ui->lineEdit_name->text().toStdString();
    std::string manufacturer= ui->lineEdit_manufacturer->text().toStdString();
    long double staring_price = ui->lineEdit_startingPrice->text().toDouble();
    long double bin_price = ui->lineEdit_binprice->text().toDouble();
    std::string description= ui->textEdit_description->toPlainText().toStdString();
    // Lấy thời gian từ QTimeEdit
    QTime selectedTime = ui->timeEdit_auctiontime->time();
    // Lấy ngày hiện tại
    QDate currentDate = QDate::currentDate();
    // Kết hợp ngày và giờ để tạo QDateTime
    QDateTime combinedDateTime(currentDate, selectedTime);
    // Chuyển đổi từ QDateTime sang time_t
    time_t timeAsTimeT = combinedDateTime.toSecsSinceEpoch();

    item.BIN_price = bin_price;
    item.user_id = MySingleton::instance().joinedRoom.proprietor_id;
    item.price = staring_price;
    item.created_at =  std::time(nullptr);
    item.end =  item.created_at + timeAsTimeT;
    item.room_id = MySingleton::instance().joinedRoom.id;
    strcpy(item.name,item_name.c_str());
    strcpy(item.description,description.c_str());

    send(MySingleton::instance().getValue(), "11", BUFF_SIZE-1, 0);
    send(MySingleton::instance().getValue(), &item, sizeof(CreateItemMess), 0);



}


void addItem::on_btn_back_clicked()
{
    cancelClicked();
}

void addItem::handleRoomCreationStatus(char *message){
    qDebug() << "add item " << message;
    if (strcmp(message,"#OK")){
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
    QMessageBox::information(this, tr("Don't save"), tr("Delete this item."));
    emit cancelClicked();

}

