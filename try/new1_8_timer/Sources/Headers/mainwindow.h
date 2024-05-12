//
// Created by YUAN on 2024/5/11.
//

#ifndef NEW1_8_TIMER_MAINWINDOW_H
#define NEW1_8_TIMER_MAINWINDOW_H

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

    public slots:
        void onMyButtonClicked();
};


#endif //NEW1_8_TIMER_MAINWINDOW_H
