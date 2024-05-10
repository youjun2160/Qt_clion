/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QToolButton *toolButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(672, 591);
        label = new QLabel(MainWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 180, 61, 61));
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 330, 75, 24));
        toolButton = new QToolButton(MainWindow);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(300, 410, 71, 80));
        toolButton->setMinimumSize(QSize(71, 80));
        toolButton->setMaximumSize(QSize(71, 80));
        toolButton->setIconSize(QSize(71, 80));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\214\211\351\222\256", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
