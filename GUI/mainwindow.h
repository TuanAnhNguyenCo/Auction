#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include "createpage.h"
#include "historypage.h"
#include "auctionroom.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_createtab_clicked();
    void on_btn_historytab_clicked();
    void moveHome();
    void moveCreateTab();
    void moveHistoryTab();
    void moveAuctionRoom();
private:
    Ui::MainWindow *ui;
    CreatePage CreatePage;
    HistoryPage HistoryPage;
    AuctionRoom AuctionRoom;
};
#endif // MAINWINDOW_H
