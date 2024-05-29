#include "maincd.h"

MainCD::MainCD(QWidget *parent)
    : QMainWindow{parent}
{
    //创建窗口
    main = new QWidget(this);

    //将页面添加到堆栈窗口
    //stackedWidget->addWidget(main);

    //设置main窗口的背景
//    palette = new QPalette();
//    QPixmap pixmap(":/picture/kunkun.png");
//    palette->setBrush(QPalette::Window, QBrush(pixmap));
//    main->setAutoFillBackground(true);
//    main->setPalette(palette);

    //创建按钮
    btn_reciteWords = new QPushButton("背单词", main);
    btn_reciteWrongWords = new QPushButton("背错单词", main);
    btn_wordsSet = new QPushButton("设置", main);
    btn_Exit = new QPushButton("退出", main);
    btn_search = new QPushButton("搜索", main);


    //设置按钮
    btn_reciteWords->setGeometry(130, 350, 200, 50);
    btn_reciteWrongWords->setGeometry(130, 400, 200, 50);
    btn_wordsSet->setGeometry(130, 450, 200, 50);
    btn_Exit->setGeometry(130, 500, 200, 50);

    btn_search->setGeometry(500, 450, 200, 50);

    //设置按钮字体样式
    btn_reciteWords->setFont(QFont("Microsoft FangSong", 17));
    btn_reciteWrongWords->setFont(QFont("Microsoft FangSong", 17));
    btn_wordsSet->setFont(QFont("Microsoft FangSong", 17));
    btn_Exit->setFont(QFont("Microsoft FangSong", 17));

    btn_search->setFont(QFont("Microsoft FangSong", 17));

    //鼠标指针悬在按钮上，字体变大
    btn_reciteWords->setStyleSheet("QPushButton {"
                                   "   border: none;" // 移除边框
                                   "   color: Black;" // 字体颜色
                                   "   background-color: transparent;" // 透明背景
                                   "}"
                                   "QPushButton:hover {"
                                   "   font-size: 21pt;" // 字体放大效果
                                   "   color: Blue;" // 可以根据需要更改颜色
                                   "}"
                                   "QPushButton:pressed {"
                                   "   font-size: 19pt;"// 字体稍小一点
                                   "   color: green;" // 可以根据需要更改颜色
                                   "}");

    btn_reciteWrongWords->setStyleSheet("QPushButton {"
                                        "   color: Black;" // 字体颜色
                                        "   background-color: transparent;" // 透明背景
                                        "}"
                                        "QPushButton:hover {"
                                        "   font-size: 21pt;" // 字体放大效果
                                        "   color: Blue;" // 可以根据需要更改颜色
                                        "}"
                                        "QPushButton:pressed {"
                                        "   font-size: 19pt;"// 字体稍小一点
                                        "   color: green;" // 可以根据需要更改颜色
                                        "}");

    btn_wordsSet->setStyleSheet("QPushButton {"
                                "   color: Black;" // 字体颜色
                                "   background-color: transparent;" // 透明背景
                                "}"
                                "QPushButton:hover {"
                                "   font-size: 21pt;" // 字体放大效果
                                "   color: Blue;" // 可以根据需要更改颜色
                                "}"
                                "QPushButton:pressed {"
                                "   font-size: 19pt;"// 字体稍小一点
                                "   color: green;" // 可以根据需要更改颜色
                                "}");

    btn_Exit->setStyleSheet("QPushButton {"
                            "   color: Black;" // 字体颜色
                            "   background-color: transparent;" // 透明背景
                            "}"
                            "QPushButton:hover {"
                            "   font-size: 21pt;" // 字体放大效果
                            "   color: Blue;" // 可以根据需要更改颜色
                            "}"
                            "QPushButton:pressed {"
                            "   font-size: 19pt;"// 字体稍小一点
                            "   color: green;" // 可以根据需要更改颜色
                            "}");

    //鼠标指针悬在按钮上，字体变大
    btn_search->setStyleSheet("QPushButton {"
                              "   color: Black;" // 字体颜色
                              "   background-color: transparent;" // 透明背景
                              "}"
                              "QPushButton:hover {"
                              "   font-size: 21pt;" // 字体放大效果
                              "   color: Blue;" // 可以根据需要更改颜色
                              "}"
                              "QPushButton:pressed {"
                              "   font-size: 19pt;"// 字体稍小一点
                              "   color: green;" // 可以根据需要更改颜色
                              "}");

    //切换窗口
//    connect(btn_reciteWords, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(reciteWords);});
//    connect(btn_reciteWrongWords, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(reciteWrongWords);});
//    connect(btn_wordsSet, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(wordsSet);});
//    connect(btn_Exit, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(main);});
//    connect(btn_search, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(search);});
}
