#include "Music/Voz.h"

Voz::Voz()
{
	segmentos = new Segmentos();
	this->instrumento = DEFAULT_INSTRUMENT;
}

Voz::~Voz()
{
    delete segmentos;
	segmentos = NULL;
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

void Voz::setTempo(int t)
{
	for(int i = 0; i < segmentos->size(); i++)
		segmentos->getAt(i)->setTempo(t);
}
