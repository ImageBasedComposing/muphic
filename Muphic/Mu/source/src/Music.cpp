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