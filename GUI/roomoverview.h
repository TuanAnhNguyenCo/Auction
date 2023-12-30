#ifndef ROOMOVERVIEW_H
#define ROOMOVERVIEW_H

#include <QWidget>

namespace Ui {
class RoomOverview;
}

class RoomOverview : public QWidget
{
    Q_OBJECT

public:
    explicit RoomOverview(QWidget *parent = nullptr);
    ~RoomOverview();
signals:
    void backtoRoomClicked();
    void addItemClicked();
private slots:
    void on_btn_backAuctionroom_clicked();
    void on_btn_add_clicked();

public slots:
    void showItems();

private:
    Ui::RoomOverview *ui;
};

#endif // ROOMOVERVIEW_H
