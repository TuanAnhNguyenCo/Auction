#ifndef CREATEPAGE_H
#define CREATEPAGE_H

#include <QWidget>
#include <QFileDialog>
#include "additem.h"
#include "roomoverview.h"
namespace Ui {
class CreatePage;
}

class CreatePage : public QWidget
{
    Q_OBJECT

public:
    explicit CreatePage(QWidget *parent = nullptr);
    ~CreatePage();

private:
    Ui::CreatePage *ui;
    addItem addItemobj;
    RoomOverview roomOverviewobj;

signals:
    void HomeClicked();
    void HistoryClicked();
private slots:
    void on_btn_hometab_clicked();
    void on_btn_historytab_clicked();
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void addNewItem();
    void on_btn_createtab_clicked();
public slots:
    void handleMessageFromRoomCreationRequest(char *Message);
};

#endif // CREATEPAGE_H
