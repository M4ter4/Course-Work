#include "player.h"

Player::Player(QGraphicsScene *scene, QGraphicsItem *parent) : Tank(scene, parent) {
    shootTimer = new QTimer(this);
    shootTimer->setSingleShot(true);
    shootTimer->setInterval(1000);
    connect(shootTimer, &QTimer::timeout, this, &Player::shootTimerTimeout);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::moveTimerTimeout);
    timer->start(100);
    hp = maxhp;
}
Player::~Player(){}

void Player::shoot(qint8 damage){
    if(isShootEnabled){
        this->Tank::shoot(damage);
        isShootEnabled = false;
        shootTimer->start();
    }
}

void Player::keyPressEvent(QKeyEvent* e){
    if(e->key() == Qt::Key_D){
        this->enableMovement(Square::RIGHT);
    }
    if(e->key() == Qt::Key_S){
        this->enableMovement(Square::DOWN);
    }
    if(e->key() == Qt::Key_A){
        this->enableMovement(Square::LEFT);
    }
    if(e->key() == Qt::Key_W){
        this->enableMovement(Square::UP);
    }
    if(e->key() == Qt::Key_Space){
        this->shoot(1);
    }
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
        isMoveEnabled = false;
    }
}

void Player::enableMovement(Direction direction){
    if (this->direction == direction){
        this->isMoveEnabled = true;
    }
    else {
        this->rotate(direction);
        this->isMoveEnabled = false;
    }
}

void Player::moveTimerTimeout(){
    if(isMoveEnabled){
    this->move();
    }
}

void Player::shootTimerTimeout(){
    this->isShootEnabled=true;
}
