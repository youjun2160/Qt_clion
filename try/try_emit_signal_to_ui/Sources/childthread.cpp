//
// Created by YUAN on 2024/4/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChildThread.h" resolved

#include "childthread.h"
#include "ui_ChildThread.h"


ChildThread::ChildThread(QWidget *parent) :
        QThread(parent), ui(new Ui::ChildThread) {
    ui->setupUi(this);
}

ChildThread::~ChildThread() {
    delete ui;
}
