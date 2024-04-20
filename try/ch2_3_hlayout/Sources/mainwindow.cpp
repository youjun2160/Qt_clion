//
// Created by YUAN on 2024/4/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent){

    resize(500, 500);

    QLabel* pPath = new QLabel(this);
    pPath->objectName() = "pPath";
    //pPath->setFixedSize(40, 32);
    pPath->setText(u8"路径");

    QLineEdit* pLineEdit = new QLineEdit(this);
    pLineEdit->objectName() = "pEdit";
    //pLineEdit->setFixedSize(200, 32);

    QPushButton* pButton = new QPushButton(this);
    pButton->objectName() = "pButton";
    //pButton->setFixedSize(50, 32);
    pButton->setText(u8"打开");

    QHBoxLayout *PHLay = new QHBoxLayout(this);
    PHLay->addWidget(pPath);
    PHLay->addStretch();
    PHLay->addWidget(pLineEdit);
    PHLay->setSpacing(50);
    PHLay->addSpacing(10);
    PHLay->addWidget(pButton);
}

MainWindow::~MainWindow() {

}
