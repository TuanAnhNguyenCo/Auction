#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

signals:
    void LoginClicked();

private slots:
    void on_btn_loginPage_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H