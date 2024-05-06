//
// Created by YUAN on 2024/4/28.
//

#ifndef NEWPROJECT_1_CALCULATOR_MAINWINDOW_H
#define NEWPROJECT_1_CALCULATOR_MAINWINDOW_H

#include <QWidget>

enum BtnType{
    Num,//数字
    point,//点
    op,//运算符
    equal,//等于
    ac,//ac
    deleate//删除
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    QString NUM1;
    QString NUM2;
    QString OP;
    QString RESULT;

public slots:
    void OnClicked(BtnType type, QString num);

private:
    Ui::MainWindow *ui;
};


#endif //NEWPROJECT_1_CALCULATOR_MAINWINDOW_H
