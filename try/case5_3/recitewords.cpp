#include "recitewords.h"

ReciteWords::ReciteWords(QWidget *parrent) {

    //设置窗口的背景
    QPalette palette;
    QPixmap pixmap(":/picture/reciteWords.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    //创建标签
    label_currentWord = new QLabel(this);
    label_chinese = new QLabel(this);
    label_yuanxing = new QLabel(this);
    label_fushu = new QLabel(this);
    label_guoqu = new QLabel(this);
    label_guoqufenci = new QLabel(this);

    //设置标签
    label_currentWord->setGeometry(420, 100, 300, 150);
    label_chinese->setGeometry(80, 100, 200, 50);
    label_yuanxing->setGeometry(80, 180, 200, 50);
    label_fushu->setGeometry(80, 260, 200, 50);
    label_guoqu->setGeometry(80, 340, 200, 50);
    label_guoqufenci->setGeometry(80, 420, 200, 50);

    //设置标签样式
    label_currentWord->setFont(QFont("Microsoft FangSong", 20));
    label_chinese->setFont(QFont("Microsoft FangSong", 20));
    label_yuanxing->setFont(QFont("Microsoft FangSong", 20));
    label_fushu->setFont(QFont("Microsoft FangSong", 20));
    label_guoqu->setFont(QFont("Microsoft FangSong", 20));
    label_guoqufenci->setFont(QFont("Microsoft FangSong", 20));

    //给标签设置一个边框
    label_currentWord->setStyleSheet("border: 1px solid black;");
    label_chinese->setStyleSheet("border: 1px solid black;");
    label_yuanxing->setStyleSheet("border: 1px solid black;");
    label_fushu->setStyleSheet("border: 1px solid black;");
    label_guoqu->setStyleSheet("border: 1px solid black;");
    label_guoqufenci->setStyleSheet("border: 1px solid black;");

    //创建一个line edit用来作为用户输入框
    lineEdit = new QLineEdit(this);

    //设置line edit的样式
    lineEdit->setGeometry(420, 320, 300, 50);
    lineEdit->setFont(QFont("Microsoft FangSong", 20));
    lineEdit->setStyleSheet("background-color: rgb(132, 126, 125);");

    //创建一个确认按钮
    confirmBtn = new QPushButton(this);
    confirmBtn->setGeometry(420, 420, 300, 50);
    confirmBtn->setFont(QFont("Microsoft FangSong", 20));
    confirmBtn->setText("确认");
    confirmBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //创建一个返回按钮
    backBtn = new QPushButton(this);
    backBtn->setGeometry(720, 20, 50, 50);
    backBtn->setFont(QFont("Microsoft FangSong", 20));
    backBtn->setText("返回");
    backBtn->setStyleSheet("background-color: rgb(153, 229, 80);");


}

//添加到堆栈窗口
void ReciteWords::addToStack(QStackedWidget *stackedWidget) {
    stackedWidget->addWidget(this);
}

//设置按钮连接其他页面
void ReciteWords::connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu) {
    connect(backBtn, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(mainMenu);});
}