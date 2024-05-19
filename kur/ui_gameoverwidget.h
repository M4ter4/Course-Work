/********************************************************************************
** Form generated from reading UI file 'gameoverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERWIDGET_H
#define UI_GAMEOVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOverWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *GameOverWidget)
    {
        if (GameOverWidget->objectName().isEmpty())
            GameOverWidget->setObjectName(QString::fromUtf8("GameOverWidget"));
        GameOverWidget->resize(400, 300);
        verticalLayoutWidget = new QWidget(GameOverWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 30, 93, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(GameOverWidget);

        QMetaObject::connectSlotsByName(GameOverWidget);
    } // setupUi

    void retranslateUi(QWidget *GameOverWidget)
    {
        GameOverWidget->setWindowTitle(QCoreApplication::translate("GameOverWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("GameOverWidget", "Game Over", nullptr));
        pushButton->setText(QCoreApplication::translate("GameOverWidget", "Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverWidget: public Ui_GameOverWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERWIDGET_H
