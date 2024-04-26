#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <QKeyEvent>
#include <QTimer>

class Player : public Tank
{

public:
    Player(QGraphicsItem *parent = 0);
    ~Player();
    void move(Direction direction);

protected:
    void keyPressEvent(QKeyEvent* e) override;
    void keyReleaseEvent(QKeyEvent* e) override;

private:
    bool enableMove = false;
private slots:
    void timerSlot();
};

#endif // PLAYER_H
