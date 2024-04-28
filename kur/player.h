#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <QKeyEvent>
#include <QTimer>

class Player : public Tank
{

public:
    Player(QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Player();
    void enableMovement(Direction direction);
    void shoot(qint8 damage) override;

protected:
    const qint8 maxhp = 10;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent* e) override;
    void keyReleaseEvent(QKeyEvent* e) override;

private:
    bool isMoveEnabled = false;
    QTimer *shootTimer;
    bool isShootEnabled = true;
private slots:
    void moveTimerTimeout();
    void shootTimerTimeout();
};

#endif // PLAYER_H
