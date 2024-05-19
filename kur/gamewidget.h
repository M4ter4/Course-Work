#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "player.h"
#include "levelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    void startGame(qint8 difficulty);
private slots:
    void gameOverSlot();
    void nextRoundSlot();
private:
    LevelScene *scene;
    Ui::Widget *ui;
    qint8 playerHP;
    qint8 difficulty;
    qint64 killCount=0;
    void changePlayerHp(qint8 hp);
    void increaseKillCount();
    void createNewGame();
signals:
    void gameOverSignal();
};
#endif // GAMEWIDGET_H
