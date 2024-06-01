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
    label_chinese->setGeometry(80, 100, 250, 50);
    label_yuanxing->setGeometry(80, 180, 250, 50);
    label_fushu->setGeometry(80, 260, 250, 50);
    label_guoqu->setGeometry(80, 340, 250, 50);
    label_guoqufenci->setGeometry(80, 420, 250, 50);

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

    //设置标签背景颜色为灰色
    label_currentWord->setStyleSheet("background-color: rgb(132, 126, 125);");
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

    //创建一个确认按钮
    confirmBtn = new QPushButton(this);
    confirmBtn->setGeometry(420, 420, 300, 50);
    confirmBtn->setFont(QFont("Microsoft FangSong", 20));
    confirmBtn->setText("下一个");
    confirmBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //创建一个返回按钮
    backBtn = new QPushButton(this);
    backBtn->setGeometry(720, 20, 50, 50);
    backBtn->setFont(QFont("Microsoft FangSong", 20));
    backBtn->setText("返回");
    backBtn->setStyleSheet("background-color: rgb(153, 229, 80);");

    //连接按钮
    connect(confirmBtn, &QPushButton::clicked, this, &ReciteWords::reciteWord);
}

//添加到堆栈窗口
void ReciteWords::addToStack(QStackedWidget *stackedWidget) {
    stackedWidget->addWidget(this);
}

//设置按钮连接其他页面
void ReciteWords::connectBtn(QStackedWidget *stackedWidget, MainMenu *mainMenu) {
    connect(backBtn, &QPushButton::clicked, stackedWidget, [=](){stackedWidget->setCurrentWidget(mainMenu);});
}

//背单词
void ReciteWords::reciteWord() {

    if(btnState){

        confirmBtn->setText("确认");

        if(shuffled == false){
            qDebug() << "重置";

            //清空vector
            words.clear();

            //打开文件
            QFile file("Words/words.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qDebug() << "文件打开失败";
                return;
            }

            //读取文件的每一行到vector
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                words.push_back(line);
            }

            //关闭文件
            file.close();

            total = words.size() - 1;
            qDebug() << total;

            // 获取一个随机时间点作为种子
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            // 利用种子初始化一个随机数引擎
            std::default_random_engine engine(seed);

            //打乱vector中的行
            std::shuffle(words.begin(), words.end(), engine);

            shuffled = true;
        }

        //从vector中读取第index个单词
        currentWord = words[index];
        qDebug() << currentWord << index;
        index++;
        if (index > total) {
            index = 0;
            shuffled = false;
        }

        //将对应内容输入进字符中去
        yuanxing = currentWord.section('-', 0, 0);
        cixing = currentWord.section('-', 1, 1);
        chinese = currentWord.section('-', 2, 2);
        fushu = currentWord.section('-', 3, 3);
        guoqu = currentWord.section('-', 4, 4);
        guoqufenci = currentWord.section('-', 5, 5);

        //设置标签内容
        label_currentWord->setText(yuanxing);
        label_chinese->clear();
        label_yuanxing->clear();
        label_fushu->clear();
        label_guoqu->clear();
        label_guoqufenci->clear();

        btnState = false;
    } else {

        confirmBtn->setText("下一个");

        userInput = lineEdit->text();

        //判断用户输入是否和单词的汉译一样
        if(userInput != chinese){
            //将这个单词添加进错词本

            if (!wordExistsInFile(currentWord, "Words/wrongWords.txt")) {
                //当文件中不存在这个单词时
                QFile wrongfile("Words/wrongWords.txt");
                if (!wrongfile.open(QIODevice::Append | QIODevice::Text)) {
                    qDebug() << "文件打开失败";
                    return;
                }

                //将这个单词添加进文件
                QTextStream out(&wrongfile);
                out << currentWord << Qt::endl;
                wrongfile.close();
            }

            //显示回答错误
            label_currentWord->setText("回答错误");
        } else {
            //显示回答正确
            label_currentWord->setText("回答正确");
        }
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
        //将正确的单词信息显示出来
        label_chinese->setText(chinese);
        label_yuanxing->setText(yuanxing);
        label_fushu->setText(fushu);
        label_guoqu->setText(guoqu);
        label_guoqufenci->setText(guoqufenci);

        lineEdit->clear();

        //设置按钮状态
        btnState = true;
    }
}

//判断单词在文件中是否存在
bool ReciteWords::wordExistsInFile(const QString& word, const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "文件打开失败";
        return false;
    }

    //读取文件
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        //去除空格和换行后比较
        if (line.trimmed() == word.trimmed()) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}