#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QWidget>
#include "square.h"

class Tank : public Square
{
    Q_OBJECT
public:
    Tank(QGraphicsItem *parent = 0);
    ~Tank();
    void rotate(Direction direction);
    void move();
    void shoot();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    Direction direction;
};

#endif // TANK_H
