#include "gamewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWidget w;
    w.setFixedSize(1200,900);
    w.show();

    return a.exec();
}
