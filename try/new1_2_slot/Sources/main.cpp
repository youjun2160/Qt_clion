#include <QApplication>
#include "Headers/slottest.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SlotTest w;
    w.show();
    return QApplication::exec();
}
