#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QWidget>
#include "square.h"
#include "bullet.h"

class Tank : public Square
{

public:
    Tank(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~Tank();
    void rotate(Direction direction);
    void move();
    virtual void shoot(qint8 damage);
    void takeDamage(qint8 damage);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Direction getDirection();
protected:

    QTimer *reloadTimer;

    const qint8 maxhp = 5;
    qint8 hp;
    Direction direction;
    QRectF boundingRect() const override;
};

#endif // TANK_H
