#include "player.h"

player::player(QWidget *parent)
    : QMainWindow{parent}
{}


//角色移动
void player::move()
{
    if(dx > 0) {
        //摩擦力为负方向
        friction = -0.1;
    } else if(dx < 0) {
        //摩擦力为正方向
        friction = 0.1;
    } else if(dx == 0) {
        //摩擦力为0
        friction = 0;
    }

    // 设置一个阈值
    const double threshold = 0.05;

    // 如果dx的绝对值小于阈值，则将dx设置为0
    if(std::fabs(dx) < threshold) {
        dx = 0;
    }

    if(power + friction > 0 && dx < maxDx) {
        dx += power + friction;
    } else if(power + friction < 0 && dx > -maxDx) {
        dx += power + friction;
    } else if(power + friction == 0) {
        dx += power + friction;
    }

    pos.setX(pos.x() + dx);
    pos.setY(pos.y() + dy);
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
