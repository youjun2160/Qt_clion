#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置窗口背景色为白色
    this->centralWidget->setStyleSheet("background-color: rgb(91, 54, 48);");

    //固定窗口大小
    this->setFixedSize(boardWidth * squareSize + 40 + margin * 2 + boardSize2 * squareSize, boardHeight * squareSize + margin * 2);

    //创建并初始化分数
    score = 0;
    QLabel *scoreLabel = new QLabel(this);
    // 创建一个QFont对象
    QFont font("Arial", 20, QFont::Bold);
    // 应用字体到QLabel上
    scoreLabel->setFont(font);
    // 设置QLabel显示的文本
    scoreLabel->setText("Score:");
    scoreLabel->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2);

    // 创建一个QLCDNumber对象
    QLCDNumber *lcd = new QLCDNumber(this);
    // 设置LCD显示的数字
    lcd->display(score);
    // 设置LCD显示的位置
    lcd->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2 + 40);

    //创建开始/暂停 和重置按钮
    QPushButton *startButton = new QPushButton("开始/暂停", this);
    startButton->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2 + 300);

    QPushButton *resetButton = new QPushButton("重置", this);
    resetButton->move(boardWidth * squareSize + 40 + margin , boardSize2 * squareSize + margin * 2 + 350);

    connect(startButton, &QPushButton::clicked, this, &Widget::StartGame);
    connect(resetButton, &QPushButton::clicked, this, &Widget::InitGame);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    QColor boardColor = Qt::black;

    //创建一个QPen对象来设置边框属性
    QPen borderPen(boardColor);
    borderPen.setWidth(1);

    //设置坐标
    painter.translate(margin, margin);


    //绘制每个小方格
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            int y = i * squareSize;
            int x = j * squareSize;

            //设置笔刷颜色为白色
            painter.setBrush(Qt::white);

            //在绘制之前应用边框画笔
            painter.setPen(borderPen);

            //绘制带有边框的小方格
            painter.drawRect(x, y, squareSize, squareSize);

            if (board[i][j] == 1) {
                //设置笔刷颜色为黑色
                painter.setBrush(Qt::black);

                //在绘制之前应用填充画笔
                painter.setPen(Qt::NoPen);

                //绘制黑色小方格
                painter.drawRect(x, y, squareSize, squareSize);
            }
        }
    }


    //设置坐标
    painter.translate(boardWidth * squareSize + 40 , 0);

    //绘制预告方块
    for (int i = 0; i < boardSize2; i++) {
        for (int j = 0; j < boardSize2; j++) {
            int x = j * squareSize;
            int y = i * squareSize;

            //设置笔刷颜色为白色
            painter.setBrush(Qt::white);

            //在绘制之前应用边框画笔
            painter.setPen(borderPen);

            //绘制带有边框的小方格
            painter.drawRect(x, y, squareSize, squareSize);

            if (next_block[i][j] == 1) {
                //设置笔刷颜色为黑色
                painter.setBrush(Qt::black);
                //在绘制之前应用填充画笔
                painter.setPen(Qt::NoPen);
                //绘制黑色小方格
                painter.drawRect(x, y, squareSize, squareSize);
            }
        }
    }

}


//方块拷贝
inline void block_cpy(int src[4][4], int des[4][4]){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            des[i][j] = src[i][j];
        }
    }
}

//初始化游戏
void Widget::InitGame(){
    for(int i = 0; i < boardWidth; i++){
        for(int j = 0; j < boardHeight; j++){
            board[i][j] = 0;
        }
    }

    speed_ms = 800;
    refresh_ms = 30;

    //初始化随机种子
    srand(time(0));

    //分数清零
    score = 0;

    //开始游戏
    StartGame();
}

//开始游戏
void Widget::StartGame(){
    game_timer = startTimer(speed_ms);
    paint_timer = startTimer(refresh_ms);

    //产生初始下一个方块
    int block_id = rand() % 7;
    CreateBlock(next_block,block_id);
    ResetBlock();
}

//游戏结束
void Widget::GameOver()
{
    //游戏结束停止定时器
    killTimer(game_timer);
    killTimer(paint_timer);
    QMessageBox::information(this, "failed", "game over");
}



void Widget::ResetBlock()
{
    //产生当前方块
    block_cpy(cur_block, next_block);
    GetBorder(cur_block, cur_border);

    //产生下一个方块
    int block_id = rand()%7;
    CreateBlock(next_block, block_id);

    //设置初始方块坐标，以方块左上角为锚点
    struct block_pos start_point;
    start_point.pos_x = boardHeight/2-2;
    start_point.pos_y = 0;
    block_pos = start_point;
}



void Widget::BlockMove(Direction dir)
{
    switch (dir) {
    case UP:
        if(IsCollide(block_pos.pos_x,block_pos.pos_y,UP))
            break;
        //逆时针旋转90度
        BlockRotate(cur_block);
        //防止旋转后bug,i和j从0到4重新设置方块
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                board[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
        //重新计算边界
        GetBorder(cur_block,cur_border);
        break;
    case DOWN:
        //方块到达边界则不再移动
        if(block_pos.pos_y+cur_border.dbound==boardWidth-1)
        {
            ConvertStable(block_pos.pos_x,block_pos.pos_y);
            ResetBlock();
            break;
        }
        //碰撞检测，只计算上下左右边界，先尝试走一格，如果碰撞则稳定方块后跳出
        if(IsCollide(block_pos.pos_x,block_pos.pos_y,DOWN))
        {
            //只有最终不能下落才转成稳定方块
            ConvertStable(block_pos.pos_x,block_pos.pos_y);
            ResetBlock();
            break;
        }
        //恢复方块上场景,为了清除移动过程中的方块残留
        for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
            board[block_pos.pos_y][block_pos.pos_x+j]=0;
        //没有碰撞则下落一格
        block_pos.pos_y+=1;
        //方块下降一格，拷贝到场景,注意左右边界
        for(int i=0;i<4;i++) //必须是0到4而不是边界索引，考虑到旋转后边界重新计算
            for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
                if(block_pos.pos_y+i<=boardHeight-1&&board[block_pos.pos_y+i][block_pos.pos_x+j]!=2) //注意场景数组不越界,而且不会擦出稳定的方块
                    board[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
        break;
    case LEFT:
        //到左边界或者碰撞不再往左
        if(block_pos.pos_x+cur_border.lbound==0||IsCollide(block_pos.pos_x,block_pos.pos_y,LEFT))
            break;
        //恢复方块右场景,为了清除移动过程中的方块残留
        for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
            board[block_pos.pos_y+i][block_pos.pos_x+3]=0;
        block_pos.pos_x-=1;
        //方块左移一格，拷贝到场景
        for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
            for(int j=0;j<4;j++)
                if(block_pos.pos_x+j>=0&&board[block_pos.pos_y+i][block_pos.pos_x+j]!=2) //注意场景数组不越界
                    board[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
        break;
    case RIGHT:
        if(block_pos.pos_x+cur_border.rbound==boardWidth-1||IsCollide(block_pos.pos_x,block_pos.pos_y,RIGHT))
            break;
        //恢复方块左场景,为了清除移动过程中的方块残留
        for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
            board[block_pos.pos_y+i][block_pos.pos_x]=0;
        block_pos.pos_x+=1;
        //方块右移一格，拷贝到场景
        for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
            for(int j=0;j<4;j++)
                if(block_pos.pos_x+j<=boardHeight-1&&board[block_pos.pos_y+i][block_pos.pos_x+j]!=2) //注意场景数组不越界
                    board[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
        break;
    case SPACE: //一次到底
        //一格一格下移，直到不能下移
        while(block_pos.pos_y+cur_border.dbound<boardHeight-1&&!IsCollide(block_pos.pos_x,block_pos.pos_y,DOWN))
        {
            //恢复方块上场景,为了清除移动过程中的方块残留
            for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
                board[block_pos.pos_y][block_pos.pos_x+j]=0;
            //没有碰撞则下落一格
            block_pos.pos_y+=1;
            //方块下降一格，拷贝到场景,注意左右边界
            for(int i=0;i<4;i++) //必须是0到4
                for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
                    if(block_pos.pos_y+i<=boardHeight-1&&board[block_pos.pos_y+i][block_pos.pos_x+j]!=2) //注意场景数组不越界,而且不会擦出稳定的方块
                        board[block_pos.pos_y+i][block_pos.pos_x+j]=cur_block[i][j];
        }
        ConvertStable(block_pos.pos_x,block_pos.pos_y);
        ResetBlock();
        break;
    default:
        break;
    }
    //处理消行，整个场景上面的行依次下移
    int i=boardHeight-1;
    int line_count=0; //记消行数
    while(i>=1)
    {
        bool is_line_full=true;
        for(int j=0;j<boardWidth;j++)
            if(board[i][j]==0)
            {
                is_line_full=false;
                i--;
                break;
            }
        if(is_line_full)
        {
            for(int k=i;k>=1;k--)
                for(int j=0;j<boardWidth;j++)
                    board[k][j]=board[k-1][j];
            line_count++;//每次增加消行的行数
        }
    }
    score+=line_count*10; //得分
    //判断游戏是否结束
    for(int j=0;j<boardWidth;j++)
        if(board[0][j]==2) //最顶端也有稳定方块
            GameOver();
}


void Widget::BlockRotate(int block[4][4])
{
    int temp_block[4][4];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            temp_block[3-j][i]=block[i][j];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            block[i][j]=temp_block[i][j];
}


void Widget::CreateBlock(int block[4][4], int block_id)
{
    switch (block_id)
    {
    case 0:
        block_cpy(block,item1);
        break;
    case 1:
        block_cpy(block,item2);
        break;
    case 2:
        block_cpy(block,item3);
        break;
    case 3:
        block_cpy(block,item4);
        break;
    case 4:
        block_cpy(block,item5);
        break;
    case 5:
        block_cpy(block,item6);
        break;
    case 6:
        block_cpy(block,item7);
        break;
    default:
        break;
    }
}


void Widget::GetBorder(int block[4][4], Border &border)
{
    int i = 0, j = 0;
    //计算上下左右边界
    //上边界
    for(i=3; i>=0; i--)
    {
        for(j=0; j<4; j++)
        {
            if(block[i][j] == 1)
            {
                border.ubound = i;
                break;
            }
        }
    }

    //下边界
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(block[i][j] == 1)
            {
                border.dbound = i;
                break;
            }
        }
    }

    //左边界
    for(j=3; j>=0; j--)
    {
        for(i=0; i<4; i++)
        {
            if(block[i][j] == 1)
            {
                border.lbound = j;
                break;
            }
        }
    }

    //右边界
    for(j=0; j<4; j++)
    {
        for(i=0; i<4; i++)
        {
            if(block[i][j] == 1)
            {
                border.rbound = j;
                break;
            }
        }
    }
}


void Widget::ConvertStable(int x, int y)
{
    for(int i=cur_border.ubound;i<=cur_border.dbound;i++)
        for(int j=cur_border.lbound;j<=cur_border.rbound;j++)
            if(cur_block[i][j]==1)
                board[y+i][x+j]=2; //x和y别搞反
}


bool Widget::IsCollide(int x, int y, Direction dir)
{
    int temp_block[4][4];
    block_cpy(temp_block, cur_block);

    Border temp_border;
    GetBorder(temp_block, temp_border);

    switch(dir)
    {
    case UP:
        BlockRotate(temp_block);
        GetBorder(temp_block, temp_border); //旋转后要重新计算边界
        break;

    case DOWN:
        y += 1;
        break;

    case LEFT:
        x -= 1;
        break;

    case RIGHT:
        x += 1;
        break;

    default:
        break;
    }

    for(int i=temp_border.ubound; i<=temp_border.dbound; i++)
    {
        for(int j=temp_border.lbound; j<=temp_border.rbound; j++)
        {
            if(board[y+i][x+j]==2&&temp_block[i][j]==1||x+temp_border.lbound<0||x+temp_border.rbound>boardWidth-1)
                return true;
        }
    }

    return false;
}


void Widget::timerEvent(QTimerEvent *event)
{
    //方块下落
    if(event->timerId() == game_timer)
        BlockMove(DOWN);

    //刷新画面
    if(event->timerId() == paint_timer)
        update();
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        BlockMove(UP);
        break;
    case Qt::Key_Down:
        BlockMove(DOWN);
        break;
    case Qt::Key_Left:
        BlockMove(LEFT);
        break;
    case Qt::Key_Right:
        BlockMove(RIGHT);
        break;
    case Qt::Key_Space:
        BlockMove(SPACE);
        break;
    default:
        break;
    }
}
