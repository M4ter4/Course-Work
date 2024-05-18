#include "player.h"

Player::Player(qint8 x, qint8 y, QGraphicsObject *parent) : Tank(x, y, parent) {
    QPixmap map(QDir::current().filePath("resources/player.jpg"));
    this->pixmap = map;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::moveTimerTimeout);
    timer->start(10);
    hp = maxhp;
    currentCellX = getCellX();
    currentCellY = getCellY();
}
Player::~Player(){}

void Player::shoot(qint8 damage){
    if(isShootEnabled){
        this->Tank::shoot(damage);
        isShootEnabled = false;
        reloadTimer->start();
    }
}

void Player::move(qint64 stepSize)
{
    Tank::move(stepSize);
    double radians = qDegreesToRadians((double)direction);
    foreach(auto item, scene()->collidingItems(this)){
        if(Tank *tank = dynamic_cast<Tank*>(item)){
            this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
        }
        if(SteelWall *wall = dynamic_cast<SteelWall*>(item)){
            this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
        }
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
    this->move(stepSize);
        if(currentCellX != getCellX() || currentCellY != getCellY()){
        currentCellX = getCellX();
        currentCellY = getCellY();
        emit updatePos(currentCellX, currentCellY);
    }
    }
}

