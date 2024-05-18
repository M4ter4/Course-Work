#include "enemy.h"

Enemy::Enemy(qint8 x, qint8 y, QGraphicsObject *parent) : Tank(x, y, parent) {
    QPixmap map(QDir::current().filePath("resources/enemy.jpg"));
    this->rotate(Square::RIGHT);
    this->pixmap = map;
    tickTimer = new QTimer();
    connect(tickTimer, &QTimer::timeout, this, &Enemy::tick);
        tickTimer->start(10);
}

Enemy::~Enemy(){}

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
        if(SteelWall *wall = dynamic_cast<SteelWall*>(item)){
            this->setPos(this->x() - stepSize*qCos(radians), this->y() - stepSize*qSin(radians));
        }
    }
}

void Enemy::onWallDestroy(QVector<QVector<bool> > *field)
{
    this->field = field;
}

void Enemy::onPlayerCellUpdate(qint8 x, qint8 y)
{
    Enemy::Point point;
    point.x = x;
    point.y = y;
    this->playerCell = point;
}

void Enemy::tick(){
    QList<Enemy*> enemies;
    foreach(auto item, scene()->items()) {
        if(Enemy *enemy = dynamic_cast<Enemy*>(item)){
            enemies.append(enemy);
        }
    }
    if(qRound64(x())%40 == 20 && qRound64(y())%40 == 20){
        Enemy::Point point;
        point.x = getCellX();
        point.y = getCellY();
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
    qint8 currentCellX = getCellX();
    qint8 currentCellY = getCellY();
    bool noObstacles = true;
    while(true){
        currentCellX += qRound(qCos(radians));
        currentCellY += qRound(qSin(radians));
        if(currentCellX < 0 || currentCellX > 19 || currentCellY < 0 || currentCellY > 19){
            break;
        }
        if(playerCell.x == currentCellX && playerCell.y == currentCellY && noObstacles){
            shoot(1);
        }
        foreach (auto enemy, enemies) {
            if(enemy->getCellX() == currentCellX && enemy->getCellY() == currentCellY){
                noObstacles = false;
            }
        }

        if (!(*field)[currentCellY][currentCellX]){
            noObstacles = false;
        }
    }
}

bool Enemy::isValidSquare(const QVector<QVector<bool>> &field, int x, int y)
{
    return x >= 0 && x < field.size() && y >= 0 && y < field[0].size() && (field[y][x] == true);
}

bool Enemy::isValidSquare(const QVector<QVector<bool> > &field, int x, int y, QList<Enemy *> enemies)
{
    foreach (auto enemy, enemies) {
        if (enemy->getCellX() == x && enemy->getCellY() == y){
            return false;
        }
    }
    return x >= 0 && x < field.size() && y >= 0 && y < field[0].size() && (field[y][x] == true);
}

Square::Direction Enemy::findShortestPath(const QVector<QVector<bool> > &field, Point start, Point end)
{


    // qDebug() << start.x << " -start-" << start.y;
    // qDebug() << end.x << " -end-" << end.y;
    QQueue<Point> queue;

    // Массив для хранения пройденных точек
    QVector<QVector<bool>> visited(field.size(), QVector<bool>(field[0].size(), false));

    // Массив для хранения предков каждой точки
    QVector<QVector<Point>> parents(field.size(), QVector<Point>(field[0].size(), {-1, -1}));

    // Добавляем начальную точку в очередь
    queue.append(start);
    visited[start.y][start.x] = true;
    // Пока очередь не пуста
    while (!queue.empty()) {
        // Извлекаем следующую точку из очереди
        Point current = queue.front();
        queue.pop_front();

        // Проверяем, достигли ли мы конечной точки
        if (current.x == end.x && current.y == end.y) {
            // Восстанавливаем кратчайший путь, двигаясь по предкам
            QVector<Point> path;

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
        }

        QVector<Point> neighbors = {
            {current.x - 1, current.y},
            {current.x + 1, current.y},
            {current.x, current.y - 1},
            {current.x, current.y + 1}
        };

        for (const Point& neighbor : neighbors) {
            if (isValidSquare(field, neighbor.x, neighbor.y) && !visited[neighbor.y][neighbor.x]) {
                queue.append(neighbor);
                visited[neighbor.y][neighbor.x] = true;
                parents[neighbor.y][neighbor.x] = current;
            }
        }
    }
    return Direction::NONE;
}

Square::Direction Enemy::findShortestPath(const QVector<QVector<bool> > &field, Point start, Point end, QList<Enemy *> enemies)
{
    QQueue<Point> queue;

    // Массив для хранения пройденных точек
    QVector<QVector<bool>> visited(field.size(), QVector<bool>(field[0].size(), false));

    // Массив для хранения предков каждой точки
    QVector<QVector<Point>> parents(field.size(), QVector<Point>(field[0].size(), {-1, -1}));

    // Добавляем начальную точку в очередь
    queue.append(start);
    visited[start.y][start.x] = true;
    // Пока очередь не пуста
    while (!queue.empty()) {
        // Извлекаем следующую точку из очереди
        Point current = queue.front();
        queue.pop_front();

        // Проверяем, достигли ли мы конечной точки
        if (current.x == end.x && current.y == end.y) {
            // Восстанавливаем кратчайший путь, двигаясь по предкам
            QVector<Point> path;

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
        QVector<Point> neighbors = {
            {current.x - 1, current.y},
            {current.x + 1, current.y},
            {current.x, current.y - 1},
            {current.x, current.y + 1}
        };

        for (const Point& neighbor : neighbors) {
            if (isValidSquare(field, neighbor.x, neighbor.y, enemies) && !visited[neighbor.y][neighbor.x]) {
                queue.append(neighbor);
                visited[neighbor.y][neighbor.x] = true;
                parents[neighbor.y][neighbor.x] = current;
            }
        }
    }
    return Direction::NONE;
}
