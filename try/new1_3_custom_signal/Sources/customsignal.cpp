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
}

CustomSignal::~CustomSignal() {
}


void CustomSignal::BossDeadBC() {
    qDebug() << "完成击杀, 获得经验";
}