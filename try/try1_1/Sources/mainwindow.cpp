//
// Created by YUAN on 2024/4/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "setdialog.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

}

void MainWindow::on_btnSet_clicked() {
    SetDialog dlg;

    connect(&dlg, &SetDialog::sig_addOne, [=](int value){
        ui->label_Num->setText(QString::number(value));
    });

    dlg.exec();
}

MainWindow::~MainWindow() {
    delete ui;
}
