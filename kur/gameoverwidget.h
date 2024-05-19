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

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameOverWidget *ui;
signals:
    void restartGameSignal();
};

#endif // GAMEOVERWIDGET_H
