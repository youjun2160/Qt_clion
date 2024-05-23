#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include "player.h"
#include "map.h"
#include <QGraphicsView>
#include <QTimer>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPixmap>

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
    void paintEvent(QPaintEvent *event) override;

private:
    QPushButton *button;

    //游戏状态：1，游戏开始界面   2，游戏进行中   3，游戏结束
    int gameState = 1;
    //地图大小
    Map gameMap;
    //创建角色
    player player;
    //游戏主计时器
    int gameTimer = 0;
    //创建摄像机
    QGraphicsView *camera;
    //创建场景
    QGraphicsScene *Tscene;
    //创建角色
    QGraphicsPixmapItem *playerItem;


protected:
    //当窗口大小调整时，重新设置窗口
    void resizeEvent(QResizeEvent *event) override;
    //当玩家移动时，根据玩家位置来更新摄像机
    void updateCamera(QGraphicsView *view);
    //开始游戏
    void startGame();
    //计时器
    void timerEvent(QTimerEvent *event) override;
    //角色键盘响应
    void keyPressEvent(QKeyEvent *event) override;
    //角色键盘松开
    void keyReleaseEvent(QKeyEvent *event) override;
    //更新角色样子
    void updateSkin();
};
#endif // MAINWINDOW_H
