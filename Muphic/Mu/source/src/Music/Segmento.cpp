#include "Music/Segmento.h"


Segmento::Segmento()
{
	tempo = 120; // Andantino.
	simbolos = new Simbolos();
	duration = 0;
}

Segmento::~Segmento()
{
	delete simbolos;
	simbolos = NULL;
}

Segmento* Segmento::clone()
{
	Segmento* out = new Segmento();
	out->setTempo(tempo);
	out->setMetrica(metrica);
	out->setSimbolos(simbolos->clone());
	out->setDuration(duration);

	return out;
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

bool Segmento::insert(int pos, Simbolo* s)
{
	if(simbolos->insert(pos, s))
		duration += s->getDuracion();
	else
		return false;
	return true;
}

void Segmento::pushBack(Simbolo* s)
{
	simbolos->pushBack(s);
	duration += s->getDuracion();
}

Metrica Segmento::getMetrica()
{
	return metrica;
}

Tempo Segmento::getTempo()
{
	return tempo;
}

int Segmento::getDuration()
{
	return duration;
}

//-----Setters-----//

void Segmento::setSimbolos(Simbolos* s)
{
	simbolos = s;
	duration = 0;
	for(int i = 0; i < s->size(); i++)
		duration += simbolos->getAt(i)->getDuracion();
}

void Segmento::addSimbolos(Simbolos* s)
{
	for(int i = 0; i < s->size(); i++)
	{
		simbolos->pushBack(s->getAt(i));
		duration += s->getAt(i)->getDuracion();
	}

}

void Segmento::setMetrica(Metrica m)
{
	metrica = m;
}

void Segmento::setTempo(Tempo t)
{
	tempo = t;
}

void Segmento::setDuration(int dur)
{
	duration = dur;
}
