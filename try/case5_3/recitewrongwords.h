#ifndef RECITEWRONGWORDS_H
#define RECITEWRONGWORDS_H

#include <QWidget>
#include "pagebase.h"
#include "mainmenu.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <random>
#include <vector>
#include <QFile>
#include <chrono>
#include <algorithm>
#include <QDebug>

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


    //按钮状态,当true时，从全部单词中随机抽取一个，当false时，检查用户输入是否正确
    bool btnState = true;

    //创建一个要背单词的容器
    std::vector<QString> words;
    //当前读取到第几个单词
    int index = 0;
    //是否已被打乱
    bool shuffled = false;
    //总单词数
    int total;

    //背单词
    void reciteWord();
};

#endif // RECITEWRONGWORDS_H
