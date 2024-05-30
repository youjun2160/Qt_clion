#ifndef RECITEWRONGWORDS_H
#define RECITEWRONGWORDS_H

#include <QWidget>
#include "pagebase.h"
#include "mainmenu.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class ReciteWrongWords : public PageBase
{
    Q_OBJECT
public:
    ReciteWrongWords(QWidget *parent = nullptr);

    //添加到堆栈窗口
    virtual void addToStack(QStackedWidget *stackedWidget) override;

    //创建6个Label标签,分别对应单词的汉译，原型，复数形式，过去式，过去分词, 以及当前单词
    QLabel *label_currentWord;
    QLabel *label_chinese;
    QLabel *label_yuanxing;
    QLabel *label_fushu;
    QLabel *label_guoqu;
    QLabel *label_guoqufenci;

    //创建一个line edit用来作为用户输入框
    QLineEdit *lineEdit;

    //创建一个确认按钮
    QPushButton *confirmBtn;

    //创建一个返回按钮
    QPushButton *backBtn;

    //设置按钮连接其他页面
    void connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu);


    //创建7个文本，分别用来接收不同信息
    QString chinese;
    QString yuanxing;
    QString fushu;
    QString guoqu;
    QString guoqufenci;
    QString currentWord;

    QString userInput;
};

#endif // RECITEWRONGWORDS_H
