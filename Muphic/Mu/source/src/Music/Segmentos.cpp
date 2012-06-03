#include "Music/Segmentos.h"


Segmentos::Segmentos()
{
	segmentos.clear();
}

Segmentos::~Segmentos()
{
    std::list<Segmento*>::iterator it = segmentos.begin();
    while (it != segmentos.end())
    {
        delete (*it);
		(*it) = NULL;
        it++;
    }
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
bool Segmentos::insert(int n, Segmento* s)
{
	if( segmentos.size() < n)
		return false;

	list<Segmento*>::iterator it = segmentos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	segmentos.insert(it, s);

	return true;
}

Segmento* Segmentos::getAt(int n)
{
	if( segmentos.size() < n )
		return NULL;

	list<Segmento*>::iterator it = segmentos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}