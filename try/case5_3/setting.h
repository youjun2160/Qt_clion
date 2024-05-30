#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include "pagebase.h"
#include "mainmenu.h"
#include <QPushButton>
#include <QTextBrowser>
#include <QLineEdit>

class Setting : public PageBase
{
    Q_OBJECT
public:
    Setting(QWidget *parent = nullptr);

    //添加到堆栈窗口
    virtual void addToStack(QStackedWidget *stackedWidget) override;

    //创建一个返回按钮
    QPushButton *backBtn;

    //设置按钮连接其他页面
    void connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu);

    //创建一个textBrowser
    QTextBrowser *textBrowser;

    //创建一个lineEdit
    QLineEdit *lineEdit;

    //创建三个按钮,分别是查看全部单词本，查看错词本，删除错词本中的单词
    QPushButton *allWordBookBtn;
    QPushButton *wrongWordBookBtn;
    QPushButton *deleteWordBookBtn;
};

#endif // SETTING_H
