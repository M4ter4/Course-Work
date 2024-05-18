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
    void move(qint64 stepSize) override;
protected:
    const qint8 maxhp = 10;
    void keyPressEvent(QKeyEvent* e) override;
    void keyReleaseEvent(QKeyEvent* e) override;


private:
    bool isMoveEnabled = false;
    qint8 currentCellX;
    qint8 currentCellY;
    qint64 stepSize = 4;
private slots:
    void moveTimerTimeout();
signals:
    void updatePos(qint8 x, qint8 y);
};

#endif // PLAYER_H
