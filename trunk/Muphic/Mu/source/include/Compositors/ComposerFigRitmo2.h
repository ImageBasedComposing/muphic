#pragma once

#ifndef COMPOSERFIGRITMO2_H
#define COMPOSERFIGRITMO2_H

#include "math_functions.h"

#include "Music/FiguresMusic.h"
#include "Music/FigureMusic.h"
#include "Music/Segmento.h"
#include "Music/Nota.h"

class ComposerFigRitmo2
{
    public:
		ComposerFigRitmo2() {};
		virtual ~ComposerFigRitmo2() {};

		//Se pide que haga un ritmo dada una figura. Devuelve el segmento con el ritmo, de duracion dur
		bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur = WHOLE);

	protected:

	private:
		int getDrumTone();
		int getCymbalTone();
};


#endif