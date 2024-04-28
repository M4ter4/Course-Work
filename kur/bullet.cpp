#include "bullet.h"

Bullet::Bullet(QGraphicsScene *scene, qreal x0, qreal y0, Direction direction, qint8 damage, QGraphicsItem *parent) : Square(scene, parent) {
    double radians = qDegreesToRadians((double)direction);
    this->setRotation(direction);
    this->setPos(x0 + 22*qCos(radians), y0 + 22*qSin(radians));

    this->direction = direction;
    this->damage = damage;
    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Bullet::move);
    moveTimer->start(100);
}

Bullet::~Bullet(){}

QRectF Bullet::boundingRect() const{
    return QRectF(-2,-1,4,2);
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(Qt::black));
    painter->drawRect(this->boundingRect());
    update();
}
void Bullet::move(){
    double radians = qDegreesToRadians((double)direction);
    this->setPos(this->x() + 10*qCos(radians), this->y() + 10*qSin(radians));
}
