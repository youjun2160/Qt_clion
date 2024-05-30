#ifndef PAGEBASE_H
#define PAGEBASE_H

#include <QWidget>
#include <QStackedWidget>

class PageBase : public QWidget
{
    Q_OBJECT
public:
    explicit PageBase(QWidget *parent = nullptr);

    //设定一个纯虚函数，要求每个页面添加到堆栈窗口
    virtual void addToStack(QStackedWidget *stackedWidget) = 0;

signals:
};

#endif // PAGEBASE_H
