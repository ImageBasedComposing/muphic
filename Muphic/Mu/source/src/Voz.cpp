#include "Voz.h"

Voz::Voz()
{
	segmentos = new Segmentos();
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

//-----Setters-----//
void Voz::setInstrumento(int i)
{
	instrumento = i;
}

void Voz::setSegmentos(Segmentos* s)
{
	segmentos = s;
}