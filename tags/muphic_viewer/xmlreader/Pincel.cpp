//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pincel.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

PV2D::PV2D(GLfloat x, GLfloat y, bool vector)
{
    this->x = x;
    this->y = y;
    this->vector = vector;
};

PV2D::~PV2D()
{
}

GLfloat PV2D::getX()
{
    return x;
};

GLfloat PV2D::getY()
{
    return y;
};

void PV2D::setX(GLfloat px)
{
    x = px;
};

void PV2D::setY(GLfloat py)
{
    y = py;
};

// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------

Pincel::Pincel(GLfloat x, GLfloat y, GLfloat angulo)
{
    posicion = new PV2D(x,y);
    direccion = angulo;
}

Pincel::Pincel(PV2D* posicion, GLfloat angulo)
{
    this->posicion = posicion;
    direccion = angulo;}

Pincel::~Pincel()
{
    delete posicion;
}

void Pincel::moveTo(PV2D* p)
{
    delete posicion;
    posicion = p;
}

void Pincel::moveTo(GLfloat x, GLfloat y)
{
    PV2D* p = new PV2D(x,y);
    moveTo(p);
}

void Pincel::lineTo(PV2D* p)
{
    //glBegin(GL_LINES);
        glVertex2f(posicion->getX(),posicion->getY());
        glVertex2f(p->getX(),p->getY());
    //glEnd();


    delete posicion;
    posicion = p;
}

void Pincel::lineTo(GLfloat x, GLfloat y)
{
    PV2D* p = new PV2D(x,y);
    lineTo(p);
}

void Pincel::turnTo(GLfloat angulo)
{
    this->direccion = angulo;
}

void Pincel::turn(GLfloat delta)
{
    direccion += delta;
}

void Pincel::forward(GLfloat dist, bool pinta)
{
    GLfloat nx = posicion->getX() + dist*cos(direccion*PI/180);
    GLfloat ny = posicion->getY() + dist*sin(direccion*PI/180);

    //glBegin(GL_LINES);
      //  glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(posicion->getX(),posicion->getY());
        glVertex2d(nx,ny);
    //glEnd();

    delete posicion;
    posicion = new PV2D(nx,ny);
}

void Pincel::arco(PV2D* centro, GLfloat radio, GLfloat alpha, GLfloat beta, int lados)
{
    GLfloat incr = (beta/lados) * (PI/180);
    alpha *= PI/180;

    GLfloat x = cos(alpha)*radio + centro->getX();
    GLfloat y = sin(alpha)*radio + centro->getY();
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
    GLfloat b = 2*PI / nLados;
    GLfloat r = lengthLado / (2*sin(b/2));
    GLfloat g = ((PI + b)/2)*(180/PI);
    PV2D* p = new PV2D(centro->getX()+r, centro->getY());
    regularPorygon(lengthLado, nLados, p, g);
}

void Pincel::regularPorygon(float lado, int nLados, PV2D* from, GLfloat alpha)
{
    moveTo(from);
    turnTo(alpha);
    for (int i = 0; i < nLados; i++)
    {
        forward(lado, true);
        turn(((2*PI) * (180/PI))/(float) nLados);
    }
}

// returns the angle a vector (x2-x1,y2-y1) with the x axis
double vectorAngle(int x1, int x2, int y1, int y2)
{
	// angle = acos((x2 - x1) / module)
	// it's important to check sin's behaviour as well
    double module = sqrt(pow((float) x2 - x1, 2) + pow((float)y2 - y1, 2));

	double angle;
	double cos = ((double) x2 - x1) / (double) module;
	double sin = ((double) y2 - y1) / (double) module;
	if (sin >= 0)
	{
		angle = acos(cos); // sin 0 gives angle 0, not 360
	}
	else
	{
		angle = 2*PI - acos(cos);
	}
	// cast to decimal angles
	angle *= (180/PI);

	return angle;
}

// if the current polyline is a regular polygon, this will draw gay arcs between
// adjacent vertex. If it's not, i really don't want to know.
void Pincel::rosePolygon(int segmentos)
{
}
