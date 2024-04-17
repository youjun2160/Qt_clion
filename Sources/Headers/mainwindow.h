//
// Created by YUAN on 2024/4/17.
//

#ifndef SAMPLE_1_1_MAINWINDOW_H
#define SAMPLE_1_1_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;


private slots:
    void openImage();

private:
    Ui::MainWindow *ui;
};


#endif //SAMPLE_1_1_MAINWINDOW_H
