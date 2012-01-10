#include "Voz.h"

Voz::Voz()
{
	segmentos = new Segmentos();
	this->instrumento = DEFAULT_INSTRUMENT;
}

Voz::~Voz()
{
    delete segmentos;
}

//-----Getters-----//
int Voz::getInstrumento()
{
	return instrumento;
}

Segmentos* Voz::getSegmentos()
{
	return segmentos;
}

Tonalidad Voz::getTonalidad()
{
	return tonalidad;
}

//-----Setters-----//
void Voz::setInstrumento(int i)
{
	instrumento = i;
}

void Voz::setSegmentos(Segmentos* s)
{
	segmentos = s;
}

void Voz::setTonalidad(Tonalidad k)
{
	tonalidad = k;
}