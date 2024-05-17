#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QWidget>
#include <QQueue>
#include "tank.h"
class Enemy : public Tank
{

public:
    Enemy(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~Enemy();
protected:
    QTimer *tickTimer;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public slots:
    void onWallDestroy(QVector<QVector<bool>>* field);
    void onPlayerCellUpdate(qint8 x, qint8 y);
private slots:
    void tick();
private:
    struct Point {
        int x;
        int y;
    };
    Point playerCell;
    QVector<QVector<bool>>* field;
    bool isValidSquare(const QVector<QVector<bool>>& field, int x, int y);
    Square::Direction findShortestPath(const QVector<QVector<bool>>& field, Point start, Point end);
    Square::Direction turnTo;
};

#endif // ENEMY_H
