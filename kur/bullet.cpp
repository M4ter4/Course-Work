#include "brickwall.h"
#include "bullet.h"
#include "player.h"
#include "steelwall.h"
#include "tank.h"

Bullet::Bullet(qreal x0, qreal y0, Direction direction, qint8 damage, QGraphicsObject *parent) : Square(x0, y0, parent) {
    double radians = qDegreesToRadians((double)direction);
    this->setRotation(direction);
    this->setPos(x0 + 22*qCos(radians), y0 + 22*qSin(radians));

    this->direction = direction;
    this->damage = damage;
    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Bullet::move);
    moveTimer->start(10);
}

Bullet::~Bullet(){}

QRectF Bullet::boundingRect() const{
    return QRectF(-2,-1,4,2);
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QBrush(Qt::white));
    painter->setPen(QPen(Qt::white));
    painter->drawRect(this->boundingRect());
    update();
}
void Bullet::move(){
    double radians = qDegreesToRadians((double)direction);
    this->setPos(this->x() + 15*qCos(radians), this->y() + 15*qSin(radians));
    foreach(auto item, scene()->collidingItems(this)){
        if(Player *player = dynamic_cast<Player*>(item)){
            if(!player->isInGhostForm()){
                player->takeDamage(damage);
                deleteLater();
            }
        }
        else if(Tank *tank = dynamic_cast<Tank*>(item)){
            tank->takeDamage(damage);
            deleteLater();
        }
        else if(BrickWall *wall = dynamic_cast<BrickWall*>(item)){
            wall->takeDamage(damage);
            deleteLater();
        }
        else if(SteelWall *wall = dynamic_cast<SteelWall*>(item)){
            deleteLater();
        }
    }
    if(this->x()>810){
        deleteLater();
    }
    if(this->x()<-10){
        deleteLater();
    }
    if(this->y()>810){
        deleteLater();
    }
    if(this->y()<-10){
        deleteLater();
    }
}
