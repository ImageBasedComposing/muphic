#pragma once

#ifndef COMPOSERFIGRITMO2_H
#define COMPOSERFIGRITMO2_H

#include "math_functions.h"
#include "Compositors/ComposerVoice.h"
#include "Music/Nota.h"

class ComposerFigRitmo2 : public ComposerVoice
{
    public:
		ComposerFigRitmo2(ColorSystem* cs);
		ComposerFigRitmo2(ColorSystem* cs, TableScale* tb);
		virtual ~ComposerFigRitmo2();

		//Se pide que haga un ritmo dada una figura. Devuelve el segmento con el ritmo, de duracion dur
		inline bool compRythmFig(FigureMusic* f, Segmento* seg, int dur){return compRythmFig(f,seg,dur,WHOLE,EIGHTHNOTE);};
		inline bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){return compRythmFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, /*fake-int*/int minDur);

		
/*------Getters------*/
		int getDrumTone();
		int getCymbalTone();

/*------Setters------*/
		void setDrumTone(int d);
		void setCymbalTone(int c);

	protected:

	private:
};


#endif