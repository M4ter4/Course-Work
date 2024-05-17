#include "square.h"

Square::Square(qint8 x, qint8 y, QGraphicsObject *parent) : QGraphicsObject(parent) {
    this->setPos(20+40*x, 20+40*y);
}

Square::~Square(){}

qint8 Square::getCellX()
{
    return (qRound(x())-20)/40;
}

qint8 Square::getCellY()
{
    return (qRound(y())-20)/40;
}

QRectF Square::boundingRect() const
{
    return QRectF(-20,-20,40,40);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //this->setPos(200,200);
    painter->drawPixmap(this->boundingRect(), this->pixmap, QRectF(0,0,this->boundingRect().x(),this->boundingRect().y()));
}


