#ifndef DRAFT_H
#define DRAFT_H

#include <QWidget>

namespace Ui {
class draft;
}

class draft : public QWidget
{
    Q_OBJECT

public:
    explicit draft(QWidget *parent = nullptr);
    ~draft();

private:
    Ui::draft *ui;
};

#endif // DRAFT_H
