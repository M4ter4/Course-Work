#include "enemy.h"

Enemy::Enemy(QGraphicsScene *scene, QGraphicsItem *parent) : Tank(scene, parent) {}

Enemy::~Enemy(){}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QColor(0,255,0));
    this->Tank::paint(painter, option, widget);
}
