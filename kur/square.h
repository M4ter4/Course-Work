#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsObject>
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QThread>

class Square : public QGraphicsObject
{
public:
    enum Direction{
        RIGHT = 0,
        DOWN = 90,
        LEFT = 180,
        UP = 270
    };
    Square(QGraphicsScene *scene = 0, QGraphicsItem *parent = 0);
    ~Square();
protected:
    QGraphicsScene *scene;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SQUARE_H
