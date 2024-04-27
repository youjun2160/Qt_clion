//
// Created by YUAN on 2024/4/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent){
    setWindowTitle("主窗口");

    resize(500,400);

    //------------------菜单栏，主窗口中只存在一个------------------------
    QMenuBar *menuBar = new QMenuBar;
    this->setMenuBar(menuBar);
//    menuBar->addMenu("编辑")->addAction("部分");
//    menuBar->addMenu("文件");

    QMenu *menu = menuBar->addMenu("编辑");
    QAction *action = menu->addAction("新建");
    menu->addAction("打开");
    menuBar->addMenu("文件");


    //----------------------工具栏，可以存在多个----------------------------
    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(Qt::RightToolBarArea, toolBar);

    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);//设置允许防止的位置

    toolBar->addAction("编辑");
    toolBar->addSeparator();
    toolBar->addAction("打开");


    //------------------------状态栏,-----------------------------
    QStatusBar *status = statusBar();
    status->addAction(new QAction("FPS:60"));
    status->addWidget(new QPushButton("FPS:60"));
    status->addWidget(new QLabel("PIN:20"));
    status->addPermanentWidget(new QLabel("今天天气:晴"));
    this->setStatusBar(status);

    //---------------------------中心部件------------------------------
    this->setCentralWidget(new QTextEdit("请输入..."));

    //---------------------------衔接部件（浮动窗口）可以有多个-----------------------------
    QDockWidget *dock = new QDockWidget("文本一");
    this->addDockWidget(Qt::LeftDockWidgetArea, dock);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
}

MainWindow::~MainWindow() {
}
