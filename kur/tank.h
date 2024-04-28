#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QWidget>
#include "square.h"
#include "bullet.h"

class Tank : public Square
{
    Q_OBJECT
public:
    Tank(QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Tank();
    void rotate(Direction direction);
    void move();
    virtual void shoot(qint8 damage);
    void changehp(qint8 delta);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Direction getDirection();
protected:
    const qint8 maxhp = 5;
    qint8 hp;
    Direction direction;
    QRectF boundingRect() const override;
};

#endif // TANK_H
