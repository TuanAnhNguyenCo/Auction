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
    void on_btn_cancel_clicked();
    void on_btn_back_clicked();
public slots:
    void handleRoomCreationStatus(char *message);
signals:
    void cancelClicked();
private:
    Ui::addItem *ui;
};

#endif // ADDITEM_H
