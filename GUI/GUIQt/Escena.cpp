//---------------------------------------------------------------------------

#include "Escena.h"

//---------------------------------------------------------------------------

Escena::Escena(float left, float right, float top, float bot)
{
    xRight = right;
    xLeft = left;
    yTop = top;
    yBot = bot;

    clientW = xRight - xLeft;
    clientH = yTop - yBot;

    zoom = 1.0f;
    centerX = (xRight + xLeft)/2;
    centerY = (yTop + yBot)/2;

    name = "New Scene";

    f = NULL;
}

Escena::~Escena()
{
    delete f;
}

void Escena::cargar(std::string file)
{
    if (f != NULL)
        delete f;
    f = new Figuras();
    f->cargar(file);

    iWidth = f->getWidth();
    iHeight = f->getHeight();

    specialCenter();
}

void Escena::specialCenter()
{
    xRight = f->getWidth();
    xLeft = 0;
    yBot = 0;
    yTop = f->getHeight();

    centerX = (xRight + xLeft)/2;
    centerY = (yTop + yBot)/2;
    zoom = 1.0f;
}

void Escena::resize(int width, int height)
{
    float ratioVolVista = (xRight - xLeft)/(yTop - yBot);
    float ratioViewPort = (float)width/(float)height;

    if (ratioViewPort == ratioVolVista)
        return;

    float newH = yTop - yBot;
    float newW = xRight - xLeft;

    if (ratioVolVista >= ratioViewPort)
    {
        newH = newW / ratioViewPort;

        yTop = centerY + newH / 2;
        yBot = centerY - newH / 2;
     }
    else
    {
        newW = newH * ratioViewPort;

        xRight = centerX + newW / 2;
        xLeft = centerX - newW / 2;
     }

     clientW = width;
     clientH = height;
}


void Escena::paintFigura(Figura* fig)
{
    Vertice* lastVertex;
    Vertice* currentVertex;
    Vertice* nextVertex;
    list<Vertice*> tmpList = fig->getVertices();
    list<Vertice*>::iterator it = tmpList.end();
    it--;
    lastVertex = *it;
    it = tmpList.begin();
    currentVertex = *it;
    it++;
    nextVertex = *it;

    int n = 0;
    float radio, alpha1, alpha2, alpha, beta;

       int a;


       QVector<QPointF>* points = new QVector<QPointF>();
      /* points.push_back(QPointF(0, 0));
       points.push_back(QPointF(0,  f->getHeight()));
       points.push_back(QPointF(f->getWidth(), f->getHeight()));
       points.push_back(QPointF(f->getWidth(), 0));

       painter->drawPolygon(points);*/




    if (tmpList.size() == 1)
    {
        painter->setBrush(QBrush(QColor(( (float) fig->getRGB().r / 255), ( (float) fig->getRGB().g / 255), ( (float) fig->getRGB().b / 255))));
        points->push_back(QPointF(lastVertex->x, /*yTop - */lastVertex->y));
    }
    else
    {
    painter->setBrush(QBrush(QColor(( (float) fig->getRGB().r), ( (float) fig->getRGB().g), ( (float) fig->getRGB().b))));
    while (n < tmpList.size())
    {
        if (currentVertex->centro)
        {
            Pincel* p = new Pincel(0, 0, 0);
            p->width = xRight;
            p->height = yTop;
            p->setPoints(points);
            radio = vectorModule(currentVertex->x, nextVertex->x, currentVertex->y, nextVertex->y);
            alpha1 = vectorAngle(currentVertex->x, lastVertex->x, currentVertex->y, lastVertex->y);
            alpha2 = vectorAngle(currentVertex->x, nextVertex->x, currentVertex->y, nextVertex->y);

            if (alpha1 < 0)  alpha1 += 360;
            if (alpha2 < 0)  alpha2 += 360;

            if (alpha1 > alpha2)
            {
                alpha = alpha2;
                beta = alpha1 - alpha2;
            }
            else
            {
                alpha = alpha1;
                beta = alpha2 - alpha1;
            }

            if (beta == 0)
                beta = 360;

            PV2D* test = new PV2D(currentVertex->x, currentVertex->y);
            p->arco(test, radio, alpha, beta, 1000);
            delete test;
            delete p;
        }
        else
        {
            points->push_back(QPointF((*it)->x, /*yTop -*/ (*it)->y));
        }

        it++;
        if (it == tmpList.end())
            it = tmpList.begin();

        lastVertex = currentVertex;
        currentVertex = nextVertex;
        nextVertex = *it;
        n++;
    }
    }

    painter->drawPolygon(*points, Qt::WindingFill);
    delete points;

    list<Figura*> tmpHijos = fig->getHijos();
    for (list<Figura*>::iterator jt = tmpHijos.begin(); jt != tmpHijos.end(); jt++)
    {
        paintFigura(*jt);
    }
}

void Escena::render(PolygonWidget* widget)
{
        painter = new QPainter(widget);

        painter->setBrush(QBrush(QColor(255, 255, 255)));
        painter->setPen(QPen(Qt::blue, 0, Qt::NoPen));
        QVector<QPointF> points;
        /*points.push_back(QPointF(0, 0));
        points.push_back(QPointF(0,  f->getHeight()));
        points.push_back(QPointF(f->getWidth(), f->getHeight()));
        points.push_back(QPointF(f->getWidth(), 0));*/
        points.push_back(QPointF(0, 0));
        points.push_back(QPointF(0,  widget->height()));
        points.push_back(QPointF(widget->width(), widget->height()));
        points.push_back(QPointF(widget->width(), 0));


        painter->drawPolygon(points);

        Figura* m;
        list<Figura*> tmpList = f->getPadres();
        for (list<Figura*>::iterator it = tmpList.begin(); it != tmpList.end(); it++)
        {
            painter->setBrush(QBrush(QColor(255, 255, 255)));
            paintFigura(*it);
        }


        // outline
        painter->setPen(QPen(QColor(0.1f*255, 0.95f*255, 1.0f*255), 1));
        painter->drawLine(QPointF(0,0), QPointF(0,  f->getHeight()));
        painter->drawLine(QPointF(0,  f->getHeight()), QPointF(f->getWidth(), f->getHeight()));
        painter->drawLine(QPointF(f->getWidth(), f->getHeight()), QPointF(f->getWidth(), 0));
        painter->drawLine(QPointF(f->getWidth(), 0),QPointF(0,0));

        delete painter;
}

void Escena::zoomize(float factor)
{
    xLeft /= factor;
    xRight /= factor;
    yTop /= factor;
    yBot /= factor;

    zoom *= factor;

    centerAt(centerX, centerY);
}

void Escena::zoomIn()
{
    zoomize(1.2);
}

void Escena::zoomOut()
{
    zoomize(0.8);
}

void Escena::centerAt(float x, float y)
{
    float ox = (xRight + xLeft)/2;
    float oy = (yTop + yBot)/2;

    float dx = x - ox;
    float dy = y - oy;

    float nxRight = xRight + dx;
    float nxLeft = xLeft + dx;
    float nyTop = yTop + dy;
    float nyBot = yBot + dy;

    xRight = nxRight;
    xLeft = nxLeft;
    yTop = nyTop;
    yBot = nyBot;

    /*glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLeft, xRight, yBot, yTop);*/

    centerX = x;
    centerY = y;
}

void Escena::centerOrigin()
{
    centerAt(0, 0);
}

void Escena::move(float dx, float dy)
{
    yBot += dy;
    yTop += dy;
    xLeft += dx;
    xRight += dx;

    centerX = (xRight + xLeft)/2;
    centerY = (yTop + yBot)/2;

   /* glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLeft, xRight, yBot, yTop);*/
}

std::pair<float, float> Escena::pvToAve(int pvx, int pvy, int cw, int ch)
{
    float xScale = 1, yScale = 1;
    xScale = (xRight - xLeft) / (float) cw;
    yScale = (yTop - yBot) / (float)ch ;
    return std::make_pair(pvx*xScale + xLeft,
                        (clientH-pvy)*yScale + yBot);
}

