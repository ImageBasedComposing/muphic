#pragma once

#ifndef FIGURAS_H
#define FIGURAS_H

#include "Figura.h"
#include "tinyxml.h"
#include "aux_functions.h"
#include <iostream>
#include <set>

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
                list<Figura*> getPadres();
		//list<Figura*>* getFiguras();
		//list<Figura*>* getFigPadre();
		
		void setWidth(int w) { sheetWidth = w; }
		void setHeight(int h) {	sheetHeight = h; }
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

		bool** fillMask(Figura* f);

    public:
		void setParentSonStructure();
		void addToParentSonStructure(Figura* f, list<Figura*> & padres);
		void showParentSonStructure(list<Figura*> padres, int level);

		bool fcAreSimilar(Figura* a, Figura* b, double eps); // fastcheck
		bool lcAreSimilar(Figura* a, Figura* b, double eps); // longcheck
		// deletes repeated figures (destroys parent-son structure)
		void deleteReps();
		void showFig(Figura* f);
		void showFigs();
};

#endif // FIGURAS_H
