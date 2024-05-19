#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "player.h"
#include "levelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = nullptr);
    ~GameWidget();

private slots:


    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // GAMEWIDGET_H
