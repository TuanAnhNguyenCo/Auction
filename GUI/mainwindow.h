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



private:
    Ui::MainWindow *ui;
    CreatePage CreatePage;
    HistoryPage HistoryPage;
    AuctionRoom AuctionRoom;
    SignUp SignUp;
    LogIn LogIn;
    Worker *worker;
    QThread *workerThread;
};
#endif // MAINWINDOW_H
