#include "Music/Segmento.h"


Segmento::Segmento()
{
	tempo = 120; // Andantino.
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

Simbolo* Segmento::getAt(int i)
{
	return simbolos->getAt(i);
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

void Segmento::addSimbolos(Simbolos* s)
{
	for(int i = 0; i < s->size(); i++)
		simbolos->pushBack(s->getAt(i));

}

void Segmento::setMetrica(Metrica m)
{
	metrica = m;
}

void Segmento::setTempo(Tempo t)
{
	tempo = t;
}
