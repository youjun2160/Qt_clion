//
// Created by YUAN on 2024/4/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SetDialog.h" resolved

#include "setdialog.h"
#include "ui_SetDialog.h"


SetDialog::SetDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::SetDialog) {
    ui->setupUi(this);
}

SetDialog::~SetDialog() {
    delete ui;
}
