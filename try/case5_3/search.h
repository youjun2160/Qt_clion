#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include "pagebase.h"
#include "mainmenu.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFile>
#include <QDebug>

class Search : public PageBase
{
    Q_OBJECT
public:
    Search(QWidget *parent = nullptr);

    //添加到堆栈窗口
    virtual void addToStack(QStackedWidget *stackedWidget) override;

    //创建一个返回按钮
    QPushButton *backBtn;

    //设置按钮连接其他页面
    void connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu);

    //创建5个Label标签,分别对应单词的汉译，原型，复数形式，过去式，过去分词
    QLabel *label_chinese;
    QLabel *label_yuanxing;
    QLabel *label_fushu;
    QLabel *label_guoqu;
    QLabel *label_guoqufenci;

    //创建一个line edit用来作为用户输入框
    QLineEdit *lineEdit;

    //创建一个按钮
    QPushButton *searchBtn;

    //创建6个文本，分别用来表示不同信息
    QString chinese;
    QString yuanxing;
    QString fushu;
    QString guoqu;
    QString guoqufenci;

    QString UserInput;

    //执行搜索
    void search();
};

#endif // SEARCH_H
