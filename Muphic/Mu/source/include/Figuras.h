#pragma once

#ifndef FIGURAS_H
#define FIGURAS_H

#include "Figura.h"
#include <list>

using namespace std;

class Figura;

class Figuras
{
    public:
        Figuras();
        virtual ~Figuras();

        /* Envoltorio de la lista stl */

		void colocarFig(Figura* f);
		void colocarPadre(Figura* f);
		void insertFig(Figura* s, int n);
		void insertPadre(Figura* s, int n);

		Figura* getFigAt(int n);
		Figura* getPadreAt(int n);

		bool emptyFig();
		bool emptyPadre();
		int sizeFig();
		int sizePadre();


    protected:
    private:
		list<Figura*> figuras;
		list<Figura*> figPadre;
};

#endif // FIGURAS_H
