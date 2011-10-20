#include <QtGui/QApplication>
#include "guimupic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuiMupic w;
    w.show();

    return a.exec();
}
