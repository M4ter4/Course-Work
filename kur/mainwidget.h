#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void startNewGameSlot(qint8 difficulty);
    void gameOverSlot();
    void restartSlot();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
