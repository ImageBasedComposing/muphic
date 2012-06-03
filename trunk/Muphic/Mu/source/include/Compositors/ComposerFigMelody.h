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
		inline bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur){ return compMelodyFig(f,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){ return compMelodyFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur);

		inline bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur){ return decMelodyFig(f,seg1,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur){ return decMelodyFig(f,seg1,seg,dur,maxDur,EIGHTHNOTE);};
		bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur, int minDur){ return compMelodyFig(f, seg, dur, maxDur, minDur);};

		inline bool compBassFig(FigureMusic* f, Segmento* seg, int dur){ return compBassFig(f,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){ return compBassFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){ return compMelodyFig(f, seg, dur, maxDur, minDur);};


		/* Obsoletos */
		//Devuelve un segmento con la melodia a partir de una figura y la siguiente figura  a la que va a visitar.
		bool compMelodyFig(FigureMusic* f, Segmento* seg, FigureMusic* fNext, int dur);
		//Devuelve un segmento con melodia teniendo en cuenta tmb el ritmo. La duración del ritmo es la misma que la melodia.
		bool compMelodyFig(FigureMusic* f, Segmento* seg, FigureMusic* fNext, Segmento* rithm);
        /* Fin obsoletos*/


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