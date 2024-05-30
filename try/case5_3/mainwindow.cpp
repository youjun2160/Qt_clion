#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建一个堆栈窗口
    stackedWidget = new QStackedWidget(this);

    //实例化窗口
    mainMenu = new MainMenu(this);
    reciteWords = new ReciteWords(this);
    reciteWrongWords = new ReciteWrongWords(this);
    Setting *setting = new Setting(this);
    search = new Search(this);


    //添加到堆栈窗口
    mainMenu->addToStack(stackedWidget);
    reciteWords->addToStack(stackedWidget);
    reciteWrongWords->addToStack(stackedWidget);
    search->addToStack(stackedWidget);
    setting->addToStack(stackedWidget);


    //设置堆栈窗口
    setCentralWidget(stackedWidget);

    //设置按钮连接
    mainMenu->connectBtn(stackedWidget, reciteWords, reciteWrongWords, setting, search);
    reciteWords->connectBtn(stackedWidget, mainMenu);
    reciteWrongWords->connectBtn(stackedWidget, mainMenu);
    search->connectBtn(stackedWidget, mainMenu);
    setting->connectBtn(stackedWidget, mainMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}
