#include "mainwidget.h"
#include "qdebug.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->gameWidget->hide();
    ui->gameOverWidget->hide();
    connect(ui->startWidget, &StartWidget::startSignal, this, &MainWidget::startNewGameSlot);
    connect(ui->gameWidget, &GameWidget::gameOverSignal, this, &MainWidget::gameOverSlot);
    connect(ui->gameOverWidget, &GameOverWidget::restartGameSignal, this, &MainWidget::restartSlot);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::startNewGameSlot(qint8 difficulty)
{
    ui->startWidget->hide();
    ui->gameWidget->show();
    ui->gameWidget->startGame(difficulty);
}

void MainWidget::gameOverSlot()
{
    ui->gameWidget->hide();
    ui->gameOverWidget->show();
}

void MainWidget::restartSlot()
{
    ui->gameOverWidget->hide();
    ui->startWidget->show();
}
