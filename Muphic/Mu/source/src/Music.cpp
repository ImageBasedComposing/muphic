#include "Music.h"

Music::Music()
{
    //ctor
}

Music::~Music()
{
    //dtor
}

//-----Getters-----//
string Music::getName()
{
	return name;
}

string Music::getComposer()
{
	return composer;
}

Voces* Music::getVoces()
{
	return voces;
}

Midizator* Music::getMidizator()
{
	return midizator;
}

Music::Tempo Music::getTempo()
{
	return tempo;
}

Music::Ritmo Music::getRitmo()
{
	return ritmo;
}

Music::Clave Music::getClave()
{
	return clave;
}

//-----Setters-----//

void Music::setName(string n)
{
	name = n;
}

void Music::setComposer(string c)
{
	composer = c;
}

void Music::setVoces(Voces* v)
{
	voces = v;
}

void Music::setMidizator(Midizator* m)
{
	midizator = m;
}

void Music::setTempo(Music::Tempo t)
{
	tempo = t;
}

void Music::setRitmo(Music::Ritmo r)
{
	ritmo = r;
}

void Music::setClave(Music::Clave c)
{
	clave = c;
}