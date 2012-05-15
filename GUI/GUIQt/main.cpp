#include <QtGui/QApplication>
#include "guimupic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("MuphicGUI");
    GuiMupic w;
    w.show();
    w.initialize();

    return a.exec();
}
