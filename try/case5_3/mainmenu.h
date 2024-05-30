#ifndef MAINMENU_H
#define MAINMENU_H

#include "pagebase.h"
#include <QPushButton>
#include <QStackedWidget>

class MainMenu : public PageBase
{
    Q_OBJECT
public:
    MainMenu(QWidget *parent = nullptr);

    //添加到堆栈窗口
    void addToStack(QStackedWidget *stackedWidget) override;

    //创建按钮
    QPushButton *btn_reciteWords;
    QPushButton *btn_reciteWrongWords;
    QPushButton *btn_wordsSet;
    QPushButton *btn_Exit;
    QPushButton *btn_search;

    //按钮连接其他页面
    void connectBtn(QStackedWidget *stackedWidget, QWidget *reciteWords, QWidget *reciteWrongWords, QWidget *wordsSet,QWidget *search);
};

#endif // MAINMENU_H
