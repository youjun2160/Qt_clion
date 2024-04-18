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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *btnSet;
    QLabel *label_Num;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(824, 595);
        btnSet = new QPushButton(MainWindow);
        btnSet->setObjectName("btnSet");
        btnSet->setGeometry(QRect(380, 170, 75, 24));
        label_Num = new QLabel(MainWindow);
        label_Num->setObjectName("label_Num");
        label_Num->setGeometry(QRect(180, 170, 54, 16));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnSet->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_Num->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
