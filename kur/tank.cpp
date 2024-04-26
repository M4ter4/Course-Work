#include "tank.h"
#include "QDebug"

Tank::Tank(QGraphicsItem *parent) : Square(parent) {
    this->direction = Direction::UP;
}
Tank::~Tank(){}
void Tank::shoot(){}
void Tank::rotate(Direction direction){
    this->direction = direction;
    update();
}
void Tank::move(){
    double radians = qDegreesToRadians((double)direction);
    qDebug() << " " << radians << " " << qCos(radians) << " " << qSin(radians);
    this->setPos(this->x() + 10*qCos(radians), this->y() + 10*qSin(radians));

}
void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF boundingRect = this->boundingRect();
    QPolygonF polygon;
    polygon.append(boundingRect.topLeft());
    polygon.append(QPointF(boundingRect.center().x(), boundingRect.top()));
    polygon.append(QPointF(boundingRect.right(), boundingRect.center().x()));
    polygon.append(QPointF(boundingRect.center().x(), boundingRect.bottom()));
    polygon.append(boundingRect.bottomLeft());
    this->setRotation(direction);
    painter->drawPolygon(polygon);
}
