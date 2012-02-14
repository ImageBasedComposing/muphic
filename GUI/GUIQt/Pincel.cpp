//---------------------------------------------------------------------------
#include "Pincel.h"

//---------------------------------------------------------------------------

PV2D::PV2D(float x, float y, bool vector)
{
    this->x = x;
    this->y = y;
    this->vector = vector;
}

PV2D::~PV2D()
{
}

float PV2D::getX()
{
    return x;
}

float PV2D::getY()
{
    return y;
}

void PV2D::setX(float px)
{
    x = px;
}

void PV2D::setY(float py)
{
    y = py;
}

// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------

Pincel::Pincel(float x, float y, float angulo)
{
    posicion = new PV2D(x,y);
    direccion = angulo;
}

Pincel::Pincel(PV2D* posicion, float angulo)
{
    this->posicion = posicion;
    direccion = angulo;}

Pincel::~Pincel()
{
    delete posicion;
}

void Pincel::setPoints(QVector<QPointF>* p)
{
    points = p;
}

void Pincel::moveTo(PV2D* p)
{
    delete posicion;
    posicion = p;
}

void Pincel::moveTo(float x, float y)
{
    PV2D* p = new PV2D(x,y);
    moveTo(p);
}

void Pincel::lineTo(PV2D* p)
{
    //glBegin(GL_LINES);
        /*glVertex2f(posicion->getX(),posicion->getY());
        glVertex2f(p->getX(),p->getY());*/
    //glEnd();
    points->push_back(QPointF(posicion->getX(),height - posicion->getY()));
    points->push_back(QPointF(p->getX(),height - p->getY()));


    delete posicion;
    posicion = p;
}

void Pincel::lineTo(float x, float y)
{
    PV2D* p = new PV2D(x,y);
    lineTo(p);
}

void Pincel::turnTo(float angulo)
{
    this->direccion = angulo;
}

void Pincel::turn(float delta)
{
    direccion += delta;
}

void Pincel::forward(float dist, bool pinta)
{
    float nx = posicion->getX() + dist*cos(direccion*PI/180);
    float ny = posicion->getY() + dist*sin(direccion*PI/180);

    //glBegin(GL_LINES);
      //  glColor3f(1.0f, 1.0f, 1.0f);
        /*glVertex2d(posicion->getX(),posicion->getY());
        glVertex2d(nx,ny);*/
    //glEnd();
     points->push_back(QPointF(posicion->getX(),height - posicion->getY()));
      points->push_back(QPointF(nx,height - ny));

    delete posicion;
    posicion = new PV2D(nx,ny);
}

void Pincel::arco(PV2D* centro, float radio, float alpha, float beta, int lados)
{
    float incr = (beta/lados) * (PI/180);
    alpha *= PI/180;

    float x = cos(alpha)*radio + centro->getX();
    float y = sin(alpha)*radio + centro->getY();
    moveTo(x,y);

    for (int i = 0; i < lados; i++)
    {
        alpha += incr;
        x = centro->getX() + radio*cos(alpha);
        y = centro->getY() + radio*sin(alpha);

        lineTo(x,y);
    }

    return;
}

void Pincel::regularPolygon(PV2D* centro, int nLados, float lengthLado)
{
    float b = 2*PI / nLados;
    float r = lengthLado / (2*sin(b/2));
    float g = ((PI + b)/2)*(180/PI);
    PV2D* p = new PV2D(centro->getX()+r, centro->getY());
    regularPorygon(lengthLado, nLados, p, g);
}

void Pincel::regularPorygon(float lado, int nLados, PV2D* from, float alpha)
{
    moveTo(from);
    turnTo(alpha);
    for (int i = 0; i < nLados; i++)
    {
        forward(lado, true);
        turn(((2*PI) * (180/PI))/(float) nLados);
    }
}

// if the current polyline is a regular polygon, this will draw gay arcs between
// adjacent vertex. If it's not, i really don't want to know.
void Pincel::rosePolygon(int segmentos)
{
}
