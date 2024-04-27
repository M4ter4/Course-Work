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
    void changehp(qint8 delta);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
protected:
    const qint8 maxhp = 5;
    qint8 hp;
    Direction direction;
};

#endif // TANK_H
