#include "player.h"

Player::Player(QGraphicsItem *parent) : Tank(parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::timerSlot);
    timer->start(100);
    hp = maxhp;
}
Player::~Player(){}

void Player::keyPressEvent(QKeyEvent* e){
    if(e->key() == Qt::Key_D){
        this->move(Square::RIGHT);
    }
    if(e->key() == Qt::Key_S){
        this->move(Square::DOWN);
    }
    if(e->key() == Qt::Key_A){
        this->move(Square::LEFT);
    }
    if(e->key() == Qt::Key_W){
        this->move(Square::UP);
    }
    // if(e->key() == Qt::Key_Space){
    //     qDebug() << "space";
    // }
    // if(e->key() == Qt::Key_F){
    //     qDebug() << "f";
    // }
    update();
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QColor(0,255,0));
    this->Tank::paint(painter, option, widget);
}

void Player::keyReleaseEvent(QKeyEvent* e){
    Direction direction;
    if(e->key() == Qt::Key_D){
        direction = Square::RIGHT;
    }
    else if(e->key() == Qt::Key_S){
        direction = Square::DOWN;
    }
    else if(e->key() == Qt::Key_A){
        direction = Square::LEFT;
    }
    else if(e->key() == Qt::Key_W){
        direction = Square::UP;
    }
    else {
        return;
    }

    if(this->direction == direction){
        enableMove = false;
    }
}

void Player::move(Direction direction){
    if (this->direction == direction){
        this->enableMove = true;
    }
    else {
        this->rotate(direction);
        this->enableMove = false;
    }
}

void Player::timerSlot(){
    if(enableMove){
    this->Tank::move();
    }
}
