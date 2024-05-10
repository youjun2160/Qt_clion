//
// Created by YUAN on 2024/5/10.
//

#ifndef NEW1_7_EVENTS_MYBUTTON_H
#define NEW1_7_EVENTS_MYBUTTON_H


#include <QToolButton>
#include <QWidget>


class MyButton : public QToolButton {
Q_OBJECT

public:
    explicit MyButton(QWidget *parent = nullptr);

public:
    void mouseMoveEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    QPoint mousePressPosition;


};


#endif //NEW1_7_EVENTS_MYBUTTON_H
