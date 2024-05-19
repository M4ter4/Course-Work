/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "gameoverwidget.h"
#include "gamewidget.h"
#include "startwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    GameWidget *gameWidget;
    GameOverWidget *gameOverWidget;
    StartWidget *startWidget;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(400, 300);
        gameWidget = new GameWidget(MainWidget);
        gameWidget->setObjectName(QString::fromUtf8("gameWidget"));
        gameWidget->setGeometry(QRect(0, 0, 1200, 900));
        gameOverWidget = new GameOverWidget(MainWidget);
        gameOverWidget->setObjectName(QString::fromUtf8("gameOverWidget"));
        gameOverWidget->setGeometry(QRect(20, 10, 361, 271));
        startWidget = new StartWidget(MainWidget);
        startWidget->setObjectName(QString::fromUtf8("startWidget"));
        startWidget->setGeometry(QRect(19, 9, 361, 271));
        gameOverWidget->raise();
        gameWidget->raise();
        startWidget->raise();

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
