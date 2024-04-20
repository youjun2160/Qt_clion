//
// Created by YUAN on 2024/4/20.
//

#ifndef TRY_EMIT_SIGNAL_TO_UI_WIDGET_H
#define TRY_EMIT_SIGNAL_TO_UI_WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:
    Ui::Widget *ui;
};


#endif //TRY_EMIT_SIGNAL_TO_UI_WIDGET_H
