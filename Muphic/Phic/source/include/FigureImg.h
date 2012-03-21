#pragma once

#ifndef FIGUREIMG_H
#define FIGUREIMG_H

#include "Figura.h"


using namespace std;

class FigureImg : public Figura
{
	friend class Figuras;

    public:
		FigureImg();
        virtual ~FigureImg();

		static bool compare(FigureImg* f1, FigureImg* f2);

    protected:
		

	private:
};

#endif // FIGUREIMG_H
