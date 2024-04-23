//
// Created by YUAN on 2024/4/23.
//

#ifndef NEW1_1_CREATE_FIRST_WINDOW_MAINWINDOW_H
#define NEW1_1_CREATE_FIRST_WINDOW_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //NEW1_1_CREATE_FIRST_WINDOW_MAINWINDOW_H
