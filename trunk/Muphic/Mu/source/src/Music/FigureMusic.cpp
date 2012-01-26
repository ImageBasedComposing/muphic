#include "Music/FigureMusic.h"

FigureMusic::FigureMusic() : Figura()
{
	vistosidad = -1;
}

FigureMusic::~FigureMusic()
{
}

float FigureMusic::getVistosidad()
{
	return vistosidad;
}

float FigureMusic::calcularVistosidad(int sHeight, int sWidth)
{
	if (rgb.r == -1)
		return -1;
	else if (vistosidad == -1)
	{
		vistosidad = A*getSaturation()*(rgb.r*pR + rgb.g*pG + rgb.b*pB) + B*area + C*(float)distanceCenter(sHeight, sWidth);
	}
	return vistosidad;
}

void FigureMusic::setVistosidad(float v)
{
	vistosidad = v;
}


bool FigureMusic::compare(FigureMusic* f1, FigureMusic* f2) 
{
	return f1->getVistosidad() > f2->getVistosidad();
}