#include "Music/Segmentos.h"


Segmentos::Segmentos()
{
	segmentos.clear();
}

Segmentos::~Segmentos()
{
	segmentos.clear();
}

bool Segmentos::empty()
{
	return segmentos.empty();
}

int Segmentos::size()
{
	return segmentos.size();
}

void Segmentos::pushBack(Segmento* s)
{
	segmentos.push_back(s);
}

//Añade el elemento empujando el que estaba en n
void Segmentos::insert(Segmento* s, int n)
{
	list<Segmento*>::iterator it = segmentos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	segmentos.insert(it,s);
}

Segmento* Segmentos::getAt(int n)
{
	list<Segmento*>::iterator it = segmentos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}