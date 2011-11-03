#include "Voces.h"

Voces::Voces()
{
	voces.clear();
}

Voces::~Voces()
{
    //dtor
}

bool Voces::empty()
{
	return voces.empty();
}
int Voces::size()
{
	return voces.size();
}

void Voces::pushBack(Voz* v)
{
	voces.push_back(v);
}

//Añade el elemento empujando el que estaba en n
void Voces::insert(Voz* v, int n)
{
	list<Voz*>::iterator it = voces.begin();

	for(int i = 0; i = n; i++)
	{
		it++;
	}

	voces.insert(it,v);
}

Voz* Voces::getAt(int n)
{
	list<Voz*>::iterator it = voces.begin();

	for(int i = 0; i = n; i++)
	{
		it++;
	}

	return *it;
}