#pragma once

#ifndef COMPOSERFIGMELODY2_H
#define COMPOSERFIGMELODY2_H

#include "Compositors/Composer.h"
#include "Music/music_elements.h"
//#include "math_functions.h"
#include "Music/FigureMusic.h"
#include "Music/Segmento.h"
#include "Music/Nota.h"
#include "Music/TableScale.h"


class FiguresMusic;

using namespace std;

class ComposerFigMelody2
{

	protected:

		Segmento* lastSeg;
		TableScale* tableScale;
		vector< int > calcDurDirect(FigureMusic * f, vector< Vertice* > vertices);
		vector< int > calcTonesDiff(FigureMusic * f, vector< Vertice* > vertices);

    public:
		ComposerFigMelody2();
		ComposerFigMelody2(TableScale* tbScale);
		virtual ~ComposerFigMelody2();

		//Se pide que haga una melodia dada una figura. Devuelve el segmento con la melodia
		bool compMelodyFig(FigureMusic* f, Segmento* seg);
		//Devuelve una nota dados los angulos y la duracion
		int getNextDegreeTone(int degree, double actualAngle, double lastAngle, int lastTone);

		Segmento* decMelodyFig(FigureMusic* f, Segmento* seg);
		Segmento* decSimbolo(Nota* n, int numVert, int degree);
		Segmento* dec2Simbolos(Nota* n1, Nota* n2, int degree);
		Segmento* emptyMelody(Segmento* seg);
		vector<int> patDurations(int numSimbols, int durTotal, int pattern);
		Segmento* interMelodyFig(FigureMusic* f, Segmento* seg);

/*------Getters------*/
		inline Segmento* getLastSegment(){ return lastSeg;};

/*------Setters------*/
		inline void setTableScale(TableScale* tb){ delete tableScale; tableScale = tb; };

		//int calcTono(float angulo, Nota* nPpal);
		//int calcDur(float longMedia, float longitud);
		//int notaFigura(FigureMusic* f);
		//void sumarArea(list< pair<string,int> >* cs, Figura* f);
		//void calcularPadres(FigureMusic* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos);


		//// tmp shit
		//int calcularNota(float angulo, int* escala);
};


#endif