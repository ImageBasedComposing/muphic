#pragma once

#ifndef COMPOSERFIGSILENCE_H
#define COMPOSERFIGSILENCE_H

#include "Compositors/ComposerVoice.h"
#include "Music/music_elements.h"
//#include "math_functions.h"
#include "Music/FigureMusic.h"
#include "Music/Segmento.h"
#include "Music/Nota.h"
#include "Music/TableScale.h"


class FiguresMusic;

using namespace std;

class ComposerFigSilence : public ComposerVoice
{

	protected:

		Segmento* lastSeg;
		TableScale* tableScale;

    public:
		ComposerFigSilence(ColorSystem* cs);
		ComposerFigSilence(ColorSystem* cs, TableScale* tbScale);
		virtual ~ComposerFigSilence();

		//Se pide que haga una melodia dada una figura. Devuelve el segmento con la melodia
		inline bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur){ return compMelodyFig(f,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){ return compMelodyFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		inline bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){ return compSilence(seg, dur);};

		inline bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur){ return decMelodyFig(f,seg1,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur){ return decMelodyFig(f,seg1,seg,dur,maxDur,EIGHTHNOTE);};
		inline bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur, int minDur){ return compSilence(seg, dur);};

		inline bool compBassFig(FigureMusic* f, Segmento* seg, int dur){ return compBassFig(f,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){ return compBassFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		inline bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){ return compSilence(seg, dur);};

		inline bool compRythmFig(FigureMusic* f, Segmento* seg, int dur){ return compRythmFig(f,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){ return compRythmFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		inline bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){ return compSilence(seg, dur);};

		bool compSilence(Segmento* seg, int dur);

/*------Getters------*/

/*------Setters------*/
};


#endif //COMPOSERFIGSILENCE_H