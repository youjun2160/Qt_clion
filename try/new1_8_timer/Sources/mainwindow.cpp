//
// Created by YUAN on 2024/5/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "MyButton.h"
#include <QPushButton>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    MyButton *myButton = new MyButton(this); // 使用this作为父窗口
    myButton->setText("Click me!"); // 可以设置按钮文本
    // 设置位置和大小，或者使用布局管理器
    myButton->setGeometry(QRect(QPoint(50, 50), QSize(200, 50)));

    // 将按钮添加到主窗口中
    //setCentralWidget(myButton);

    // 连接信号和槽（如果需要）
    connect(myButton, &QPushButton::clicked, this, &MainWindow::onMyButtonClicked);

    MyButton *myButton2 = new MyButton(this); // 使用this作为父窗口
    myButton2->move( 200, 100 );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onMyButtonClicked() {
    qDebug() << "Button clicked!";
}