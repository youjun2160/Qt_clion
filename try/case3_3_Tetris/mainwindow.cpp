#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    this->setFixedSize(margin * 2 + (boardWidth - 4) * cellSize + 4 * cellSize + 40, margin * 2 + (boardHeight - 6) * cellSize);
    this->setWindowTitle("俄罗斯方块");

    //this->setStyleSheet("background-color: black");

    //测试按钮
    QPushButton *button = new QPushButton(this);
    button->setText("测试按钮");
    button->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 200);
    connect(button, &QPushButton::clicked, this, &MainWindow::startGame);

    //测试按钮2
    QPushButton *button2 = new QPushButton(this);
    button2->setText("测试按钮2");
    button2->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 250);
    connect(button2, &QPushButton::clicked, this, &MainWindow::gamePause);

    //测试按钮3
    QPushButton *button3 = new QPushButton(this);
    button3->setText("测试按钮3");
    button3->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 300);
    connect(button3, &QPushButton::clicked, this, &MainWindow::initGame);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //绘制出游戏盘边框
    QColor color = QColor(91, 54, 48);
    painter.setPen(color);
    //绘制一个矩形
    painter.drawRect(margin, margin, (boardWidth - 4) * cellSize, (boardHeight - 6) * cellSize);

    //绘制出下一个方块展示位置边框
    color = QColor(67, 143, 192);
    painter.setPen(color);
    //绘制一个矩形
    painter.drawRect(margin + (boardWidth - 4) * cellSize + 40, margin, 4 * cellSize, 4 * cellSize);

    //根据游戏盘绘制游戏画面
    for(int i = 2; i < (boardWidth - 2); i++){
        for(int j = 4; j < (boardHeight - 2); j++){
            if(board[i][j] == 0){
                color = QColor(Qt::white);
            } else if(board[i][j] == 1){
                color = gameBlock.color;
            } else if(board[i][j] == 2){
                color = QColor(Qt::red);
            }
            //计算坐标
            int x = margin + (i - 2) * cellSize;
            int y = margin + (j - 4) * cellSize;
            //根据游戏盘绘制无边框实心方块
            // 使用画刷填充一个矩形区域
            painter.fillRect(QRect(x, y, cellSize, cellSize), QBrush(color));

        }
    }

    //根据下一个方块绘制预告方块
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(nextBlock[i][j] == 0){
                color = QColor(Qt::white);
            }else if(nextBlock[i][j] == 1){
                color = gameBlock.color;
            }
            //计算坐标
            int x = margin + (boardWidth - 4) * cellSize + 40 + j * cellSize;
            int y = margin + i * cellSize;
            //根据游戏盘绘制无边框实心方块
            // 使用画刷填充一个矩形区域
            painter.fillRect(QRect(x, y, cellSize, cellSize), QBrush(color));
        }
    }
}

//初始化游戏
void MainWindow::initGame(){
    //初始化游戏盘
    for(int i = 0; i < boardWidth; i++){
        for(int j = 0; j < boardHeight; j++){
            board[i][j] = 0;
        }
    }
    //初始化下一个方块
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            nextBlock[i][j] = 0;
        }
    }

    srand(time(0));

    startGame();

}

//方块复制
void MainWindow::copyBlock(int src[4][4], int des[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            des[j][i] = src[i][j];
        }
    }
}

//创建新方块到下一个方块
void MainWindow::createBlock(int seed, Block &newBlock){
    //根据时间设置种子
    srand(time(0));
    seed = rand();
    switch (seed % 7) {
    case 0:
        copyBlock(item1, newBlock.block);
        break;
    case 1:
        copyBlock(item2, newBlock.block);
        break;
    case 2:
        copyBlock(item3, newBlock.block);
        break;
    case 3:
        copyBlock(item4, newBlock.block);
        break;
    case 4:
        copyBlock(item5, newBlock.block);
        break;
    case 5:
        copyBlock(item6, newBlock.block);
        break;
    case 6:
        copyBlock(item7, newBlock.block);
        break;
    default:
        break;
    }

    //随机颜色
    newBlock.color = QColor(rand() % 256, rand() % 256, rand() % 256);

    //设置下一个方块
    copyBlock(newBlock.block, nextBlock);
}

//方块下落
void MainWindow::moveDown(){
    qDebug() << "1";
    for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
        for(int j = gameBlock.y + 4; j >= gameBlock.y; j--){
            if(board[i][j] == 1){
                board[i][j + 1] = 1;
                board[i][j] = 0;
            }
        }
    }
    gameBlock.y++;
}

//放置方块进游戏
void MainWindow::resetBlock(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i + 6][j] = gameBlock.block[i][j];
        }
    }
    //设置方块坐标
    gameBlock.x = 6;
    gameBlock.y = 0;
}

//检测左右移动是否被阻挡
bool MainWindow::checkMove(enum MoveType type){
    if(type == LEFT){
        for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
            for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
                if((board[i][j] == 1 && i <= 2) || (gameBlock.block[i][j] == 1 && board[i - 1][j] == 2)){
                    return false;
                }
            }
        }
    } else if(type == RIGHT){
        for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
            for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
                if((board[i][j] == 1 && i >= boardWidth - 3) || (gameBlock.block[i][j] == 1 && board[i + 1][j] == 2)){
                    return false;
                }
            }
        }
    }
    return true;
}

//检测是否落地
bool MainWindow::checkLand(){
    for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
        for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
            if((board[i][j] == 1 && board[i][j + 1] == 2) || (board[i][j] == 1 && j >= boardHeight - 3)){
                return false;
            }
        }
    }
    return true;
}

//左移
void MainWindow::moveLeft(){
    for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
        for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
            if(board[i][j] == 1){
                board[i - 1][j] = 1;
                board[i][j] = 0;
            }
        }
    }
    gameBlock.x--;
}

//右移
void MainWindow::moveRight(){
    for(int i = gameBlock.x + 4; i >= gameBlock.x; i--){
        for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
            if(board[i][j] == 1){
                board[i + 1][j] = 1;
                board[i][j] = 0;
            }
        }
    }
    gameBlock.x++;
}

//旋转
void MainWindow::rotate(){

    //先暂存旋转后的方块
    int temp[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp[j][3 - i] = gameBlock.block[i][j];
        }
    }

    //检测是否可以旋转
    for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
        for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
            if(temp[i - gameBlock.x][j - gameBlock.y] == 1){
                if(board[i][j] == 2 || j >= boardHeight - 3 || i < 2 || i >= boardWidth - 2){
                    return;
                }
            }
        }
    }

    //旋转
    for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
        for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
            board[i][j] = temp[i - gameBlock.x][j - gameBlock.y];
            gameBlock.block[i - gameBlock.x][j - gameBlock.y] = temp[i - gameBlock.x][j - gameBlock.y];
        }
    }

}



//键盘响应
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_A){
        if(checkMove(LEFT)){
            moveLeft();
            //更新画面
            update();
        }
    } else if(event->key() == Qt::Key_D){
        if(checkMove(RIGHT)){
            moveRight();
            //更新画面
            update();
        }
    } else if(event->key() == Qt::Key_W){
        rotate();
        //更新画面
        update();
    } else if(event->key() == Qt::Key_S){
        game_timer = startTimer(speed_ms_up);
        paint_timer = startTimer(speed_ms_up);
    }
}

//时间恢复
void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_S){
        game_timer = startTimer(speed_ms);
        paint_timer = startTimer(speed_ms);
    }
}

//游戏暂停/继续
void MainWindow::gamePause(){
    if(timer->isActive()){
        timer->stop();
    } else {
        timer->start();
    }
}

//游戏结束
void MainWindow::gameOver(){
    ui->statusbar->showMessage("游戏结束");
    timer->stop();
}

//计时器
void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId() == game_timer){
        if(checkLand()){
            moveDown();
        } else{
            qDebug() << "2";
            for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
                for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
                    if(board[i][j] == 1){
                        board[i][j] = 2;
                    }
                }
            }
            startGame();
        }
    }

    if(event->timerId() == paint_timer){
        update();
    }
}

//开始游戏
void MainWindow::startGame(){
    game_timer = startTimer(speed_ms);
    paint_timer = startTimer(speed_ms);

    createBlock(seed, gameBlock);
    resetBlock();
}

//游戏主引擎
void MainWindow::gameEngine(){
    initGame();
}
