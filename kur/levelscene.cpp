#include "levelscene.h"

LevelScene::LevelScene() {
    this->setBackgroundBrush(QBrush(Qt::black));

    field = new QVector<QVector<bool>>(20);

    // Заполняем каждый внутренний QVector значениями true
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
                qDebug() << "steel";
                SteelWall* wall = new SteelWall(j,i);
                this->addItem(wall);
                (*field)[i][j] = false;
            }
            if(curr == 2){
                qDebug() << "brick";
                BrickWall* wall = new BrickWall(j,i);
                this->addItem(wall);
                (*field)[i][j] = false;
                connect(wall, &BrickWall::onDeath, this, &LevelScene::onWallDestroy);
            }
        }
    }


    Player* obj = new Player(10,10);
    player = obj;
    this->addItem(obj);
    obj->grabKeyboard();
    connect(obj, &Player::updatePos, this, &LevelScene::onPlayerChangeCell);


    Enemy *enemy = new Enemy(2,2);
    connect(this, &LevelScene::updatePlayerPos, enemy, &Enemy::onPlayerCellUpdate);
    connect(this, &LevelScene::updateField, enemy, &Enemy::onWallDestroy);
    this->addItem(enemy);
    emit updateField(field);


}

LevelScene::~LevelScene(){}

QVector<QVector<bool>> *LevelScene::getField()
{
    return field;
}

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
    (*field)[y][x] = false;
    emit updateField(field);
}

void LevelScene::onPlayerChangeCell(qint8 x, qint8 y)
{
    emit updatePlayerPos(x, y);
}
