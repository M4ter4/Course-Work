#include "widget.h"
#include "ui_widget.h"
#include "square.h"
#include <QDebug>
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
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

Widget::~Widget()
{
    delete ui;
}

