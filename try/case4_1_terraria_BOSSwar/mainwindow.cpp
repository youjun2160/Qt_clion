#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口最大化
    this->setWindowState(Qt::WindowMaximized);

    button = new QPushButton("开始游戏", this);
    button->setFlat(true);
    button->setFocusPolicy(Qt::NoFocus);
    //设置按钮字体大小
    QFont font = button->font();
    font.setPointSize(25);
    button->setFont(font);
    //鼠标指针悬在按钮上，字体变大
    button->setStyleSheet("QPushButton {"
                          "   border: none;" // 移除边框
                          "   color: grey;" // 字体颜色
                          "   background-color: transparent;" // 透明背景
                          "}"
                          "QPushButton:hover {"
                          "   font-size: 34pt;" // 字体放大效果
                          "   color: white;" // 可以根据需要更改颜色
                          "}"
                          "QPushButton:pressed {"
                          "   font-size: 32pt;"// 字体稍小一点
                          "   color: green;" // 可以根据需要更改颜色
                          "}");

    //连接按钮
    connect(button, &QPushButton::clicked, this, &MainWindow::startGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter painter(this);

    if(gameState == 1){
        //绘制图片资源作为背景
        QPixmap pixmap(":/pictures/startgame.png");

        pixmap = pixmap.scaled(this->width(), this->height());
        painter.drawPixmap(0, 0, pixmap);
    } else if(gameState == 2){
        /*
        //绘制游戏地图
        QPixmap pixmap(":/pictures/Battlefield.png");

        pixmap = pixmap.scaled(this->width() * 2, this->height() * 2);
        painter.drawPixmap(0, 0, pixmap);

        //绘制角色
        player.paintEvent(event);
        //绘制地图
        //gameMap.draw(&painter);
        */

    }


}

void MainWindow::resizeEvent(QResizeEvent *event) {
    //设置窗口大小为最大化时的大小
    QMainWindow::resizeEvent(event);
    // 窗口大小改变时，更新按钮的位置
    button->setGeometry(width() / 2 - 150, height() / 2 - 50, 300, 100);
}


//开始游戏，进行初始化
void MainWindow::startGame() {
    gameState = 2;
    update();

    //开始计时器
    gameTimer = startTimer(1000 / 60);

    //开始按钮隐藏起来
    button->hide();

    //创建一个足够大的场景
    Tscene = new QGraphicsScene(this);
    QPixmap pixmapSence(":/pictures/Battlefield3.png");
    Tscene->setSceneRect(0, 0, pixmapSence.width(), pixmapSence.height());
    Tscene->addPixmap(pixmapSence);

    //设置摄像机
    camera = new QGraphicsView(this);
    camera->setScene(Tscene);

    //添加角色
    QPixmap pixmapPlayer(":/pictures/ArmsDealer_Default.png");
    QPixmap cropPixmap = pixmapPlayer.copy(0, 0, 39, 45);
    playerItem = Tscene->addPixmap(cropPixmap);
    playerItem->setPos(player.pos);

    //添加固体方块
    QGraphicsItem *blockItem = Tscene->addRect(0, 672 * 2, 3840, 316);

    //添加平台
    platformItem = Tscene->addRect(0, 206 * 2, 3840, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    platformItem2 = Tscene->addRect(0, 386 * 2, 3840, 1, QPen(Qt::NoPen), QBrush(Qt::black));
    platformItem3 = Tscene->addRect(0, 534 * 2, 3840, 1, QPen(Qt::NoPen), QBrush(Qt::black));

    

    //配置视图
    //设置渲染模式
    camera->setRenderHint(QPainter::Antialiasing);
    //设置缩放模式
    camera->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //设置拖拽模式
    camera->setDragMode(QGraphicsView::NoDrag);

    //设置摄像机
    camera->centerOn(playerItem);

    camera->resize(this->width(), this->height());

    //添加视图大小，设置为最大化
    // 获取窗口的大小和场景的大小
    QSize windowSize = this->size() * 4;
    QSizeF sceneSize = pixmapSence.size();

    // 计算需要的缩放因子
    qreal scaleX = windowSize.width() / sceneSize.width();
    qreal scaleY = windowSize.height() / sceneSize.height();
    qreal scale = qMin(scaleX, scaleY); // 取较小的一个以保持场景比例

    // 应用缩放变换
    camera->setTransform(QTransform::fromScale(scale, scale));


    //添加视图
    camera->show();
}

//计时器
void MainWindow::timerEvent(QTimerEvent *event) {
    if(event->timerId() == gameTimer) {
        //更新角色位置
        player.move();
        playerItem->setPos(player.pos);
        //更新摄像机跟随角色
        camera->centerOn(playerItem);
        //更新角色样子
        updateSkin();
        //角色下落
        fall();

    }
}

//角色键盘响应
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        //角色动力
        player.power = -0.2;
        //角色状态样子
        if(isStandingOnPlatform(playerItem, platformItem) || isStandingOnPlatform(playerItem, platformItem2) || isStandingOnPlatform(playerItem, platformItem3)){
            player.skin = 1;
        } else{
            player.skin = 5;
        }
    } else if(event->key() == Qt::Key_D){
        //角色动力
        player.power = 0.2;
        //角色状态样子
        if(isStandingOnPlatform(playerItem, platformItem) || isStandingOnPlatform(playerItem, platformItem2) || isStandingOnPlatform(playerItem, platformItem3)){
            player.skin = 2;
        } else{
            player.skin = 6;
        }
    } else if(event->key() == Qt::Key_S){
        //如果脚下状态是平台,那么角色穿过平台，开始自由下落
        if(player.state == 2){
            player.dy = 1;
            player.state = 0;
        }
    } else if(event->key() == Qt::Key_Space){
        //跳跃
        if(player.state == 1 || player.state == 2){
            player.dy = -5;
            player.state = 0;
            //判断角色样子
            if(player.dx > 0){
                player.skin = 6;
            }else if(player.dx < 0){
                player.skin = 5;
            }
            //飞行
        }else if(player.state == 0){
            player.dy -= 1;
            player.state = 0;
        }
    }
}

//键盘松开
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        //角色动力
        player.power = 0;
    } else if(event->key() == Qt::Key_D){
        //角色动力
        player.power = 0;
    }
}

//判断角色脚下是否是平台
bool MainWindow::isStandingOnPlatform(QGraphicsPixmapItem *playerItem, QGraphicsItem *platformItem) {
    // 获取角色脚下区域的矩形，您可能需要根据角色的实际尺寸和位置调整这个区域
    QRectF feetRect = playerItem->boundingRect().adjusted(0, playerItem->boundingRect().height() - 1, 0, 0);
    feetRect.translate(playerItem->pos());

    // 获取所有与角色脚下区域发生碰撞的项
    QList<QGraphicsItem *> collidingItems = playerItem->scene()->items(feetRect, Qt::IntersectsItemBoundingRect);

    // 检查碰撞列表中是否有平台项
    foreach(QGraphicsItem *item, collidingItems) {
        if (item == platformItem) {
            return true; // 碰撞项中有平台，角色站在平台上
        }
    }

    return false; // 没有碰撞项是平台，角色不在平台上

}

//角色自由下落
void MainWindow::fall() {
    if(isStandingOnPlatform(playerItem, platformItem) || isStandingOnPlatform(playerItem, platformItem2) || isStandingOnPlatform(playerItem, platformItem3)){
        player.state = 2;
        player.dy = 0;
    } else{
        player.state = 1;
        player.fall();
    }
}

//更新角色样子
void MainWindow::updateSkin() {
    //加载图片
    //角色样子状态： 1,静止面朝左边 2,静止面朝右边 3,向左走动 4，向右走动
    // 5，面向左脚下悬空状态  6，面向右脚下悬空状态 7，朝左持武器角度 8，朝右持武器角度
    QPixmap pixmapPlayer(":/pictures/ArmsDealer_Default.png");
    if(player.skin == 1){
        //将角色图片替换
        QPixmap cropPixmap = pixmapPlayer.copy(0, 8, 39, 45);
        playerItem->setPixmap(cropPixmap);
        //设置不应用变换
        playerItem->setTransform(QTransform());
    } else if(player.skin == 2){
        //由状态1镜像过来
        QPixmap cropPixmap = pixmapPlayer.copy(0, 8, 39, 45);
        playerItem->setPixmap(cropPixmap);
        //水平反转
        QTransform transform;
        transform.scale(-1, 1);
        transform.translate(-cropPixmap.width(), 0);
        playerItem->setTransform(transform);
    } else if(player.skin == 3){

    } else if(player.skin == 4){

    } else if(player.skin == 5){
        //将角色图片替换
        QPixmap cropPixmap = pixmapPlayer.copy(0, 64, 39, 45);
        playerItem->setPixmap(cropPixmap);
        //设置不应用变换
        playerItem->setTransform(QTransform());
    } else if(player.skin == 6){
        //由状态5镜像过来
        QPixmap cropPixmap = pixmapPlayer.copy(0, 64, 39, 45);
        playerItem->setPixmap(cropPixmap);
        //水平反转
        QTransform transform;
        transform.scale(-1, 1);
        transform.translate(-cropPixmap.width(), 0);
        playerItem->setTransform(transform);
    } else if(player.skin == 7){
    } else if(player.skin == 8){
    }
}
