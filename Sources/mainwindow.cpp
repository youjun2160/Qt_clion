//
// Created by YUAN on 2024/4/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include "Forms/ui_MainWindow.h"

#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->Label_image->clear();

    connect(ui->pushButton_open, &QPushButton::clicked, this, &MainWindow::openImage);
}

void MainWindow::openImage() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "C:/", tr("Image Files (*.png *.jpg)"));

    if(fileName.isEmpty()) {
        return;
    }

    ui->lineEdit_path->setText(fileName);
    ui->Label_image->setPixmap(QPixmap(fileName));
}

MainWindow::~MainWindow() {
    delete ui;
}
