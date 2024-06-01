#include "search.h"

Search::Search(QWidget *parrent) {

    //设置窗口的背景
    QPalette palette;
    QPixmap pixmap(":/picture/Search.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    //创建一个返回按钮
    backBtn = new QPushButton(this);
    backBtn->setGeometry(720, 20, 50, 50);
    backBtn->setFont(QFont("Microsoft FangSong", 20));
    backBtn->setText("返回");
    backBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //创建标签
    label_chinese = new QLabel(this);
    label_yuanxing = new QLabel(this);
    label_fushu = new QLabel(this);
    label_guoqu = new QLabel(this);
    label_guoqufenci = new QLabel(this);

    //设置标签
    label_chinese->setGeometry(80, 100, 250, 50);
    label_yuanxing->setGeometry(80, 180, 250, 50);
    label_fushu->setGeometry(80, 260, 250, 50);
    label_guoqu->setGeometry(80, 340, 250, 50);
    label_guoqufenci->setGeometry(80, 420, 250, 50);

    //设置标签样式,设置字体颜色为黑色
    label_chinese->setFont(QFont("Microsoft FangSong", 15));
    label_yuanxing->setFont(QFont("Microsoft FangSong", 15));
    label_fushu->setFont(QFont("Microsoft FangSong", 15));
    label_guoqu->setFont(QFont("Microsoft FangSong", 15));
    label_guoqufenci->setFont(QFont("Microsoft FangSong", 15));

    //给标签设置一个边框
    label_chinese->setStyleSheet("border: 1px solid black;");
    label_yuanxing->setStyleSheet("border: 1px solid black;");
    label_fushu->setStyleSheet("border: 1px solid black;");
    label_guoqu->setStyleSheet("border: 1px solid black;");
    label_guoqufenci->setStyleSheet("border: 1px solid black;");

    //设置背景颜色为灰色
    label_chinese->setStyleSheet("background-color: rgb(132, 126, 125);");
    label_yuanxing->setStyleSheet("background-color: rgb(132, 126, 125);");
    label_fushu->setStyleSheet("background-color: rgb(132, 126, 125);");
    label_guoqu->setStyleSheet("background-color: rgb(132, 126, 125);");
    label_guoqufenci->setStyleSheet("background-color: rgb(132, 126, 125);");

    //创建一个line edit用来作为用户输入框
    lineEdit = new QLineEdit(this);

    //设置line edit的样式
    lineEdit->setGeometry(420, 320, 300, 50);
    lineEdit->setFont(QFont("Microsoft FangSong", 20));
    lineEdit->setStyleSheet("background-color: rgb(132, 126, 125);");

    //创建一个按钮
    searchBtn = new QPushButton(this);
    searchBtn->setGeometry(420, 420, 300, 50);
    searchBtn->setFont(QFont("Microsoft FangSong", 20));
    searchBtn->setText("搜索");
    searchBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //连接搜索按钮
    connect(searchBtn, &QPushButton::clicked, this, &Search::search);
}

//添加到堆栈窗口
void Search::addToStack(QStackedWidget *stackedWidget)
{
    stackedWidget->addWidget(this);
}

//设置按钮连接其他页面
void Search::connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu) {
    connect(backBtn, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(mainMenu);});
}

//执行搜索
void Search::search() {

    //获取用户输入
    UserInput = lineEdit->text();


    //打开文件
    QFile file("Words/words.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return;
    }

    //读取其中一行
    QString line = file.readLine();
    //判断读取的这一行是否包含UserInput，如果不是，那么久读取下一行，直到找到UserInput
    //先判断用户输入是否是空
    if (UserInput.isEmpty()) {
        qDebug() << "输入为空";
        return;
    }
    while (!line.contains(UserInput)) {
        line = file.readLine();
        qDebug() << line;
        if (file.atEnd()) {
            break;
        }
    }
    //如果找到了
    if (line.contains(UserInput)) {
        qDebug() << "找到了";
        //将对应内容输入进字符中去
        yuanxing = line.section('-', 0, 0);
        chinese = line.section('-', 2, 2);
        fushu = line.section('-', 3, 3);
        guoqu = line.section('-', 4, 4);
        guoqufenci = line.section('-', 5, 5);
        //特殊情况
        if(fushu == '*'){
            fushu = yuanxing;
        }
        if(guoqufenci == '*'){
            guoqufenci = guoqu;
        }
        if(fushu == '#'){
            fushu = ' ';
        }
        if(guoqu == '#'){
            guoqu = ' ';
        }
        if(guoqufenci == '#'){
            guoqufenci = ' ';
        }
        //显示
        qDebug() << chinese << yuanxing << fushu << guoqu << guoqufenci;
        label_chinese->setText(chinese);
        label_yuanxing->setText(yuanxing);
        label_fushu->setText(fushu);
        label_guoqu->setText(guoqu);
        label_guoqufenci->setText(guoqufenci);

    } else {
        qDebug() << "没有找到";
        //如果没有找到
        label_chinese->setText("没有找到");
        label_yuanxing->setText("没有找到");
        label_fushu->setText("没有找到");
        label_guoqu->setText("没有找到");
        label_guoqufenci->setText("没有找到");
    }
    file.close();
}
