#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QDateTime>
#include <QSet>
#include "player.h"
#include "enemy.h"
#include "steelwall.h"
#include "brickwall.h"
#include "powerup.h"
class LevelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    LevelScene();
    ~LevelScene();
    // QVector<QVector<bool>>* getField();
    // QVector<Enemy>* getEnemies();
    Player* getPlayer();
private:
    QTimer *powerUpTimer;
    Player* player;
    QVector<Enemy>* enemies;
    QVector<QVector<bool>>* field;
public slots:
    void onPowerUpTimeout();
    void onWallDestroy(Square::Cell cell);
    void onPlayerChangeCell(Square::Cell cell);
signals:
    void updatePlayerPos(Square::Cell cell);
    void updateField(QVector<QVector<bool>>*);
};

#endif // LEVELSCENE_H
