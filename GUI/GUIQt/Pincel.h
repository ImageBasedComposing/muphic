//---------------------------------------------------------------------------

#ifndef PincelH
#define PincelH
//---------------------------------------------------------------------------
#define PI 3.14159

#include <math.h>

#include "qpainter.h"

class PV2D
{
        protected:
            float x, y;
            bool vector;

        public:
            PV2D(float x, float y, bool vector = false);
            ~PV2D();

            float getX();
            float getY();
            void setX(float x);
            void setY(float y);
};

class Pincel
{
        protected:
            PV2D* posicion;
            float direccion;
            QVector<QPointF>* points;

        public:
            Pincel(float x, float y, float angulo = 0);
            Pincel(PV2D* posicion, float angulo = 0);
            ~Pincel();

            int width;
            int height;

            void setPoints(QVector<QPointF>* p);

            void moveTo(PV2D* p);
            void moveTo(float x, float y);
            void lineTo(PV2D* p);
            void lineTo(float x, float y);
            void turnTo(float angulo);
            void turn(float delta);
            void forward(float dist, bool pinta = true);

            void arco(PV2D* centro, float radio, float alpha, float beta, int lados);
            void regularPolygon(PV2D* centro, int nLados, float lengthLado);
            void regularPorygon(float lado, int nLados, PV2D* from, float alpha);
            void rosePolygon(int segmentos);
};

#endif
