//
// Created by YUAN on 2024/5/10.
//

#include "MyButton.h"

#include <QMouseEvent>
#include <QPoint>
#include <QDebug>


MyButton::MyButton(QWidget *parent) : QToolButton(parent) {
}

void MyButton::mouseMoveEvent(QMouseEvent *event) {
    QPoint delta = event->pos() - mousePressPosition;
    this->move(this->pos() + delta);
}

void MyButton::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        mousePressPosition = event->pos();
        qDebug() << "x:" << mousePressPosition.x() << "y:" << mousePressPosition.y();
    }
}