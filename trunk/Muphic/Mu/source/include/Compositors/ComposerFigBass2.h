#pragma once

#ifndef COMPOSERFIGBASS2_H
#define COMPOSERFIGBASS2_H

#include "Compositors/ComposerVoice.h"
#include "Music/Nota.h"


class FiguresMusic;

using namespace std;

class ComposerFigBass2 : public ComposerVoice
{

	protected:
		
    public:
		ComposerFigBass2(ColorSystem* cs);
		ComposerFigBass2(ColorSystem* cs, TableScale* tbScale);
		virtual ~ComposerFigBass2();

		//Se pide que haga un bajo dada una figura. Devuelve el segmento con el bajo acorde
		inline bool compBassFig(FigureMusic* f, Segmento* seg3, int dur){return compBassFig(f,seg3,dur,WHOLE,QUARTERNOTE);};
		inline bool compBassFig(FigureMusic* f, Segmento* seg3, int dur, int maxDur){return compBassFig(f,seg3,dur,maxDur,QUARTERNOTE);};
		bool compBassFig(FigureMusic* f, Segmento* seg3, int dur, int maxDur, int minDur);
		bool composeVoice(FigureMusic* f, Segmento* seg, int dur, int maxDur = WHOLE, int minDur = HALFNOTE, Segmento* seg1 = NULL);
		bool compBassFig(Segmento* seg1, Segmento* seg2, Segmento* seg3, int maxDur = WHOLE, int minDur = QUARTERNOTE);
		

/*------Setters------*/

};


#endif