#pragma once

#ifndef FIGURESMUSIC_H
#define FIGURESMUSIC_H

#include "FigureMusic.h"
#include "tinyxml.h"
#include "Figuras.h"
//#include <list>
//#include <string>

using namespace std;

class Figuras;
class FigureMusic;

class FiguresMusic:public Figuras
{
	friend class Figura;

    public:
        FiguresMusic();
        virtual ~FiguresMusic();

		void calculateVisibility();

        /* Envoltorio de la lista stl */

		//void colocarFig(FigureMusic* f);
		//void colocarPadre(FigureMusic* f);
		////void insertFig(Figura* s, int n);
		////void insertPadre(Figura* s, int n);

		//FigureMusic* getFigAt(int n);
		//FigureMusic* getPadreAt(int n);

		//bool emptyFig();
		//bool emptyPadre();
		//int sizeFig();
		//int sizePadre();

		pair<int,int> calcularCentro();

		///* Getters */
		//int getHeight();
		//int getWidth();
		//list<Figura*>* getFiguras();
		//list<Figura*>* getFigPadre();

    protected:
		//int sheetWidth;
		//int sheetHeight;
		float vistosidadTotal;

    private:
		//list<Figura*> figuras;
		//list<Figura*> figPadres;

		//void cargarRec(TiXmlNode* f, FigureMusic* padre = NULL);
		void createFigure(Figura* f);
};

#endif // FIGURAS_H