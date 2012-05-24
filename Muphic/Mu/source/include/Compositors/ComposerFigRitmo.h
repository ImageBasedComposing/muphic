#pragma once

#ifndef COMPOSERFIGRITMO_H
#define COMPOSERFIGRITMO_H

#include "math_functions.h"
#include "Compositors/ComposerVoice.h"
#include "Music/Nota.h"

class ComposerFigRitmo : public ComposerVoice
{
    public:
		ComposerFigRitmo(ColorSystem* cs);
		ComposerFigRitmo(ColorSystem* cs, TableScale* tb);
		virtual ~ComposerFigRitmo();

		//Se pide que haga un ritmo dada una figura. Devuelve el segmento con el ritmo, de duracion dur
		inline bool compRythmFig(FigureMusic* f, Segmento* seg, int dur){ return compRythmFig(f,seg,dur,4,false);}
		bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int compas = 4, bool quick = false);

	protected:

	private:
		int getDrumTone();
};


#endif