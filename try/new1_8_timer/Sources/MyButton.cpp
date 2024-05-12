//
// Created by YUAN on 2024/5/11.
//

// MyButton.cpp

#include "MyButton.h"
#include <QMouseEvent>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent) {
    // 在这里设置按钮属性，例如文本，大小等
    setText("My Custom Button");
    // 你还可以在这里连接信号和槽


}


void MyButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton){
        mousePosition = event->pos();
    }

    qDebug() << "Button clicked!";
}


void MyButton::mouseMoveEvent(QMouseEvent *event) {
    QPoint delta = event->pos() - mousePosition;
    this->move(this->pos() + delta);
}