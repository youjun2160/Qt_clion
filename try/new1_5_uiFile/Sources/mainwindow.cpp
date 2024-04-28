//
// Created by YUAN on 2024/4/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include <QSlider>
#include <QProgressBar>
#include <QPushButton>
#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);

    //模态对话框
    connect(ui->btn1, &QPushButton::clicked, [this](){
        QDialog *dialog = new QDialog(this);
        dialog->resize(200,200);

        dialog->exec();
    });

    //非模态对话框
    connect(ui->btn2, &QPushButton::clicked, [this](){
        QDialog *dialog = new QDialog(this);
        dialog->resize(200,200);
        dialog->show();
        dialog->exec();
        dialog->setAttribute(Qt::WA_DeleteOnClose);
//        QDialog dialog(this);
//        dialog.resize(200, 200);
//        dialog.show();
//        dialog.exec();
    });

    //文件对话框
    connect(ui->FileBtn, &QPushButton::clicked, [this](){
       QString fileName = QFileDialog::getOpenFileName(this, "打开文本文件", "D:/");
       qDebug() << fileName;

       auto color = QColorDialog::getColor(Qt::blue, this, "文字颜色");
       ui->textEdit->setTextColor(color);
       ui->textEdit->setText("歪比巴布");
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
