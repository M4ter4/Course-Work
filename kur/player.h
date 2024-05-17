#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <QKeyEvent>
#include <QTimer>

class Player : public Tank
{
    Q_OBJECT
public:
    Player(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~Player();
    void enableMovement(Direction direction);
    void shoot(qint8 damage) override;

protected:
    const qint8 maxhp = 10;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent* e) override;
    void keyReleaseEvent(QKeyEvent* e) override;

private:
    bool isMoveEnabled = false;
    QTimer *shootTimer;
    bool isShootEnabled = true;
    qint8 currentCellX;
    qint8 currentCellY;
private slots:
    void moveTimerTimeout();
    void shootTimerTimeout();
    void tick();
signals:
    void updatePos(qint8 x, qint8 y);
};

#endif // PLAYER_H
