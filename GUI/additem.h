#ifndef ADDITEM_H
#define ADDITEM_H

#include <QWidget>

namespace Ui {
class addItem;
}

class addItem : public QWidget
{
    Q_OBJECT

public:
    explicit addItem(QWidget *parent = nullptr);
    ~addItem();

private slots:
    void on_btn_choosePic_clicked();
    void on_btn_save_clicked();
    void on_btn_back_clicked();
    void on_btn_cancel_clicked();
signals:
    void backOverview();
private:
    Ui::addItem *ui;
};

#endif // ADDITEM_H
