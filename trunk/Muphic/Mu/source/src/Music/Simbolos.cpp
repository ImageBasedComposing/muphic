#include "Music/Simbolos.h"

Simbolos::Simbolos()
{
    simbolos.clear();
}

Simbolos::~Simbolos()
{
    simbolos.clear();
	list<Simbolo*>::iterator it;
	for (it = simbolos.begin(); it != simbolos.end(); it++)
		delete (*it);
}

bool Simbolos::empty()
{
	return simbolos.empty();
}

int Simbolos::size()
{
	return simbolos.size();
}

void Simbolos::pushBack(Simbolo* s)
{
	simbolos.push_back(s);
}

bool Simbolos::insert(int n, Simbolo* s)
{
	if(simbolos.size() < n)
		return false;

	list<Simbolo*>::iterator it = simbolos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	simbolos.insert(it, s);
}

Simbolo* Simbolos::getAt(int n)
{
	if(simbolos.size() < n)
		return NULL;

	list<Simbolo*>::iterator it = simbolos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}