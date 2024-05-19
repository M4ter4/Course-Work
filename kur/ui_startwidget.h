/********************************************************************************
** Form generated from reading UI file 'startwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWIDGET_H
#define UI_STARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *easyPushButton;
    QPushButton *mediumPushButton;
    QPushButton *hardPushButton;

    void setupUi(QWidget *StartWidget)
    {
        if (StartWidget->objectName().isEmpty())
            StartWidget->setObjectName(QString::fromUtf8("StartWidget"));
        StartWidget->resize(400, 300);
        verticalLayoutWidget = new QWidget(StartWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(150, 30, 101, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        easyPushButton = new QPushButton(verticalLayoutWidget);
        easyPushButton->setObjectName(QString::fromUtf8("easyPushButton"));

        verticalLayout->addWidget(easyPushButton);

        mediumPushButton = new QPushButton(verticalLayoutWidget);
        mediumPushButton->setObjectName(QString::fromUtf8("mediumPushButton"));

        verticalLayout->addWidget(mediumPushButton);

        hardPushButton = new QPushButton(verticalLayoutWidget);
        hardPushButton->setObjectName(QString::fromUtf8("hardPushButton"));

        verticalLayout->addWidget(hardPushButton);


        retranslateUi(StartWidget);

        QMetaObject::connectSlotsByName(StartWidget);
    } // setupUi

    void retranslateUi(QWidget *StartWidget)
    {
        StartWidget->setWindowTitle(QCoreApplication::translate("StartWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("StartWidget", "New Game", nullptr));
        easyPushButton->setText(QCoreApplication::translate("StartWidget", "Easy", nullptr));
        mediumPushButton->setText(QCoreApplication::translate("StartWidget", "Normal", nullptr));
        hardPushButton->setText(QCoreApplication::translate("StartWidget", "Hard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWidget: public Ui_StartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWIDGET_H
