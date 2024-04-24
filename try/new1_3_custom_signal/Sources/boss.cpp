//
// Created by YUAN on 2024/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Boss.h" resolved

#include "Headers/boss.h"


Boss::Boss(QString name, int exp, QWidget *parent) :
        QWidget(parent){

    this->name = name;
    this->exp = exp;
}

Boss::~Boss() {
}


void Boss::BossDead() {
    qDebug() << name << "已被击杀, 获得经验" << exp;
    emit BossDeads();
}


