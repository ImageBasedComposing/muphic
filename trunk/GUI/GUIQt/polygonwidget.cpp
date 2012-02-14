#include "polygonwidget.h"

#include "QScrollArea.h"

PolygonWidget::PolygonWidget(QWidget *parent) :
    QWidget(parent)
{
    scene = new Escena(0,0,0,0);
    scene->cargar("test1");


    /*QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(this);*/
}


void PolygonWidget::paintEvent(QPaintEvent *event)
{

    /*QPainter* painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
    painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter->drawEllipse(80, 80, 400, 240);
    delete painter;*/
    scene->render(this);
}
