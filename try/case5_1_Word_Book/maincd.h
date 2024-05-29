#ifndef MAINCD_H
#define MAINCD_H

#include <QMainWindow>
#include <QPushButton>

class MainCD : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainCD(QWidget *parent = nullptr);

    //创建窗口
    QWidget *main;

    //创建窗口属性
    QPalette *palette;

    //创建按钮
    QPushButton *btn_reciteWords;
    QPushButton *btn_reciteWrongWords;
    QPushButton *btn_wordsSet;
    QPushButton *btn_Exit;
    QPushButton *btn_search;

signals:
};

#endif // MAINCD_H
