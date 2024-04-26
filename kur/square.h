#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsObject>
#include <QPainter>
#include <QtMath>
#include <QDebug>

class Square : public QGraphicsObject
{
public:
    enum Direction{
        RIGHT = 0,
        DOWN = 90,
        LEFT = 180,
        UP = 270
    };
    Square(QGraphicsItem *parent = 0);
    ~Square();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H
