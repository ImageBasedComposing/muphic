#pragma once

#ifndef COMPOSERFIGMELODY_H
#define COMPOSERFIGMELODY_H

#include "Compositors/ComposerVoice.h"
#include "Music/music_elements.h"
//#include "math_functions.h"
#include "Music/FigureMusic.h"
#include "Music/Segmento.h"
#include "Music/Nota.h"
#include "Music/TableScale.h"


class FiguresMusic;

using namespace std;

class ComposerFigMelody : public ComposerVoice
{

	protected:

		Segmento* lastSeg;
		TableScale* tableScale;

    public:
		ComposerFigMelody(ColorSystem* cs);
		ComposerFigMelody(ColorSystem* cs, TableScale* tbScale);
		virtual ~ComposerFigMelody();

		//Se pide que haga una melodia dada una figura. Devuelve el segmento con la melodia
		bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur);
		//Devuelve un segmento con la melodia a partir de una figura y la siguiente figura  a la que va a visitar.
		bool compMelodyFig(FigureMusic* f, Segmento* seg, FigureMusic* fNext, int dur);
		//Devuelve un segmento con melodia teniendo en cuenta tmb el ritmo. La duraci�n del ritmo es la misma que la melodia.
		bool compMelodyFig(FigureMusic* f, Segmento* seg, FigureMusic* fNext, Segmento* rithm);
        
/*------Getters------*/
		inline Segmento* getLastSegment(){ return lastSeg;};

/*------Setters------*/
	

		//int calcTono(float angulo, Nota* nPpal);
		//int calcDur(float longMedia, float longitud);
		//int notaFigura(FigureMusic* f);
		//void sumarArea(list< pair<string,int> >* cs, Figura* f);
		//void calcularPadres(FigureMusic* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos);


		//// tmp shit
		//int calcularNota(float angulo, int* escala);
};


#endif