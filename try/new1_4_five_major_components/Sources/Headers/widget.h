//
// Created by YUAN on 2024/4/27.
//

#ifndef NEW1_4_FIVE_MAJOR_COMPONENTS_WIDGET_H
#define NEW1_4_FIVE_MAJOR_COMPONENTS_WIDGET_H

#include <QWidget>

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:
};


#endif //NEW1_4_FIVE_MAJOR_COMPONENTS_WIDGET_H
