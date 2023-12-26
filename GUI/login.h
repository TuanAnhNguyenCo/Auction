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
public slots:
    void on_btn_signupPage_clicked();
    void on_btn_login_clicked();
    void update_sign_in(char *message);

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
