//
// Created by YUAN on 2024/5/7.
//

#ifndef NEW1_6_SOURCESFILE_MAINWINDOW_H
#define NEW1_6_SOURCESFILE_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //NEW1_6_SOURCESFILE_MAINWINDOW_H
