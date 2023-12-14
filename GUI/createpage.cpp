#include "createpage.h"
#include "ui_createpage.h"
#include <QMessageBox>
CreatePage::CreatePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreatePage)
{
    ui->setupUi(this);
    QPixmap logo(":/image/logo_auction.png");
    ui->label_logo_2->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
}

CreatePage::~CreatePage()
{
    delete ui;
}

void CreatePage::on_btn_hometab_clicked()
{
    emit HomeClicked();
}

void CreatePage::on_btn_historytab_clicked()
{
    emit HistoryClicked();
}


void CreatePage::on_pushButton_clicked()
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


void CreatePage::on_btn_save_clicked()
{
    QMessageBox::information(this, tr("CREATE A ROOM"), tr("Create an auction room successfully."));

}

