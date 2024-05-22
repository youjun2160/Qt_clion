#include "player.h"

player::player(QWidget *parent)
    : QMainWindow{parent}
{}

//角色键盘响应
void player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        //向左移动
        if(dx > -maxDx){
            dx -= 1;
        }
        //角色状态样子
        skin = 1;
    } else if(event->key() == Qt::Key_D){
        //向右移动
        if(dx < maxDx){
            dx += 1;
        }
        //角色状态样子
        skin = 2;
    } else if(event->key() == Qt::Key_S){
        //如果脚下状态是平台,那么角色穿过平台，开始自由下落
        if(state == 2){
            dy = 1;
            state = 0;
            //角色状态样子
            skin = 5;
        }
    } else if(event->key() == Qt::Key_Space){
        //跳跃
        if(state == 1 || state == 2){
            dy = -10;
            state = 0;
            //角色状态样子
            skin = 5;
            //飞行
        }else if(state == 0){
            dy -= 1;
            state = 0;
            //角色状态样子
            skin = 5;
        }
    }
}

//角色移动
void player::move()
{
    //更新位置
    pos.rx() += dx;
    pos.ry() += dy;
}

//在没有执行移动操作时，速度慢慢归零
void player::slowDown(QKeyEvent *event)
{
    //不是向左，向右，不要改变dx的值
    if(event->key() != Qt::Key_A) {
        if (dx < 0) {
            dx += 1;
        }
    }

    if(event->key() != Qt::Key_D) {
        if (dx > 0) {
            dx -= 1;
        }
    }
}

//自由下落
void player::fall()
{
    dy += 1;
}

//落到地面
void player::land(int A_state)
{
    dy = 0;
    state = A_state;
}

void player::paintEvent(QPaintEvent *event)
{
    //绘制角色
    QPainter painter(this);
    QPixmap pixmap(":/pictures/ArmsDealer_Default.png");
    //截取部分绘制
    QRect sourceRect(0, 8, 39, 45);
    //设置目标绘制位置
    QRect targetRect(pos.x(), pos.y(), 39, 45);
    //绘制
    painter.drawPixmap(targetRect, pixmap, sourceRect);

}