#include "enemy.h"

Enemy::Enemy(qint8 x, qint8 y, QGraphicsObject *parent) : Tank(x, y, parent) {
    QPixmap map(QDir::current().filePath("resources/enemy.jpg"));
    this->rotate(Square::RIGHT);
    this->pixmap = map;
    tickTimer = new QTimer();
    connect(tickTimer, &QTimer::timeout, this, &Enemy::tick);
        tickTimer->start(300);
}

Enemy::~Enemy(){}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(QColor(0,255,0));
    this->Tank::paint(painter, option, widget);
}

void Enemy::onWallDestroy(QVector<QVector<bool> > *field)
{
    this->field = field;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (!((*field)[j][i])){
                qDebug() << j << " - " << i;
            }
        }
    }
}

void Enemy::onPlayerCellUpdate(qint8 x, qint8 y)
{
    Enemy::Point point;
    point.x = x;
    point.y = y;
    this->playerCell = point;
}

void Enemy::tick(){
    // qDebug() << x() << " - " << y();
    // qDebug() << " - ";
    // qDebug() << qRound64(x()) << " - " << qRound64(y());
    if(qRound64(x())%40 == 20 && qRound64(y())%40 == 20){
        Enemy::Point point;
        point.x = getCellX();
        point.y = getCellY();
        turnTo = findShortestPath(*field, point, playerCell);
        if (turnTo != direction){
            rotate(turnTo);
            direction = turnTo;
        }
    }
    //shoot(1);
    move();
}

bool Enemy::isValidSquare(const QVector<QVector<bool>> &field, int x, int y)
{
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
            if (isValidSquare(field, neighbor.x, neighbor.y) && !visited[neighbor.y][neighbor.x]) {
                queue.append(neighbor);
                visited[neighbor.y][neighbor.x] = true;
                parents[neighbor.y][neighbor.x] = current;
            }
        }
    }

    // Если кратчайший путь не найден, возвращаем пустой массив
    return Direction::NONE;
}
