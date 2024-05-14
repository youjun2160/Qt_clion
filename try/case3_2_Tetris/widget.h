#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPainter>
#include <QLabel>
#include <QlcdNumber>
#include <QTimer>
#include <QPushButton>

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

    int board[12][20] = {0};
    //预告方块显示板
    int board2[4][4] = {0};

    virtual void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
