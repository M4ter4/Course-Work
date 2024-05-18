#include "tank.h"


Tank::Tank(qint8 x, qint8 y, QGraphicsObject *parent) : Square(x,y, parent) {
    reloadTimer = new QTimer(this);
    reloadTimer->setSingleShot(true);
    reloadTimer->setInterval(1000);
    connect(reloadTimer, &QTimer::timeout, this, &Tank::shootTimerTimeout);
    hp = maxhp;
    this->direction = Direction::NONE;
}
Tank::~Tank(){}

void Tank::shootTimerTimeout(){
    this->isShootEnabled=true;
}

Square::Direction Tank::getDirection(){
    return this->direction;
}

QRectF Tank::boundingRect() const
{
    return QRectF(-18,-18,36,36);
}

void Tank::shoot(qint8 damage){
    if(isShootEnabled){
        Bullet *bullet = new Bullet(this->x(), this->y(), this->direction, damage);
        scene()->addItem(bullet);
        isShootEnabled = false;
        reloadTimer->start();
    }
}

void Tank::rotate(Direction direction){
    this->direction = direction;
    update();
}
void Tank::move(qint64 stepSize){
    if (direction == NONE){
        return;
    }
    double radians = qDegreesToRadians((double)direction);
    this->setPos(this->x() + stepSize*qCos(radians), this->y() + stepSize*qSin(radians));
    if(qRound64(x())>780){
        this->setPos(this->x() - stepSize, this->y());
    }
    if(qRound64(x())<20){
        this->setPos(this->x() + stepSize, this->y());
    }
    if(qRound64(y())>780){
        this->setPos(this->x(), this->y() - stepSize);
    }
    if(qRound64(y())<20){
        this->setPos(this->x(), this->y() + stepSize);
    }
    // foreach(auto item, scene()->collidingItems(this)){
    //     if(Tank *tank = dynamic_cast<Tank*>(item)){
    //         this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
    //     }
    //     if(SteelWall *wall = dynamic_cast<SteelWall*>(item)){
    //         this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
    //     }
    // }
}

void Tank::takeDamage(qint8 damage){
    this->hp -= damage;
    if (hp <= 0){
        qDebug() << "ADD SIGNAL EMITTING";
        deleteLater();
    }
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF boundingRect = this->boundingRect();
    // QPolygonF polygon;
    // polygon.append(boundingRect.topLeft());
    // polygon.append(QPointF(boundingRect.center().x(), boundingRect.top()));
    // polygon.append(QPointF(boundingRect.right(), boundingRect.center().x()));
    // polygon.append(QPointF(boundingRect.center().x(), boundingRect.bottom()));
    // polygon.append(boundingRect.bottomLeft());
    this->setRotation(direction);
    this->Square::paint(painter, option, widget);
}
