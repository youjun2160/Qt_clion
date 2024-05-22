#ifndef MAP_H
#define MAP_H

#include <QMainWindow>

enum blockType
{
    none,
    solid,
    platform
};

class Map : public QMainWindow
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);

    //地图大小
    QSize size = QSize(1960, 830);

    //实体方块区域
    QRect rect = QRect(0, 672, 1960, 158);

    //平台区域
    QRect platform1 = QRect(0, 206, 1960, 8);

    //实体方块区域
    QRect rect2 = QRect(0, 386, 1960, 8);

    //平台区域
    QRect platform3 = QRect(0, 534, 1960, 8);

signals:
};

#endif // MAP_H
