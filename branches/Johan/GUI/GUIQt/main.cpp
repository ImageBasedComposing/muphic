#include <QtGui/QApplication>
#include "guimupic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiMupic w;
    w.show();
    w.initialize();

    return a.exec();
}
