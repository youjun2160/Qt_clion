//
// Created by YUAN on 2024/5/8.
//

#ifndef NEW1_7_EVENTS_MAINWINDOW_H
#define NEW1_7_EVENTS_MAINWINDOW_H

#include <QWidget>
#include <QLabel>


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
    void test();

public:

    virtual void enterEvent(QEvent *event);

    virtual void leaveEvent(QEvent *event);

    virtual void keyPressEvent(QKeyEvent *event) override;



};


#endif //NEW1_7_EVENTS_MAINWINDOW_H
