#ifndef CREATEPAGE_H
#define CREATEPAGE_H

#include <QWidget>
#include <QFileDialog>

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

signals:
    void HomeClicked();
    void HistoryClicked();
private slots:
    void on_btn_hometab_clicked();
    void on_btn_historytab_clicked();
    void on_pushButton_clicked();
    void on_btn_save_clicked();
};

#endif // CREATEPAGE_H
