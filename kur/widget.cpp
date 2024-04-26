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
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800, 800);
    Player* obj = new Player();
    scene->addItem(obj);
    this->player = obj;
    obj->grabKeyboard();
}

Widget::~Widget()
{
    delete ui;
}

