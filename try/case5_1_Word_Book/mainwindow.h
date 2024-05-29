#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:

private:
    //创建一个堆栈窗口
    QStackedWidget *stackedWidget;

    //创建按钮
    QPushButton *btn_reciteWords;
    QPushButton *btn_reciteWrongWords;
    QPushButton *btn_wordsSet;
    QPushButton *btn_Exit;
    QPushButton *btn_search;

    //创建一个指针指向窗口类中的窗口，目的是为了在堆栈窗口中切换窗口
    QWidget *main;
    QWidget *reciteWords;
    QWidget *reciteWrongWords;
    QWidget *wordsSet;
    QWidget *search;



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
