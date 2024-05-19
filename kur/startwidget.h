#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>

namespace Ui {
class StartWidget;
}

class StartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();

private:
    Ui::StartWidget *ui;
signals:
    void startSignal(qint8 difficulty);
private slots:
    void on_easyPushButton_clicked();
    void on_mediumPushButton_clicked();
    void on_hardPushButton_clicked();
};

#endif // STARTWIDGET_H
