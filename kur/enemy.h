#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QWidget>
#include "tank.h"
class Enemy : public Tank
{
public:
    Enemy(QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Enemy();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ENEMY_H
