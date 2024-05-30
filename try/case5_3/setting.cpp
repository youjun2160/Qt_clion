#include "setting.h"

Setting::Setting(QWidget *parrent) {}

//添加到堆栈窗口
void Setting::addToStack(QStackedWidget *stackedWidget)
{
    stackedWidget->addWidget(this);

    //设置窗口的背景
    QPalette palette;
    QPixmap pixmap(":/picture/Setting.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    //创建一个返回按钮
    backBtn = new QPushButton(this);
    backBtn->setGeometry(720, 20, 50, 50);
    backBtn->setFont(QFont("Microsoft FangSong", 20));
    backBtn->setText("返回");
    backBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //创建一个textBrowser
    textBrowser = new QTextBrowser(this);
    textBrowser->setGeometry(30, 30, 300, 200);
    textBrowser->setStyleSheet("boarder: 1px solid black;");
}

//设置按钮连接其他页面
void Setting::connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu) {
    connect(backBtn, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(mainMenu);});
}
