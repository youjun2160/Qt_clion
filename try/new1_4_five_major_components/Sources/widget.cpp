//
// Created by YUAN on 2024/4/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include "Headers/widget.h"
#include <QMenuBar>


Widget::Widget(QWidget *parent) :
        QWidget(parent) {
    setWindowTitle("widget窗口");
}

Widget::~Widget() {
}
