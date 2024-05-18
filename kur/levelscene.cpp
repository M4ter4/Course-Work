#include "levelscene.h"

LevelScene::LevelScene() {
    this->setBackgroundBrush(QBrush(Qt::black));

    field = new QVector<QVector<bool>>(20);

    for (QVector<bool>& row : *field) {
        row.fill(true, 20);
    }

    QFile file(QDir::current().filePath("resources/map1.txt"));
    file.open(QIODevice::ReadWrite);
    QTextStream s(&file);

    for (int i = 0; i < 20; ++i) {
        QString current = s.readLine();
        for (int j = 0; j < 20; ++j) {
            walls[i][j] = current.at(j).unicode() - '0';
        }
    }

    for (qint8 i = 0; i < 20; ++i) {
        for (qint8 j = 0; j < 20; ++j) {
            qint8 curr = walls[i][j];
            if(curr == 1){
                SteelWall* wall = new SteelWall(j,i);
                this->addItem(wall);
                (*field)[i][j] = false;
            }
            if(curr == 2){
                BrickWall* wall = new BrickWall(j,i);
                this->addItem(wall);
                (*field)[i][j] = false;
                connect(wall, &BrickWall::onDeath, this, &LevelScene::onWallDestroy);
            }
        }
    }

    Player* obj = new Player(0,0);
    player = obj;
    this->addItem(obj);
    obj->grabKeyboard();
    connect(obj, &Player::updatePos, this, &LevelScene::onPlayerChangeCell);

    Enemy *enemy1 = new Enemy(9,10);
    enemy1->onPlayerCellUpdate(10, 10);
    connect(this, &LevelScene::updatePlayerPos, enemy1, &Enemy::onPlayerCellUpdate);
    connect(this, &LevelScene::updateField, enemy1, &Enemy::onWallDestroy);
    this->addItem(enemy1);
    Enemy *enemy2 = new Enemy(8,10);
    enemy2->onPlayerCellUpdate(10, 10);
    connect(this, &LevelScene::updatePlayerPos, enemy2, &Enemy::onPlayerCellUpdate);
    connect(this, &LevelScene::updateField, enemy2, &Enemy::onWallDestroy);
    this->addItem(enemy2);
    Enemy *enemy3 = new Enemy(7,10);
    enemy3->onPlayerCellUpdate(10, 10);
    connect(this, &LevelScene::updatePlayerPos, enemy3, &Enemy::onPlayerCellUpdate);
    connect(this, &LevelScene::updateField, enemy3, &Enemy::onWallDestroy);
    this->addItem(enemy3);
    emit updateField(field);
}

LevelScene::~LevelScene(){}

QVector<Enemy> *LevelScene::getEnemies()
{
    return enemies;
}

Player* LevelScene::getPlayer()
{
    return player;
}

void LevelScene::onWallDestroy(qint8 x, qint8 y)
{
    (*field)[y][x] = true;
    emit updateField(field);
}

void LevelScene::onPlayerChangeCell(qint8 x, qint8 y)
{
    emit updatePlayerPos(x, y);
}
