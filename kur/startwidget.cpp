#include "startwidget.h"
#include "ui_startwidget.h"

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartWidget)
{
    ui->setupUi(this);
}

StartWidget::~StartWidget()
{
    delete ui;
}

void StartWidget::on_easyPushButton_clicked()
{
    emit startSignal(1);
}


void StartWidget::on_mediumPushButton_clicked()
{
    emit startSignal(2);
}


void StartWidget::on_hardPushButton_clicked()
{
    emit startSignal(3);
}

