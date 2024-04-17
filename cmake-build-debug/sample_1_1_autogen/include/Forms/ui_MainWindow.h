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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_open;
    QLabel *Label_image;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(875, 661);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, 20, 20, 20);
        label = new QLabel(MainWindow);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_path = new QLineEdit(MainWindow);
        lineEdit_path->setObjectName("lineEdit_path");

        horizontalLayout->addWidget(lineEdit_path);

        pushButton_open = new QPushButton(MainWindow);
        pushButton_open->setObjectName("pushButton_open");

        horizontalLayout->addWidget(pushButton_open);


        verticalLayout->addLayout(horizontalLayout);

        Label_image = new QLabel(MainWindow);
        Label_image->setObjectName("Label_image");

        verticalLayout->addWidget(Label_image);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        Label_image->setText(QCoreApplication::translate("MainWindow", "Label_image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
