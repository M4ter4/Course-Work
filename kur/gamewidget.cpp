#include "gamewidget.h"
#include "ui_widget.h"
#include "square.h"
#include <QDebug>
#include <QKeyEvent>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    LevelScene* scene = new LevelScene();
    scene->setSceneRect(0,0,800,800);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800, 800);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameWidget::~GameWidget()
{
    delete ui;
}


void GameWidget::on_pushButton_clicked()
{
    qDebug() << "clicked";
}

