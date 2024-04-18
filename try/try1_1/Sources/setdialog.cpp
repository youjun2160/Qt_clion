//
// Created by YUAN on 2024/4/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SetDialog.h" resolved

#include "setdialog.h"
#include "Forms/ui_SetDialog.h"


SetDialog::SetDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::SetDialog) {
    ui->setupUi(this);
}

SetDialog::~SetDialog() {
    delete ui;
}

void SetDialog::on_btnAdd_clicked() {
    static int value = 100;
    emit sig_addOne(++value);
}
