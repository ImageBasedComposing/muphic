//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

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

    specialCenter();
}

void Escena::specialCenter()
{
    xRight = f->getWidth();
    xLeft = 0;
    yBot = 0;
    yTop; f->getHeight();

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
    list<Vertice*>::iterator it = fig->listaVertices.end();
    it--;
    lastVertex = *it;
    it = fig->listaVertices.begin();
    currentVertex = *it;
    it++;
    nextVertex = *it;

    int n = 0;
    float radio, alpha1, alpha2, alpha, beta;

       int a;
    if (fig->listaVertices.size() == 1)
    {
        glBegin(GL_POINTS);
        glColor3f(( (float) fig->getRGB().r / 255), ( (float) fig->getRGB().g / 255), ( (float) fig->getRGB().b / 255));
        glVertex2d(lastVertex->x, lastVertex->y);
    }
    else
    {
    glBegin(GL_POLYGON);
    glColor3f(( (float) fig->getRGB().r / 255), ( (float) fig->getRGB().g / 255), ( (float) fig->getRGB().b / 255));
    while (n < fig->listaVertices.size())
    {
        if (currentVertex->centro)
        {
            Pincel* p = new Pincel(0, 0, 0);
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
            glVertex2d((*it)->x, (*it)->y);
        }

        it++;
        if (it == fig->listaVertices.end())
            it = fig->listaVertices.begin();

        lastVertex = currentVertex;
        currentVertex = nextVertex;
        nextVertex = *it;
        n++;
    }
    }
    glEnd();


    for (list<Figura*>::iterator jt = fig->hijos.begin(); jt != fig->hijos.end(); jt++)
    {
        paintFigura(*jt);
    }
}

void Escena::render()
{
        /* Origen del AVE */
        double ox = 0;
        double oy = 0;

        /* Render Origin */
        glBegin(GL_LINES);
                glColor3f(1.0f, 0.1f, 0.1f);
                glVertex2d(ox - 10, oy);
                glVertex2d(ox + 10, oy);
                glVertex2d(ox, oy - 10);
                glVertex2d(ox, oy + 10);
        glEnd();


        Figura* m;
        for (list<Figura*>::iterator it = f->figPadres.begin(); it != f->figPadres.end(); it++)
        {
            glColor3f(1.0f, 1.0f, 1.0f);
            paintFigura(*it);
        }

        // BOUNDARIES
        glBegin(GL_LINE_LOOP);
            glColor3f(0.1f, 0.95f, 1.0f);
            glVertex2d(0, 0);
            glVertex2d(0, f->sheetHeight);
            glVertex2d(f->sheetWidth, f->sheetHeight);
            glVertex2d(f->sheetWidth, 0);
        glEnd();
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
    GLfloat ox = (xRight + xLeft)/2;
    GLfloat oy = (yTop + yBot)/2;

    GLfloat dx = x - ox;
    GLfloat dy = y - oy;

    GLfloat nxRight = xRight + dx;
    GLfloat nxLeft = xLeft + dx;
    GLfloat nyTop = yTop + dy;
    GLfloat nyBot = yBot + dy;

    xRight = nxRight;
    xLeft = nxLeft;
    yTop = nyTop;
    yBot = nyBot;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLeft, xRight, yBot, yTop);

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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLeft, xRight, yBot, yTop);
}

std::pair<GLfloat, GLfloat> Escena::pvToAve(int pvx, int pvy, int cw, int ch)
{
    GLfloat xScale = 1, yScale = 1;
    xScale = (xRight - xLeft) / (float) cw;
    yScale = (yTop - yBot) / (float)ch ;
    return std::make_pair(pvx*xScale + xLeft,
                        (clientH-pvy)*yScale + yBot);
}

