#include "gameoverwidget.h"
#include "ui_gameoverwidget.h"

GameOverWidget::GameOverWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOverWidget)
{
    ui->setupUi(this);
}

GameOverWidget::~GameOverWidget()
{
    delete ui;
}

void GameOverWidget::on_pushButton_clicked()
{
    emit restartGameSignal();
}

