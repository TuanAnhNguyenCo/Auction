#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <QWidget>
namespace Ui {
class HistoryPage;
}

class HistoryPage : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryPage(QWidget *parent = nullptr);
    ~HistoryPage();
signals:
    void HomeClicked();
    void CreateClicked();
    void HistoryDetailClicked();

private slots:
    void on_btn_hometab_clicked();
    void on_btn_createtab_clicked();
    void viewClicked();


public slots:
    void moveHistoryPage();
    void showJoinedRooms();

private:
    Ui::HistoryPage *ui;


};

#endif // HISTORYPAGE_H
