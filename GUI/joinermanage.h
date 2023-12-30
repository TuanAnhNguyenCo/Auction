#ifndef JOINERMANAGE_H
#define JOINERMANAGE_H

#include <QWidget>

namespace Ui {
class JoinerManage;
}

class JoinerManage : public QWidget
{
    Q_OBJECT

public:
    explicit JoinerManage(QWidget *parent = nullptr);
    ~JoinerManage();
private slots:
    void kickUser();

    void on_btn_back_clicked();
signals:
    void backClicked();
private:
    Ui::JoinerManage *ui;
};

#endif // JOINERMANAGE_H
