//
// Created by YUAN on 2024/4/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SlotTest.h" resolved

#include "Headers/slottest.h"
#include <QPushButton>
#include <QLabel>


SlotTest::SlotTest(QWidget *parent) :
        QWidget(parent){
    resize(500,300);

    QPushButton *btnMax = new QPushButton(this);
    btnMax->setText("最大化");
    btnMax->move(400,0);
    connect(btnMax, &QPushButton::clicked, this, &QWidget::showMaximized);

    int num = 1, num2 = 2;
    void (*p)(int, int) = [](int a, int b) {
        printf("a + b = %d\n", a + b);
    };
    p(num, num2);

}

SlotTest::~SlotTest() {
}
