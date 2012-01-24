#pragma once

#ifndef FIGURAS_H
#define FIGURAS_H

#include "Figura.h"
#include "tinyxml.h"
//#include <list>
//#include <string>
#include "aux_functions.h"


using namespace std;

//class FigureMusic;

class Figuras
{
	friend class Figura;

    public:
        Figuras();
        virtual ~Figuras();

		void cargar(string rutaXML);
		void guardar(string rutaXML);

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

		/* Getters */
		int getHeight();
		int getWidth();
		int getTotalVertices();
		int getTotalArea();
		//list<Figura*>* getFiguras();
		//list<Figura*>* getFigPadre();

		void setWidth(int h) {	sheetHeight = h; }
		void setHeight(int w) { sheetWidth = w; }
		void setTotalVertices(int v) { totalVertices = v; }
		void setTotalArea(int a) { totalArea = a; }

    protected:
		int sheetWidth;
		int sheetHeight;
		//Numero total de vértices
		int totalVertices;
		//Area que abarcan todas las figuras
		int totalArea;
		list<Figura*> figuras;
		list<Figura*> figPadres;

		void cargarRec(TiXmlNode* f, Figura* padre = NULL);
		void guardarRec(TiXmlElement* f, Figura* id);
		virtual Figura* createFigure();
    private:
};

#endif // FIGURAS_H
