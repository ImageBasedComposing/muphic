#include "Segmento.h"


Segmento::Segmento()
{
	simbolos = new Simbolos();
}

Segmento::~Segmento()
{
	delete simbolos;
}

//-----Getters-----//

Simbolos* Segmento::getSimbolos()
{
	return simbolos;
}

Metrica Segmento::getMetrica()
{
	return metrica;
}

Tempo Segmento::getTempo()
{
	return tempo;
}

//-----Setters-----//

void Segmento::setSimbolos(Simbolos* s)
{
	simbolos = s;
}

void Segmento::setMetrica(Metrica m)
{
	metrica = m;
}

void Segmento::setTempo(Tempo t)
{
	tempo = t;
}
