#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();
signals:
    void SignupClicked();
    void LoginOk();
private slots:
    void on_btn_signupPage_clicked();
    void on_btn_login_clicked();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
