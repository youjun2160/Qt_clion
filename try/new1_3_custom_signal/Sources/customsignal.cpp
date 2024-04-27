//
// Created by YUAN on 2024/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CustomSignal.h" resolved

#include "Headers/customsignal.h"
#include "Headers/boss.h"
#include <QPushButton>
#include <QDebug>


CustomSignal::CustomSignal(QWidget *parent) :
        QWidget(parent){

    QPushButton *button = new QPushButton("attack", this);
    button->move(100, 100);

    Boss *boss = new Boss("青蛇", 100, this);

    connect(button, &QPushButton::clicked, boss, &Boss::BossDead);

    connect(boss, &Boss::BossDeads, this, &CustomSignal::BossDeadBC);


    //信号连接信号测试，出发主动连接的信号会使被连接的信号会直接触发，如果有connect连接的槽函数，那么会触发这个槽函数
    QPushButton *btn2 = new QPushButton("信号连接信号测试", this);
    btn2->move(200,100);

    connect(btn2, &QPushButton::clicked, boss, &Boss::BossDeads);
}

CustomSignal::~CustomSignal() {
}


void CustomSignal::BossDeadBC() {
    qDebug() << "完成击杀, 获得经验";
}