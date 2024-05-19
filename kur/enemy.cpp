#include "enemy.h"

Enemy::Enemy(qint8 x, qint8 y, QGraphicsObject *parent) : Tank(x, y, parent) {
    QPixmap map(QDir::current().filePath("resources/enemy.png"));
    this->rotate(Square::RIGHT);
    this->pixmap = map;
    tickTimer = new QTimer();
    connect(tickTimer, &QTimer::timeout, this, &Enemy::tick);
        tickTimer->start(10);
}

Enemy::~Enemy(){}

void Enemy::takeDamage(qint8 damage)
{
    Tank::takeDamage(damage);
    if (hp <= 0){
        emit enemyDeathSignal();
    }
}

void Enemy::move(qint64 stepSize)
{
    Tank::move(stepSize);
    double radians = qDegreesToRadians((double)direction);
    foreach(auto item, scene()->collidingItems(this)){
        if(Enemy *enemy = dynamic_cast<Enemy*>(item)){
            turnTo = getOpposite(direction);
            if (turnTo != direction){
                rotate(turnTo);
                direction = turnTo;
            }
        }
        if(Tank *tank = dynamic_cast<Tank*>(item)){
            this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
        }
        else if(SteelWall *wall = dynamic_cast<SteelWall*>(item)){
            this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
        }
    }
}

void Enemy::onWallDestroy(QVector<QVector<bool> > *field)
{
    this->field = field;
}

void Enemy::onPlayerCellUpdate(Cell cell)
{
    this->playerCell = cell;
}

void Enemy::tick(){
    QList<Enemy*> enemies;
    foreach(auto item, scene()->items()) {
        if(Enemy *enemy = dynamic_cast<Enemy*>(item)){
            enemies.append(enemy);
        }
    }
    if(qRound64(x())%40 == 20 && qRound64(y())%40 == 20){
        Square::Cell point(getCell().x, getCell().y);
        turnTo = findShortestPath(*field, point, playerCell, enemies);
        if (turnTo == NONE){
            turnTo = findShortestPath(*field, point, playerCell);
        }
        if (turnTo != direction){
            rotate(turnTo);
            direction = turnTo;
        }
    }
    move(stepSize);
    double radians = qDegreesToRadians((double)direction);
    Square::Cell currentCell = getCell();
    bool noObstacles = true;
    while(true){
        currentCell.x += qRound(qCos(radians));
        currentCell.y += qRound(qSin(radians));
        if(currentCell.x < 0 || currentCell.x > 19 || currentCell.y < 0 || currentCell.y > 19){
            break;
        }
        if(playerCell.x == currentCell.x && playerCell.y == currentCell.y && noObstacles){
            shoot();
        }
        foreach (auto enemy, enemies) {
            if(enemy->getCell().x == currentCell.x && enemy->getCell().y == currentCell.y){
                noObstacles = false;
            }
        }

        if (!(*field)[currentCell.y][currentCell.x]){
            noObstacles = false;
        }
    }
}

bool Enemy::isValidSquare(const QVector<QVector<bool>> &field, Square::Cell cell)
{
    return cell.x >= 0 && cell.x < field.size() && cell.y >= 0 && cell.y < field[0].size() && (field[cell.y][cell.x] == true);
}

bool Enemy::isValidSquare(const QVector<QVector<bool> > &field, Square::Cell cell, QList<Enemy *> enemies)
{
    foreach (auto enemy, enemies) {
        if (enemy->getCell().x == cell.x && enemy->getCell().y == cell.y){
            return false;
        }
    }
    return isValidSquare(field, cell);
}

Square::Direction Enemy::findShortestPath(const QVector<QVector<bool> > &field,Square::Cell start, Square::Cell end)
{
    QQueue<Square::Cell> queue;

    QVector<QVector<bool>> visited(field.size(), QVector<bool>(field[0].size(), false));

    QVector<QVector<Square::Cell>> parents(field.size(), QVector<Square::Cell>(field[0].size(), {-1, -1}));

    queue.append(start);
    visited[start.y][start.x] = true;
    while (!queue.empty()) {
        Square::Cell current = queue.front();
        queue.pop_front();

        if (current.x == end.x && current.y == end.y) {
            QVector<Square::Cell> path;

            while (current.x != -1 && current.y != -1) {
                path.push_back(current);
                current = parents[current.y][current.x];
            }

            std::reverse(path.begin(), path.end());
            if(path.size() == 1){
                return this->direction;
            }
            if(path[0].x == path[1].x){
                return ((path[1].y > path[0].y) ? DOWN : UP);
            }
            else{
                return ((path[1].x > path[0].x) ? RIGHT : LEFT);
            }
        }

        QVector<Square::Cell> neighbors = {
            {current.x - 1, current.y},
            {current.x + 1, current.y},
            {current.x, current.y - 1},
            {current.x, current.y + 1}
        };

        for (const Square::Cell& neighbor : neighbors) {
            if (isValidSquare(field, neighbor) && !visited[neighbor.y][neighbor.x]) {
                queue.append(neighbor);
                visited[neighbor.y][neighbor.x] = true;
                parents[neighbor.y][neighbor.x] = current;
            }
        }
    }
    return Direction::NONE;
}

Square::Direction Enemy::findShortestPath(const QVector<QVector<bool> > &field, Square::Cell start, Square::Cell end, QList<Enemy *> enemies)
{
    QQueue<Square::Cell> queue;

    // Массив для хранения пройденных точек
    QVector<QVector<bool>> visited(field.size(), QVector<bool>(field[0].size(), false));

    // Массив для хранения предков каждой точки
    QVector<QVector<Square::Cell>> parents(field.size(), QVector<Square::Cell>(field[0].size(), {-1, -1}));

    // Добавляем начальную точку в очередь
    queue.append(start);
    visited[start.y][start.x] = true;
    // Пока очередь не пуста
    while (!queue.empty()) {
        // Извлекаем следующую точку из очереди
        Square::Cell current = queue.front();
        queue.pop_front();

        // Проверяем, достигли ли мы конечной точки
        if (current.x == end.x && current.y == end.y) {
            // Восстанавливаем кратчайший путь, двигаясь по предкам
            QVector<Square::Cell> path;

            while (current.x != -1 && current.y != -1) {
                path.push_back(current);
                current = parents[current.y][current.x];
            }

            // Возвращаем массив точек, составляющих кратчайший путь
            std::reverse(path.begin(), path.end());
            if(path.size() == 1){
                return this->direction;
            }
            if(path[0].x == path[1].x){
                return ((path[1].y > path[0].y) ? DOWN : UP);
            }
            else{
                return ((path[1].x > path[0].x) ? RIGHT : LEFT);
            }
            //return path;
        }

        // Иначе добавляем в очередь соседние точки
        QVector<Square::Cell> neighbors = {
            {current.x - 1, current.y},
            {current.x + 1, current.y},
            {current.x, current.y - 1},
            {current.x, current.y + 1}
        };

        for (const Square::Cell& neighbor : neighbors) {
            if (isValidSquare(field, neighbor, enemies) && !visited[neighbor.y][neighbor.x]) {
                queue.append(neighbor);
                visited[neighbor.y][neighbor.x] = true;
                parents[neighbor.y][neighbor.x] = current;
            }
        }
    }
    return Direction::NONE;
}
