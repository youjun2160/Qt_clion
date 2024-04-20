//
// Created by YUAN on 2024/4/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoginWindow.h" resolved

#include "Headers/loginwindow.h"
#include "Forms/ui_LoginWindow.h"



LoginWindow::LoginWindow(QWidget *parent) :
        QDialog(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
}

LoginWindow::~LoginWindow() {
    delete ui;
}
