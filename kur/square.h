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
#include <QDir>


class Square : public QGraphicsObject
{

public:
    enum Direction{
        NONE = 360,
        RIGHT = 0,
        DOWN = 90,
        LEFT = 180,
        UP = 270
    };
    static Direction getOpposite(Direction dir);
    Square(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~Square();
    qint8 getCellX();
    qint8 getCellY();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPixmap pixmap;

};

#endif // SQUARE_H
