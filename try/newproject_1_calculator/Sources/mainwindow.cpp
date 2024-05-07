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

    ui->btn_result->setStyleSheet("QPushButton:hover {background-color: rgb(67, 143, 192);}");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::OnClicked(BtnType type, QString num) {
    switch (type) {
        case Num:
            if(OP.isEmpty()){
                NUM1 += num;
            } else {
                NUM2 += num;
            }
            break;
        case op:
            //如果此时已经运算出结果并且没有清空，那么就将结果作为第一个数字
            if(!RESULT.isEmpty()){
                NUM1 = RESULT;
                NUM2.clear();
                OP.clear();
                RESULT.clear();
            }//如果此时NUM1，NUM2和OP都已经被填入，那么再次输入符号，就直接进行运算，并将结果作为第一个数字
            else if(!NUM1.isEmpty() && !NUM2.isEmpty() && !OP.isEmpty()){
                double num1 = NUM1.toDouble();
                double num2 = NUM2.toDouble();
                if(OP == "+"){
                    RESULT = QString::number(num1 + num2);
                } else if(OP == "-"){
                    RESULT = QString::number(num1 - num2);
                } else if(OP == "*"){
                    RESULT = QString::number(num1 * num2);
                } else if(OP == "/"){
                    if(num2 == 0){
                        RESULT = "除数不能为0";
                        break;
                    }
                    RESULT = QString::number(num1 / num2);
                }
                NUM1 = RESULT;
                NUM2.clear();
                RESULT.clear();
            } else if(!OP.isEmpty()){
                break;
            }
            OP = num;
            break;
        case point:
            if(OP.isEmpty()){
                if(!NUM1.contains(".") && !NUM1.isEmpty()){
                    NUM1 += num;
                }
            } else {
                if(!NUM2.contains(".") && !NUM2.isEmpty()){
                    NUM2 += num;
                }
            }
            break;
        case ac:
            NUM1.clear();
            NUM2.clear();
            OP.clear();
            RESULT.clear();
            break;
        case deleate:
            if(!RESULT.isEmpty()){
                RESULT.chop(1);
            } else if(!OP.isEmpty() && !NUM1.isEmpty() && !NUM2.isEmpty()){
                NUM2.chop(1);
            } else if(!OP.isEmpty() && !NUM1.isEmpty()){
                OP.chop(1);
            } else if(!NUM1.isEmpty()){
                NUM1.chop(1);
            }
            break;
        case equal:
            //当输入的算式不完整时，不进行运算
            if(NUM1.isEmpty() || NUM2.isEmpty() || OP.isEmpty()){
                break;
            }
            double num1 = NUM1.toDouble();
            double num2 = NUM2.toDouble();
            if(OP == "+"){
                RESULT = QString::number(num1 + num2);
            } else if(OP == "-"){
                RESULT = QString::number(num1 - num2);
            } else if(OP == "*"){
                RESULT = QString::number(num1 * num2);
            } else if(OP == "/"){
                if(num2 == 0){
                    RESULT = "除数不能为0";
                    break;
                }
                RESULT = QString::number(num1 / num2);
            }
            break;
    }

    //更新显示
    if(!RESULT.isEmpty()){
        ui->label->setText(RESULT);
    } else {
        ui->label->setText(NUM1 + OP + NUM2);
    }
}