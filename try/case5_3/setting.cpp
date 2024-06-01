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
    textBrowser->setStyleSheet("border: 1px solid black;");

    //创建一个lineEdit
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(350, 180, 250, 50);
    lineEdit->setStyleSheet("border: 1px solid black;");
    lineEdit->setFont(QFont("Microsoft FangSong", 20));

    //创建三个按钮,分别是查看全部单词本，查看错词本，删除错词本中的单词
    allWordBookBtn = new QPushButton(this);
    allWordBookBtn->setGeometry(60, 280, 250, 50);
    allWordBookBtn->setFont(QFont("Microsoft FangSong", 20));
    allWordBookBtn->setText("查看全部单词本");
    allWordBookBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    wrongWordBookBtn = new QPushButton(this);
    wrongWordBookBtn->setGeometry(60, 360, 250, 50);
    wrongWordBookBtn->setFont(QFont("Microsoft FangSong", 20));
    wrongWordBookBtn->setText("查看错词本");
    wrongWordBookBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    deleteWordBookBtn = new QPushButton(this);
    deleteWordBookBtn->setGeometry(350, 280, 250, 50);
    deleteWordBookBtn->setFont(QFont("Microsoft FangSong", 20));
    deleteWordBookBtn->setText("删除搜索到的单词");
    deleteWordBookBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //创建一个搜索按钮
    searchBtn = new QPushButton(this);
    searchBtn->setGeometry(600, 180, 50, 50);
    searchBtn->setFont(QFont("Microsoft FangSong", 20));
    searchBtn->setText("搜索");
    searchBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //连接搜索按钮
    connect(searchBtn, &QPushButton::clicked, this, &Setting::search);

    //连接删除按钮
    connect(deleteWordBookBtn, &QPushButton::clicked, this, &Setting::deleteWord);

    //连接查看全部单词本按钮
    connect(allWordBookBtn, &QPushButton::clicked, this, &Setting::allWordBook);

    //连接查看错词本按钮
    connect(wrongWordBookBtn, &QPushButton::clicked, this, &Setting::wrongWordBook);
}

//设置按钮连接其他页面
void Setting::connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu) {
    connect(backBtn, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(mainMenu);});
}

//搜索
void Setting::search() {
    //获取用户输入
    UserInput = lineEdit->text();


    //打开文件
    QFile file("Words/wrongWords.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return;
    }

    //读取其中一行
    line = file.readLine();
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
        //找到了
        isFind = true;
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
        textBrowser->setText("中文：" + chinese + "\n" + "原型：" + yuanxing + "\n" + "负数形式：" + fushu + "\n" + "过去：" + guoqu + "\n" + "过去分词：" + guoqufenci);
    } else {
        //没有找到
        isFind = false;
        textBrowser->setText("没有找到");
    }
    file.close();
}

//删除
void Setting::deleteWord() {
    if (!isFind) {
        return;
    }

    qDebug() << "删除";

    //以读的方式打开文件
    QFile file("Words/wrongWords.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return;
    }
    //以写的方式打开文件
    QFile file2("Words/temp.txt");
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return;
    }

    //读取其中一行
    QString Tline = file.readLine();
    //判断读取的这一行是否包含UserInput，如果不是，那么久读取下一行，直到找到UserInput
    //先判断用户输入是否是空
    if (line.isEmpty()) {
        qDebug() << "输入为空";
        return;
    }
    //循环遍历原文件所有内容，如果不是要删除的那一行，就写入新文件
    while(true){

        if(!Tline.contains(line)){
            file2.write(Tline.toUtf8());
        }
        if(file.atEnd()){
            break;
        }
        Tline = file.readLine();
    }

    //删除旧文件
    file.remove();
    //重命名新文件
    file2.rename("Words/wrongWords.txt");

    //关闭文件
    file2.close();

    isFind = false;
    textBrowser->setText("删除成功");
}

//查看全部单词本
void Setting::allWordBook() {

    //清空
    textBrowser->clear();

    //打开文件
    QFile file("Words/words.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return;
    }
    //读取其中一行
    while (!file.atEnd()) {
        QString Tline = file.readLine();

        textBrowser->append(Tline);
    }
    file.close();
}

//查看错词本
void Setting::wrongWordBook() {
    //清空
    textBrowser->clear();

    //打开文件
    QFile file("Words/wrongWords.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return;
    }
    //读取其中一行
    while (!file.atEnd()) {
        QString Tline = file.readLine();
        textBrowser->append(Tline);
    }
    file.close();
}