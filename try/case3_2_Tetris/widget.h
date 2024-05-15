#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPainter>
#include <QLabel>
#include <QlcdNumber>
#include <QTimer>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE
};

struct Border{
    int ubound;
    int dbound;
    int lbound;
    int rbound;
};

struct block_pos{
    int pos_x;
    int pos_y;
    // block_pos(int x, int y):pos_x(x),pos_y(y){}
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int boardWidth = 12;
    int boardHeight = 20;
    int squareSize = 30;
    int boardSize2 = 4; //下一个方块预告显示的尺寸
    int margin = 20;    //边框
    int score = 0;      //分数

    int board[12][20] = {};
    //预告方块显示板
    int board2[4][4] = {};



    //田字型
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
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            };

//左L
    int item3[4][4] =
            {
                    {0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
            };

//右S
    int item4[4][4]=
            {
                    {0,1,0,0},
                    {0,1,1,0},
                    {0,0,1,0},
                    {0,0,0,0}
            };
//左S
    int item5[4][4]=
            {
                    {0,0,1,0},
                    {0,1,1,0},
                    {0,1,0,0},
                    {0,0,0,0}
            };
//山形
    int item6[4][4]=
            {
                    {0,0,0,0},
                    {0,0,1,0},
                    {0,1,1,1},
                    {0,0,0,0}
            };
//长条
    int item7[4][4]=
            {
                    {0,0,1,0},
                    {0,0,1,0},
                    {0,0,1,0},
                    {0,0,1,0}
            };


public:
    //初始化游戏
    void InitGame();
    //开始游戏
    void StartGame();
    //游戏结束
    void GameOver();

    //重置方块
    void ResetBlock();
    //方块变动
    void BlockMove(Direction dir);
    //方块旋转
    void BlockRotate(int block[4][4]);
    //产生方块
    void CreateBlock(int block[4][4], int block_id);
    //计算边界
    void GetBorder(int block[4][4], Border &border);
    //转换为稳定方块
    void ConvertStable(int x,int y);
    //判断是否会碰撞
    bool IsCollide(int x,int y,Direction dir);

    //定时器
    virtual void timerEvent(QTimerEvent *event) override;
    //场景重绘
    virtual void paintEvent(QPaintEvent *event) override;
    //键盘响应
    virtual void keyPressEvent(QKeyEvent *event) override;


private:
    block_pos block_pos; //当前方块坐标
    int cur_block[4][4]; //当前方块形状
    Border cur_border; //当前方块边界
    int next_block[4][4] = {}; //下一个方块形状
    bool isStable; //当前方块是否稳定了
    int game_timer; //方块下落计时器
    int paint_timer; //渲染刷新计时器
    int speed_ms; //下落时间间隔
    int refresh_ms; //刷新时间间隔


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
