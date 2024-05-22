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
        //绘制游戏地图
        QPixmap pixmap(":/pictures/Battlefield.png");

        pixmap = pixmap.scaled(this->width() * 2, this->height() * 2);
        painter.drawPixmap(0, 0, pixmap);

        //绘制角色
        player.paintEvent(event);
        //绘制地图
        //gameMap.draw(&painter);

    }


}

void MainWindow::resizeEvent(QResizeEvent *event) {
    //设置窗口大小为最大化时的大小
    QMainWindow::resizeEvent(event);
    // 窗口大小改变时，更新按钮的位置
    button->setGeometry(width() / 2 - 150, height() / 2 - 50, 300, 100);
}

void MainWindow::updateCamera(QGraphicsView *view) {
    //计算摄像机的新中心点
    QPointF viewCenter = player.pos;

    // 限制视口不超出地图边界
    qreal halfWidth = view->viewport()->width() / 2.0;
    qreal halfHeight = view->viewport()->height() / 2.0;
    qreal leftBound = halfWidth;
    qreal rightBound = gameMap.size.width() - halfWidth;
    qreal topBound = halfHeight;
    qreal bottomBound = gameMap.size.height() - halfHeight;

    viewCenter.setX(qMax(leftBound, qMin(viewCenter.x(), rightBound)));
    viewCenter.setY(qMax(topBound, qMin(viewCenter.y(), bottomBound)));

    // 设置视口的新中心点
    view->centerOn(viewCenter);
}

void MainWindow::startGame() {
    gameState = 2;
    update();

    //开始计时器
    gameTimer = startTimer(1000 / 60);

    //开始按钮隐藏起来
    button->hide();

    //创建一个足够大的场景
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1920, 830);

    //设置摄像机
    QGraphicsView *view = new QGraphicsView(scene, this);

    //添加角色
    QGraphicsRectItem *playerItem = scene->addRect(player.boundingRect());

    //创建自定义视图
    GameView *view = new GameView(this);

    //配置视图
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::NoDrag);

    //设置视图大小
    view->resize(500, 350);
}

//计时器
void MainWindow::timerEvent(QTimerEvent *event) {
    if(event->timerId() == gameTimer) {
        //更新角色位置
        player.move();
        //更新摄像机
        updateCamera(ui->graphicsView);
    }
}