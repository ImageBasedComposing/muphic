#include "Voces.h"

Voces::Voces()
{
    //ctor	
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

void Voces::addElem(Voz* v)
{
	voces.push_back(v);
}

//Añade el elemento empujando el que estaba en n
void Voces::addInPos(Voz* v, int n)
{
	list<Voz*>::iterator it = voces.begin();

	for(int i = 0; i = n; i++)
	{
		it++;
	}

	voces.insert(it,v);
}

Voz* Voces::getInPos(int n)
{
	list<Voz*>::iterator it = voces.begin();

	for(int i = 0; i = n; i++)
	{
		it++;
	}

	return *it;
}