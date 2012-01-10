#pragma once

#ifndef FIGUREMUSIC_H
#define FIGUREMUSIC_H

#include "Figura.h"


using namespace std;

class FigureMusic : public Figura
{
	friend class Figuras;

    public:
		FigureMusic();
        virtual ~FigureMusic();

		float getVistosidad();
		float calcularVistosidad(int sHeight, int sWidth);
		void setVistosidad(float v);

		static bool compare(FigureMusic* f1, FigureMusic* f2);

    protected:
		float vistosidad;
};

#endif // FIGUREMUSIC_H
