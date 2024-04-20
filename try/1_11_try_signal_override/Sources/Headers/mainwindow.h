//
// Created by YUAN on 2024/4/20.
//

#ifndef INC_1_11_TRY_SIGNAL_OVERRIDE_MAINWINDOW_H
#define INC_1_11_TRY_SIGNAL_OVERRIDE_MAINWINDOW_H

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


#endif //INC_1_11_TRY_SIGNAL_OVERRIDE_MAINWINDOW_H
