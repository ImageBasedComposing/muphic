#include "Voz.h"

Voz::Voz()
{
	simbolos = new Simbolos();
}

Voz::~Voz()
{
    //dtor
}

//-----Getters-----//
int Voz::getInstrumento()
{
	return instrumento;
}

Simbolos* Voz::getSimbolos()
{
	return simbolos;
}

//-----Setters-----//
void Voz::setInstrumento(int i)
{
	instrumento = i;
}

void Voz::setSimbolos(Simbolos* s)
{
	simbolos = s;
}