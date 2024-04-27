#include <QApplication>
#include "Headers/widget.h"
#include "Headers/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.show();

    MainWindow k;
    k.show();
    return QApplication::exec();
}
