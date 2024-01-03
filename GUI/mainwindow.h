#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include <QThread>
#include "worker.h"
#include "createpage.h"
#include "historypage.h"
#include "auctionroom.h"
#include "signup.h"
#include "login.h"
#include "historydetail.h"

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

signals:
    void callShowItem();

public slots:
    void on_btn_createtab_clicked();
    void on_btn_historytab_clicked();
    void moveHome();
    void moveCreateTab();
    void moveHistoryTab();
    void moveAuctionRoom(char *message);
    void on_btn_logout_clicked();
    void moveSignupPage();
    void moveLoginPage();
    void handleLogout(char *message);
    void notifyInfo(char *message);
    void moveHistoryDetailPage();


private slots:
    void on_search_textChanged();

private:
    Ui::MainWindow *ui;
    CreatePage createpage; //
    HistoryPage historypage; //
    AuctionRoom auctionroom; //
    SignUp signup; //
    LogIn login; //
    Worker *worker;
    QThread *workerThread;
    HistoryDetail historydetail;
};
#endif // MAINWINDOW_H
