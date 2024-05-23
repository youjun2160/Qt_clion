#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <cmath>

class player : public QMainWindow
{
    Q_OBJECT
public:
    explicit player(QWidget *parent = nullptr);


public:
    //角色在地图上的位置
    QPointF pos = QPointF(500,500);
    //x轴移动速度
    qreal dx = 0;
    //y轴移动速度
    qreal dy = 0;
    //x轴最大移动速度
    qreal maxDx = 5;
    //y轴最大移动速度
    qreal maxDy = 5;
    //角色脚下的状态: 0,悬空  1,固体方块  2,平台
    int state = 0;

    //角色样子状态： 1,静止面朝左边 2,静止面朝右边 3,向左走动 4，向右走动 5，脚下悬空状态 6，朝左持武器角度1 7，朝左持武器角度2
    //8，朝左持武器角度3 9，朝左持武器角度4 10，朝左持武器角度5 11，朝右持武器角度1 12，朝右持武器角度2 13，朝右持武器角度3 14，朝右持武器角度4 15，朝右持武器角度5
    int skin = 1;

    //摩擦力
    qreal friction = 0;
    //动力
    qreal power = 0;


public:
    //角色移动
    void move();
    //在没有执行移动操作时，速度慢慢归零
    void slowDown(QKeyEvent *event);
    //自由下落
    void fall();
    //落到地面
    void land(int A_state);

signals:
};

#endif // PLAYER_H