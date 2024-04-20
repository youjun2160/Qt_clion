//
// Created by YUAN on 2024/4/20.
//

#ifndef CH2_3_HLAYOUT_MAINWINDOW_H
#define CH2_3_HLAYOUT_MAINWINDOW_H

#include <QWidget>


//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:

};


#endif //CH2_3_HLAYOUT_MAINWINDOW_H
