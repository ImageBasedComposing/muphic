#pragma once

#ifndef COMPOSERFIGMELODY_H
#define COMPOSERFIGMELODY_H

#include "Composer.h"
#include "music_elements.h"
#include "math_functions.h"
#include "Figuras.h"
#include "Segmento.h"
#include "Nota.h"
#include "TableScale.h"


class Figuras;

using namespace std;

class ComposerFigMelody
{
    public:
		ComposerFigMelody();
		ComposerFigMelody(TableScale* tbScale);
		virtual ~ComposerFigMelody();

/*------Getters------*/
		inline Segmento* getLastSegment(){ return lastSeg;};

/*------Setters------*/
        

	protected:

		Segmento* lastSeg;
		TableScale* tableScale;

	private:
		//Se pide que haga una melodia dada una figura. Devuelve el segmento con la melodia
		bool compMelodyFig(Figura* f, Segmento* seg, int dur);
		//Devuelve un segmento con la melodia a partir de una figura y la siguiente figura  a la que va a visitar.
		bool compMelodyFig(Figura* f, Segmento* seg, Figura* fNext, int dur);
		//Devuelve un segmento con melodia teniendo en cuenta tmb el ritmo. La duración del ritmo es la misma que la melodia.
		bool compMelodyFig(Figura* f, Segmento* seg, Figura* fNext, Segmento* rithm);

		//int calcTono(float angulo, Nota* nPpal);
		//int calcDur(float longMedia, float longitud);
		//int notaFigura(Figura* f);
		//void sumarArea(list< pair<string,int> >* cs, Figura* f);
		//void calcularPadres(Figura* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos);


		//// tmp shit
		//int calcularNota(float angulo, int* escala);
};


#endif