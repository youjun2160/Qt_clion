#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QLabel>
#include <QlcdNumber>
#include <QTimer>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <iostream>
#include <chrono>
#include <random>

enum MoveType
{
    LEFT,
    RIGHT,
    DOWN,
    UP,
    SPACE
};

typedef struct Block
{
    int block[4][4];
    QColor color;
    int x;
    int y;
    bool isExit = false;
} Block;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    void paintEvent(QPaintEvent *event);

private:
    //页边距离
    int margin = 30;
    //游戏盘大小
    int boardWidth = 16;
    int boardHeight = 26;
    //游戏盘每个格子大小
    int cellSize = 30;
    //游戏分数
    int score = 0;
    //游戏盘
    int board[16][26] = {0};
    //下一个方块
    struct Block nextBlock;
    //方块生成种子
    int seed = 0;
    //方块下坠速度
    int speed_ms = 150;
    //加速下坠速度
    int speed_ms_up = 150;
    //刷新速度
    int refresh_ms = 1000;
    //方块下坠计时器
    QTimer *timer = nullptr;
    //游戏盘中运动的方块
    struct Block gameBlock;

    int game_timer;
    int paint_timer;
    int speed_up_game_timer;
    int speed_up_paint_timer;

    bool isGamePause = false;
    bool isStart = false;

    QLCDNumber *lcd = nullptr;


public:
    //初始化游戏
    void initGame();
    //创建新方块
    void createBlock(int seed, Block &gameBlock);
    //方块复制
    void copyBlock(int src[4][4], int dest[4][4]);

    //游戏主引擎
    void gameEngine();
    //方块下落
    void moveDown();
    //放置方块进游戏
    void resetBlock();
    //检测左右移动是否被阻挡
    bool checkMove(enum MoveType type);
    //检测是否落地
    bool checkLand();
    //左移
    void moveLeft();
    //右移
    void moveRight();
    //旋转
    void rotate();
    //游戏结束
    void gameOver();
    //键盘事件
    virtual void keyPressEvent(QKeyEvent *event) override;
    //时间恢复
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    //游戏暂停/继续
    void gamePause();
    //计时器
    virtual void timerEvent(QTimerEvent *event) override;
    //开始游戏
    void startGame();
    //得分
    void addScore();
    //消除方块后下落
    void moveDownAfterClear(int layer);

private:
    //田字
    int item1[4][4] =
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        };

    //右L
    int item2[4][4] =
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0}
        };

    //左L
    int item3[4][4] =
        {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        };

    //右S
    int item4[4][4]=
        {
            {0,0,0,0},
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0}
        };
    //左S
    int item5[4][4]=
        {
            {0,0,0,0},
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0}
        };
    //山形
    int item6[4][4]=
        {
            {0,0,0,0},
            {0,0,1,0},
            {0,1,1,0},
            {0,0,1,0}
        };
    //长条
    int item7[4][4]=
        {
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0}
        };
};
#endif // MAINWINDOW_H
