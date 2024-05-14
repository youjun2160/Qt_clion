#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置窗口背景色为白色
    //this->setStyleSheet("background-color: white;");

    //固定窗口大小
    this->setFixedSize(boardWidth * squareSize + 40 + margin * 2 + boardSize2 * squareSize, boardHeight * squareSize + margin * 2);

    //创建并初始化分数
    score = 0;
    QLabel *scoreLabel = new QLabel(this);
    // 创建一个QFont对象
    QFont font("Arial", 20, QFont::Bold);
    // 应用字体到QLabel上
    scoreLabel->setFont(font);
    // 设置QLabel显示的文本
    scoreLabel->setText("Score:");
    scoreLabel->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2);

    // 创建一个QLCDNumber对象
    QLCDNumber *lcd = new QLCDNumber(this);
    // 设置LCD显示的数字
    lcd->display(score);
    // 设置LCD显示的位置
    lcd->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2 + 40);

    //创建开始/暂停 和重置按钮
    QPushButton *startButton = new QPushButton("开始/暂停", this);
    startButton->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2 + 300);

    QPushButton *resetButton = new QPushButton("重置", this);
    resetButton->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2 + 350);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    QColor boardColor = Qt::black;

    //创建一个QPen对象来设置边框属性
    QPen borderPen(boardColor);
    borderPen.setWidth(1);

    //设置坐标
    painter.translate(margin, margin);

    //设置笔刷颜色为白色
    painter.setBrush(Qt::white);

    //绘制每个小方格
    for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            int x = i * squareSize;
            int y = j * squareSize;

            //在绘制之前应用边框画笔
            painter.setPen(borderPen);

            //绘制带有边框的小方格
            painter.drawRect(x, y, squareSize, squareSize);

            if (board[i][j] == 1) {
                //设置笔刷颜色为黑色
                painter.setBrush(Qt::black);

                //在绘制之前应用填充画笔
                painter.setPen(Qt::NoPen);

                //绘制黑色小方格
                painter.drawRect(x, y, squareSize, squareSize);
            }
        }
    }

    //设置笔刷颜色为白色
    painter.setBrush(Qt::white);

    //设置坐标
    painter.translate(boardWidth * squareSize + 40 , 0);

    //绘制预告方块
    for (int i = 0; i < boardSize2; i++) {
        for (int j = 0; j < boardSize2; j++) {
            int x = i * squareSize;
            int y = j * squareSize;

            //在绘制之前应用边框画笔
            painter.setPen(borderPen);

            //绘制带有边框的小方格
            painter.drawRect(x, y, squareSize, squareSize);

            if (board2[i][j] == 1) {
                //设置笔刷颜色为黑色
                painter.setBrush(Qt::black);
                //在绘制之前应用填充画笔
                painter.setPen(Qt::NoPen);
                //绘制黑色小方格
                painter.drawRect(x, y, squareSize, squareSize);
            }
        }
    }

}
