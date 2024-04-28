#include "tank.h"
#include "QDebug"

Tank::Tank(QGraphicsScene *scene, QGraphicsItem *parent) : Square(scene, parent) {
    hp = maxhp;
    this->direction = Direction::UP;
}
Tank::~Tank(){}

Square::Direction Tank::getDirection(){
    return this->direction;
}

QRectF Tank::boundingRect() const
{
    return QRectF(-18,-18,36,36);
}

void Tank::shoot(qint8 damage){
    Bullet *bullet = new Bullet(scene, this->x(), this->y(), this->direction, damage);
}

void Tank::rotate(Direction direction){
    this->direction = direction;
    update();
}
void Tank::move(){
    double radians = qDegreesToRadians((double)direction);
    this->setPos(this->x() + 50*qCos(radians), this->y() + 50*qSin(radians));
}

void Tank::changehp(qint8 delta){
    this->hp += delta;
    if(hp>maxhp){
        hp = maxhp;
    }
    if (hp <= 0){
        qDebug() << "ADD SIGNAL EMITTING";
    }
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
