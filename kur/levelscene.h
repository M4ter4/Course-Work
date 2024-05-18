#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "steelwall.h"
#include "brickwall.h"
class LevelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    LevelScene();
    ~LevelScene();
    // QVector<QVector<bool>>* getField();
    QVector<Enemy>* getEnemies();
    Player* getPlayer();
private:
    Player* player;
    qint8 walls[20][20];
    QVector<Enemy>* enemies;
    QVector<QVector<bool>>* field;
public slots:
    void onWallDestroy(qint8 x, qint8 y);
    void onPlayerChangeCell(qint8 x, qint8 y);
signals:
    void updatePlayerPos(qint8 x, qint8 y);
    void updateField(QVector<QVector<bool>>*);
};

#endif // LEVELSCENE_H
