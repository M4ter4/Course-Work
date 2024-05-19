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
    LevelScene(qint8 difficulty);
    ~LevelScene();
private:
    QTimer *powerUpTimer;
    QVector<QVector<bool>>* field;
    qint8 currentEnemiesCount = 0;
public slots:
    void onPowerUpTimeout();
    void onWallDestroy(Square::Cell cell);
    void onPlayerChangeCell(Square::Cell cell);
    void onEnemyDeathSlot();
    void onPlayerDeathSlot();
     void changePlayerHPSlot(qint8 hp);
signals:
    void updatePlayerPos(Square::Cell cell);
    void updateField(QVector<QVector<bool>>*);
    void gameOverSignal();
    void enemyDeathSignal();
    void nextRoundSignal();
    void changePlayerHP(qint8 hp);
};

#endif // LEVELSCENE_H
