#include "Nota.h"


Nota::Nota() : Simbolo()
{	
	//por defecto
	tono = 25; // do en la segunda escala
}

Nota::Nota(int tono) : Simbolo()
{	
	this->tono = tono;
}

Nota::Nota(float duracion, int tono) : Simbolo(duracion)
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
