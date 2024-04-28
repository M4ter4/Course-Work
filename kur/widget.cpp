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
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800, 800);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Player* obj = new Player(scene);
    //Bullet *bullet = new Bullet(scene, 400, 400, Square::RIGHT, 1);
    // scene->addItem(obj);
    this->player = obj;
    obj->grabKeyboard();
}

Widget::~Widget()
{
    delete ui;
}

