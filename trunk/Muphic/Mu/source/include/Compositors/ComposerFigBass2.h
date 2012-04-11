#pragma once

#ifndef COMPOSERFIGBASS2_H
#define COMPOSERFIGBASS2_H

#include "Compositors/Composer.h"
#include "Music/music_elements.h"
//#include "math_functions.h"
#include "Music/FigureMusic.h"
#include "Music/Segmento.h"
#include "Music/Nota.h"
#include "Music/TableScale.h"


class FiguresMusic;

using namespace std;

class ComposerFigBass2
{

	protected:

		TableScale* tableScale;
		
    public:
		ComposerFigBass2();
		ComposerFigBass2(TableScale* tbScale);
		virtual ~ComposerFigBass2();

		//Se pide que haga un bajo dada una figura. Devuelve el segmento con el bajo acorde
		bool compBassFig(Segmento* seg1, Segmento* seg2, Segmento* seg3, int maxDur = WHOLE, int minDur = HALFNOTE);
		bool compBassFig(FigureMusic* f, int dur, Segmento* seg3, int maxDur = WHOLE, int minDur = HALFNOTE);
		

/*------Setters------*/
		inline void setTableScale(TableScale* tb){ delete tableScale; tableScale = tb; };

};


#endif