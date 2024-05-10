//
// Created by YUAN on 2024/5/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPoint>
#include <QToolButton>
#include "MyButton.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //将背景设为icon1.png
    ui->label->setStyleSheet("background-color: rgb(255, 255, 255);");

    ui->toolButton->setIcon(QIcon("../Sources/icon/icon2.png"));

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::test);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::test() {
    qDebug() << "Hello World!";
    ui->label->setStyleSheet("background-color: green;");
    ui->label->move(200,150);
}

//void MainWindow::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::LeftButton) {
//        ui->label->setStyleSheet("background-color: red;");
//        //打印鼠标点击的坐标
//        qDebug() << "x:" << event->position().x() << "y:" << event->position().y();
//    }
//}

void MainWindow::leaveEvent(QEvent *event) {
    qDebug() << "leave";
}

void MainWindow::enterEvent(QEvent *event) {
    qDebug() << "Enter";
}


void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_W:
            qDebug() << "向前移动";
            break;
        case Qt::Key_S:
            qDebug() << "向后移动";
            break;
        case Qt::Key_A:
            qDebug() << "向左移动";
            break;
        case Qt::Key_D:
            qDebug() << "向右移动";
            break;
        default:
            break;
    }
}

