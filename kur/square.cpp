#include "square.h"

Square::Square(QGraphicsItem *parent) : QGraphicsObject(parent) {

}

Square::~Square(){}

QRectF Square::boundingRect() const
{
    return QRectF(-20,-20,40,40);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //this->setPos(200,200);
    painter->drawRect(this->boundingRect());


}


