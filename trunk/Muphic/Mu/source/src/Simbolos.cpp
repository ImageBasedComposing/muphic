#include "Simbolos.h"

Simbolos::Simbolos()
{
    //ctor
}

Simbolos::~Simbolos()
{
    //dtor
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


void Simbolos::insert(Simbolo* s, int n)
{
	list<Simbolo*>::iterator it = simbolos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	simbolos.insert(it,s);
}

Simbolo* Simbolos::getAt(int n)
{
	list<Simbolo*>::iterator it = simbolos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}