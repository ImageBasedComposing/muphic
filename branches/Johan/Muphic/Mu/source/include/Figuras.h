#pragma once

#ifndef FIGURAS_H
#define FIGURAS_H

#include "FigureMusic.h"
#include "tinyxml.h"
//#include <list>
//#include <string>

using namespace std;

class FigureMusic;

class Figuras
{
	friend class Figura;

    public:
        Figuras();
        virtual ~Figuras();

		void cargar(string rutaXML);

        /* Envoltorio de la lista stl */

		void colocarFig(FigureMusic* f);
		void colocarPadre(FigureMusic* f);
		//void insertFig(Figura* s, int n);
		//void insertPadre(Figura* s, int n);

		FigureMusic* getFigAt(int n);
		FigureMusic* getPadreAt(int n);

		bool emptyFig();
		bool emptyPadre();
		int sizeFig();
		int sizePadre();

		pair<int,int> calcularCentro();

    protected:
		int sheetWidth;
		int sheetHeight;
		float vistosidadTotal;

    private:
		list<FigureMusic*> figuras;
		list<FigureMusic*> figPadres;

		void cargarRec(TiXmlNode* f, FigureMusic* padre = NULL);
};

#endif // FIGURAS_H
