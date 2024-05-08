//
// Created by YUAN on 2024/5/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //将背景设为icon1.png
    ui->label->setStyleSheet("background-color: rgb(255, 255, 255);");



    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::test);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::test() {
    qDebug() << "Hello World!";
    ui->label->setStyleSheet("background-color: green;");
}