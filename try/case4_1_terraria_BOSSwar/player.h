#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>

class player : public QMainWindow
{
    Q_OBJECT
public:
    explicit player(QWidget *parent = nullptr);

public:
    //角色在地图上的位置
    QPointF pos;

signals:
};

#endif // PLAYER_H
