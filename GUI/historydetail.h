#ifndef HISTORYDETAIL_H
#define HISTORYDETAIL_H

#include <QWidget>

namespace Ui {
class HistoryDetail;
}

class HistoryDetail : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryDetail(QWidget *parent = nullptr);
    ~HistoryDetail();
signals:
    void backHistoryClicked();
private slots:
    void on_btn_back_clicked();

public slots:
    void showItemInfo();


private:
    Ui::HistoryDetail *ui;
};

#endif // HISTORYDETAIL_H
