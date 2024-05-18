#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    this->setFixedSize(margin * 2 + (boardWidth - 4) * cellSize + 4 * cellSize + 40, margin * 2 + (boardHeight - 6) * cellSize);
    this->setWindowTitle("俄罗斯方块");

    //this->setStyleSheet("background-color: black");

    QLabel *label = new QLabel(this);
    QFont font;
    font.setPointSize(15);
    label->setFont(font);
    label->setText("Score: ");
    label->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 150);

    lcd = new QLCDNumber(this);
    lcd->display(score);
    lcd->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 180);

    //测试按钮
    QPushButton *button = new QPushButton(this);
    button->setText("开始游戏");
    button->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 230);
    connect(button, &QPushButton::clicked, this, &MainWindow::startGame);

    //测试按钮2
    QPushButton *button2 = new QPushButton(this);
    button2->setText("暂停/开始");
    button2->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 280);
    connect(button2, &QPushButton::clicked, this, &MainWindow::gamePause);

    //测试按钮3
    QPushButton *button3 = new QPushButton(this);
    button3->setText("重置");
    button3->move(margin + (boardWidth - 4) * cellSize + 40, margin + 4 * cellSize + 330);
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
            if(nextBlock.block[i][j] == 0){
                color = QColor(Qt::white);
            }else if(nextBlock.block[i][j] == 1){
                color = nextBlock.color;
            }
            //计算坐标
            int x = margin + (boardWidth - 4) * cellSize + 40 + i * cellSize;
            int y = margin + j * cellSize;
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
            nextBlock.block[i][j] = 0;
        }
    }

    if(!isGamePause){
        isGamePause = true;
        killTimer(game_timer);
        killTimer(paint_timer);
    }

    gameBlock.isExit = false;
    isStart = false;
    update();

}

//方块复制
void MainWindow::copyBlock(int src[4][4], int des[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            des[i][j] = src[i][j];
        }
    }
}

//创建新方块到下一个方块
void MainWindow::createBlock(int seed, Block &wBlock){
    //根据时间设置种子
    // 使用高精度时钟获取当前时间
    auto now = std::chrono::high_resolution_clock::now();

    // 转换时间为微秒
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();

    // 使用微秒时间戳作为种子
    std::mt19937 generator(microseconds);

    // 生成随机数
    std::uniform_int_distribution<int> distribution(1, 100);
    seed = distribution(generator);
    //方块复制
    switch (seed % 7) {
    case 0:
        copyBlock(item1, wBlock.block);
        break;
    case 1:
        copyBlock(item2, wBlock.block);
        break;
    case 2:
        copyBlock(item3, wBlock.block);
        break;
    case 3:
        copyBlock(item4, wBlock.block);
        break;
    case 4:
        copyBlock(item5, wBlock.block);
        break;
    case 5:
        copyBlock(item6, wBlock.block);
        break;
    case 6:
        copyBlock(item7, wBlock.block);
        break;
    default:
        break;
    }

    //随机颜色
    wBlock.color = QColor(rand() % 256, rand() % 256, rand() % 256);

    wBlock.isExit = true;

}



//放置方块进游戏
void MainWindow::resetBlock(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i + 6][j] = nextBlock.block[i][j];
        }
    }
    //设置方块坐标
    gameBlock.x = 6;
    gameBlock.y = 0;

    gameBlock.color = nextBlock.color;
}


//计时器
void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId() == game_timer){
        if(checkLand()){
            moveDown();
        } else{
            for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
                for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
                    if(board[i][j] == 1){
                        board[i][j] = 2;
                    }
                }
            }
            //判断是否加分
            addScore();
            //判断是否游戏失败
            gameOver();
            startGame();
        }
    }

    if(event->timerId() == paint_timer){
        update();
    }
}

//开始游戏
void MainWindow::startGame(){

    if(isGamePause){
        isGamePause = false;
        game_timer = startTimer(speed_ms);
        paint_timer = startTimer(speed_ms);
    } else{
        isGamePause = false;
        game_timer = startTimer(speed_ms);
        paint_timer = startTimer(speed_ms);

        if(nextBlock.isExit == false){
            createBlock(seed, nextBlock);
        }


        copyBlock(nextBlock.block, gameBlock.block);
        resetBlock();
        createBlock(seed, nextBlock);
    }




    // if(isGamePause){
    //     isGamePause = false;
    //     game_timer = startTimer(speed_ms);
    //     paint_timer = startTimer(speed_ms);
    // } else{
    //     if(isStart){
    //         if(nextBlock.isExit == false){
    //             createBlock(seed, nextBlock);
    //         }

    //         copyBlock(nextBlock.block, gameBlock.block);
    //         resetBlock();
    //         createBlock(seed, nextBlock);
    //     } else {
    //         game_timer = startTimer(speed_ms);
    //         paint_timer = startTimer(speed_ms);
    //         isStart = true;
    //     }

    // }

}

//得分
void MainWindow::addScore(){
    for(int j = boardHeight - 3; j > 3; j--){
        for(int i = 2; i < boardWidth - 2; i++){
            if(board[i][j] != 2){
                break;
            }

            if(i == boardWidth - 3){

                score += 10;

                lcd->display(score);

                for(int k = 2; k < boardWidth - 2; k++){
                    board[k][j] = 0;
                }
                moveDownAfterClear(j - 1);
                j++;
            }
        }
    }
}

//消除方块后下落
void MainWindow::moveDownAfterClear(int layer){
    for(int i = layer; i > 3; i--){
        for(int j = 2; j < boardWidth - 2; j++){
            if(board[j][i] == 2){
                board[j][i] = 0;
                board[j][i + 1] = 2;
            }
        }
    }
}

//方块下落
void MainWindow::moveDown(){
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

//检测左右移动是否被阻挡
bool MainWindow::checkMove(enum MoveType type){
    if(type == LEFT){
        for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
            for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
                if((board[i][j] == 1 && i <= 2) || (board[i][j] == 1 && board[i - 1][j] == 2)){
                    return false;
                }
            }
        }
    } else if(type == RIGHT){
        for(int i = gameBlock.x; i < gameBlock.x + 4; i++){
            for(int j = gameBlock.y; j < gameBlock.y + 4; j++){
                if((board[i][j] == 1 && i >= boardWidth - 3) || (board[i][j] == 1 && board[i + 1][j] == 2)){
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
            if(board[i][j] != 2){
                board[i][j] = temp[i - gameBlock.x][j - gameBlock.y];
                gameBlock.block[i - gameBlock.x][j - gameBlock.y] = temp[i - gameBlock.x][j - gameBlock.y];
            }
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
    if(isGamePause){
        isGamePause = false;
        game_timer = startTimer(speed_ms);
        paint_timer = startTimer(speed_ms);
    } else{
        isGamePause = true;
        killTimer(game_timer);
        killTimer(paint_timer);
    }

}

//游戏结束
void MainWindow::gameOver(){
    //判断是否游戏结束
    for(int i = 0; i <= 4; i++){
        for(int j = 2; j < boardWidth - 2; j++){
            if(board[j][i] == 2){
                if(!isGamePause){
                    QMessageBox::information(this, "提示", "游戏结束");
                    killTimer(game_timer);
                    killTimer(paint_timer);
                    isGamePause = true;
                }
            }
        }
    }
}

