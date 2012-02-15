#ifndef POLYGONWIDGET_H
#define POLYGONWIDGET_H

#include <QWidget>
#include "qpainter.h"
#include "Escena.h"

class Escena;

class PolygonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PolygonWidget(QWidget *parent = 0);

signals:

public slots:

    void paintEvent(QPaintEvent *event);

protected:
    Escena* scene;
    bool loaded;

public:
    void load(std::string path);
};

#endif // POLYGONWIDGET_H
