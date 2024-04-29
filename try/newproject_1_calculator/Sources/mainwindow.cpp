//
// Created by YUAN on 2024/4/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "Headers/mainwindow.h"
#include "Forms/ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    

    ui->label->clear();

    //数字
    connect(ui->btn0, &QPushButton::clicked, [this](){ OnClicked(Num, "0");});
    connect(ui->btn1, &QPushButton::clicked, [this](){ OnClicked(Num, "1");});
    connect(ui->btn2, &QPushButton::clicked, [this](){ OnClicked(Num, "2");});
    connect(ui->btn3, &QPushButton::clicked, [this](){ OnClicked(Num, "3");});
    connect(ui->btn4, &QPushButton::clicked, [this](){ OnClicked(Num, "4");});
    connect(ui->btn5, &QPushButton::clicked, [this](){ OnClicked(Num, "5");});
    connect(ui->btn6, &QPushButton::clicked, [this](){ OnClicked(Num, "6");});
    connect(ui->btn7, &QPushButton::clicked, [this](){ OnClicked(Num, "7");});
    connect(ui->btn8, &QPushButton::clicked, [this](){ OnClicked(Num, "8");});
    connect(ui->btn9, &QPushButton::clicked, [this](){ OnClicked(Num, "9");});

    //运算符
    connect(ui->btn_add, &QPushButton::clicked, [this](){ OnClicked(op, "+");});
    connect(ui->btn_subtract, &QPushButton::clicked, [this](){ OnClicked(op, "-");});
    connect(ui->btn_multiply, &QPushButton::clicked, [this](){ OnClicked(op, "*");});
    connect(ui->btn_divide, &QPushButton::clicked, [this](){ OnClicked(op, "/");});

    //其他
    connect(ui->btn_ac, &QPushButton::clicked, [this](){ OnClicked(ac, "ac");});
    connect(ui->btn_deleate, &QPushButton::clicked, [this](){ OnClicked(deleate, "deleate");});
    connect(ui->btn_point, &QPushButton::clicked, [this](){ OnClicked(point, ".");});
    connect(ui->btn_result, &QPushButton::clicked, [this](){ OnClicked(equal, "=");});
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::OnClicked(BtnType type, QString num) {}