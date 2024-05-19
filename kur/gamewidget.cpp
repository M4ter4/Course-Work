#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "square.h"
#include <QDebug>
#include <QKeyEvent>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setFixedSize(800, 800);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::startGame(qint8 difficulty)
{
    this->difficulty = difficulty;
    createNewGame();
}

void GameWidget::gameOverSlot()
{
    scene->deleteLater();
    emit gameOverSignal();
}

void GameWidget::nextRoundSlot()
{
    scene->deleteLater();
    createNewGame();
}

void GameWidget::changePlayerHp(qint8 hp)
{
    ui->healthLabel->setText(QString::number(hp));
}

void GameWidget::increaseKillCount()
{
    ++killCount;
    ui->killsLabel->setText(QString::number(killCount));
}

void GameWidget::createNewGame()
{
    LevelScene* scene = new LevelScene(difficulty);
    this->scene = scene;
    scene->setSceneRect(0,0,800,800);
    ui->graphicsView->setScene(scene);
    connect(scene, &LevelScene::gameOverSignal, this, &GameWidget::gameOverSlot);
    connect(scene, &LevelScene::nextRoundSignal, this, &GameWidget::nextRoundSlot);
    connect(scene, &LevelScene::enemyDeathSignal, this, &GameWidget::increaseKillCount);
    connect(scene, &LevelScene::changePlayerHP, this, &GameWidget::changePlayerHp);
    changePlayerHp(10);
}


