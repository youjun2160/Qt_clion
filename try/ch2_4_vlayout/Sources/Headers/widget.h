//
// Created by YUAN on 2024/4/20.
//

#ifndef CH2_4_VLAYOUT_WIDGET_H
#define CH2_4_VLAYOUT_WIDGET_H

#include <QWidget>



class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:

};


#endif //CH2_4_VLAYOUT_WIDGET_H
