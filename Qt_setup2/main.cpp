#include "qt_setup2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_setup2 w;
    w.show();
    return a.exec();
}
