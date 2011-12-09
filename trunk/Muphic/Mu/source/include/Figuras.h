#pragma once

#ifndef FIGURAS_H
#define FIGURAS_H

#include "Figura.h"
#include "tinyxml.h"
#include <list>
#include <string>

using namespace std;

class Figura;

class Figuras
{
	friend class Figura;

    public:
        Figuras();
        virtual ~Figuras();

		void cargar(string rutaXML);

        /* Envoltorio de la lista stl */

		void colocarFig(Figura* f);
		void colocarPadre(Figura* f);
		//void insertFig(Figura* s, int n);
		//void insertPadre(Figura* s, int n);

		Figura* getFigAt(int n);
		Figura* getPadreAt(int n);

		bool emptyFig();
		bool emptyPadre();
		int sizeFig();
		int sizePadre();

		pair<int,int> calcularCentro();

    protected:
		int sheetWidth;
		int sheetHeight;
		int vistosidadTotal;

    private:
		list<Figura*> figuras;
		list<Figura*> figPadres;

		void cargarRec(TiXmlNode* f, Figura* padre = NULL);
};

#endif // FIGURAS_H
