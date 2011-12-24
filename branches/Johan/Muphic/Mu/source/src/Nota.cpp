#include "Nota.h"


Nota::Nota() : Simbolo()
{	
	//por defecto
	tono = DO_C; // do en la tercera escala, DO central
}

Nota::Nota(int tono) : Simbolo()
{	
	this->tono = tono;
}

Nota::Nota(int duracion, int tono) : Simbolo(duracion)
{
	this->tono = tono;
}

Nota::~Nota()
{
}

//------Getters------//

int Nota::getTono()
{
	return tono;
}

//------Setters------//

void Nota::setTono(int t)
{
	tono = t;
}
