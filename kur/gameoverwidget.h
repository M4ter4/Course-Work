#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H

#include <QWidget>

namespace Ui {
class GameOverWidget;
}

class GameOverWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverWidget(QWidget *parent = nullptr);
    ~GameOverWidget();

private:
    Ui::GameOverWidget *ui;
};

#endif // GAMEOVERWIDGET_H
