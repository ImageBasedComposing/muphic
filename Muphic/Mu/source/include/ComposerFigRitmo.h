#pragma once

#ifndef COMPOSERFIGRITMO_H
#define COMPOSERFIGRITMO_H

#include "math_functions.h"

#include "Figuras.h"
#include "Segmento.h"
#include "Nota.h"

class ComposerFigRitmo
{
    public:
		ComposerFigRitmo() {};
		virtual ~ComposerFigRitmo() {};

		//Se pide que haga un ritmo dada una figura. Devuelve el segmento con el ritmo, de duracion dur
		bool compRythmFig(Figura* f, Segmento* seg, int dur);

	protected:

	private:
		int getDrumTone(int duracion);
};


#endif