//---------------------------------------------------------------------------

#ifndef EscenaH
#define EscenaH

#include <math.h>
#include <limits.h>

#include <list>
#include "Figuras.h"
#include "Pincel.h"
#include "polygonwidget.h"

//---------------------------------------------------------------------------

class PolygonWidget;

class Escena
{

friend class Figuras;
friend class Figura;
    public:

        double xLeft, xRight, yTop, yBot;
        double centerX, centerY;
        int clientW, clientH;
        float zoom;

        std::string name;
        Figuras* f;
        void paintFigura(Figura* fig);

        QPainter* painter;

    public:
        Escena(float left, float right, float top, float bot);
        ~Escena();

        void cargar(std::string file);
        void specialCenter();

        double getxL() { return xLeft; }
        double getxR() { return xRight; }
        double getyT() { return yTop; }
        double getyB() { return yBot; }
        float getZoom() { return zoom; }

        void resize(int width, int height);

        void zoomize(float factor);
        void zoomIn();
        void zoomOut();
        void move(float dx, float dy);
        void centerAt(float x, float y);
        void centerOrigin();

        void cohenSutherland(int x1, int y1, int x2, int y2) {}

        void render(PolygonWidget* widget);

        std::pair<float, float> pvToAve(int pvx, int pvy, int cw, int ch);
};


#endif
