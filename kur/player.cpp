#include "player.h"

Player::Player(QGraphicsItem *parent) : Tank(parent) {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::timerSlot);
    timer->start(100);
}
Player::~Player(){}

void Player::keyPressEvent(QKeyEvent* e){
    qDebug() << e->key();
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
