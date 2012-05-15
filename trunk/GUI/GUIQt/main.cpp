#include <QtGui/QApplication>
#include "muphicconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("MuphicGUI");
    MuphicConfig w;
    w.show();
    w.initialize();

    return a.exec();
}
