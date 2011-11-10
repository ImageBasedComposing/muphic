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

Clave Voz::getClave()
{
	return clave;
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

void Voz::setClave(Clave c)
{
	clave = c;
}