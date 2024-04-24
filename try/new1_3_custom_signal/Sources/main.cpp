#include <QApplication>
#include "Headers/customsignal.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CustomSignal w;
    w.show();
    return QApplication::exec();
}
