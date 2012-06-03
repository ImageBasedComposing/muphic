#include "Music/Voces.h"

Voces::Voces()
{
	voces.clear();
}

Voces::Voces(Voces* v)
{
	voces.clear();
	
	for(int i = 0; i < v->size(); i++)
		voces.push_back(v->getAt(i));
}

Voces::~Voces()
{
    std::list<Voz*>::iterator it = voces.begin();
    while (it != voces.end())
    {
        delete (*it);
		(*it) = NULL;
        it++;
    }
    voces.clear();
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

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	voces.insert(it,v);
}

Voz* Voces::getAt(int n)
{
	list<Voz*>::iterator it = voces.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}