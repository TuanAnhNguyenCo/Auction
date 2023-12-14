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
private slots:
    void on_btn_backAuctionroom_clicked();

private:
    Ui::RoomOverview *ui;
};

#endif // ROOMOVERVIEW_H
