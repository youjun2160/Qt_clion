//
// Created by YUAN on 2024/4/18.
//

#ifndef TRY1_1_MAINWINDOW_H
#define TRY1_1_MAINWINDOW_H

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
    void on_btnSet_clicked();

private:
    Ui::MainWindow *ui;
};


#endif //TRY1_1_MAINWINDOW_H
