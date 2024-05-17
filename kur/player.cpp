#include "player.h"

Player::Player(qint8 x, qint8 y, QGraphicsObject *parent) : Tank(x, y, parent) {
    QPixmap map(QDir::current().filePath("resources/player.jpg"));
    this->pixmap = map;
    shootTimer = new QTimer(this);
    shootTimer->setSingleShot(true);
    shootTimer->setInterval(1000);
    connect(shootTimer, &QTimer::timeout, this, &Player::shootTimerTimeout);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::moveTimerTimeout);
    timer->start(100);
    hp = maxhp;
    currentCellX = getCellX();
    currentCellY = getCellY();
    emit updatePos(currentCellX, currentCellY);
    // tickTimer = new QTimer();
    // connect(tickTimer, &QTimer::timeout, this, &Player::tick);
    // tickTimer->start(1);
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
    update();
}

// void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
//     // painter->setBrush(QColor(0,255,0));
//     // this->Tank::paint(painter, option, widget);
//     painter->drawRect(boundingRect());
    // QPixmap map(QDir::current().filePath("resources/player.png"));
//     painter->drawPixmap(boundingRect(), map, QRectF(0,0,38,38));
// }

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
        if(currentCellX != getCellX() || currentCellY != getCellY()){
        currentCellX = getCellX();
        currentCellY = getCellY();
        emit updatePos(currentCellX, currentCellY);
    }
    }
}

void Player::shootTimerTimeout(){
    this->isShootEnabled=true;
}
void Player::tick(){
    qDebug() << "playerTick";
}
