#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
#include "recitewords.h"
#include "recitewrongwords.h"
#include "search.h"
#include "setting.h"
#include <QStackedWidget>

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

private:
    //创建一个堆栈窗口
    QStackedWidget *stackedWidget;

    //实例化窗口
    MainMenu *mainMenu;
    ReciteWords *reciteWords;
    ReciteWrongWords *reciteWrongWords;
    Setting *setting;
    Search *search;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
