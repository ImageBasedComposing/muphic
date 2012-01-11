//---------------------------------------------------------------------------

#ifndef PincelH
#define PincelH
//---------------------------------------------------------------------------
#define PI 3.14159

#include <math.h>

#include <gl\gl.h>
#include <gl\glu.h>

class PV2D
{
        protected:
            GLfloat x, y;
            bool vector;

        public:
            PV2D(GLfloat x, GLfloat y, bool vector = false);
            ~PV2D();

            GLfloat getX();
            GLfloat getY();
            void setX(GLfloat x);
            void setY(GLfloat y);
};

class Pincel
{
        protected:
            PV2D* posicion;
            GLfloat direccion;

        public:
            Pincel(GLfloat x, GLfloat y, GLfloat angulo = 0);
            Pincel(PV2D* posicion, GLfloat angulo = 0);
            ~Pincel();

            void moveTo(PV2D* p);
            void moveTo(GLfloat x, GLfloat y);
            void lineTo(PV2D* p);
            void lineTo(GLfloat x, GLfloat y);
            void turnTo(GLfloat angulo);
            void turn(GLfloat delta);
            void forward(GLfloat dist, bool pinta = true);

            void arco(PV2D* centro, GLfloat radio, GLfloat alpha, GLfloat beta, int lados);
            void regularPolygon(PV2D* centro, int nLados, float lengthLado);
            void regularPorygon(float lado, int nLados, PV2D* from, GLfloat alpha);
            void rosePolygon(int segmentos);
};

#endif
