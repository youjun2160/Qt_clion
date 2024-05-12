//
// Created by YUAN on 2024/5/11.
//

#ifndef NEW1_8_TIMER_MYBUTTON_H
#define NEW1_8_TIMER_MYBUTTON_H


#include <QPushButton>

class MyButton : public QPushButton {
Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    // 可以添加你自己的方法和属性

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint mousePosition;
};


#endif //NEW1_8_TIMER_MYBUTTON_H
