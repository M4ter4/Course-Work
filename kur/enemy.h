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
    void move(qint64 stepSize) override;
    QTimer *tickTimer;
public slots:
    void onWallDestroy(QVector<QVector<bool>>* field);
    void onPlayerCellUpdate(qint8 x, qint8 y);
private slots:
    void tick();
private:
     qint64 stepSize = 2;
    struct Point {
        int x;
        int y;
    };
    Point playerCell;
    QVector<QVector<bool>>* field;
    bool isValidSquare(const QVector<QVector<bool>>& field, int x, int y);
    bool isValidSquare(const QVector<QVector<bool>>& field, int x, int y, QList<Enemy*> enemies);
    Square::Direction findShortestPath(const QVector<QVector<bool>>& field, Point start, Point end);
    Square::Direction findShortestPath(const QVector<QVector<bool>>& field, Point start, Point end, QList<Enemy*> enemies);
    Square::Direction turnTo;
};

#endif // ENEMY_H
