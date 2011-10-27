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

Tempo* Music::getTempo()
{
	return tempo;
}