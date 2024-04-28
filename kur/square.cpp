#include "square.h"

Square::Square(QGraphicsScene *scene, QGraphicsItem *parent) : QGraphicsObject(parent) {
    scene->addItem(this);
    this->scene = scene;
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


