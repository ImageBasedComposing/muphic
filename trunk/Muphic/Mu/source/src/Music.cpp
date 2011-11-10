#include "Music.h"

Music::Music()
{
    name = "";
	composer = "";

	midizator = new Midizator();
	voces = new Voces();
}

Music::~Music()
{
	delete voces;
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
	delete voces;
	voces = v;
}

void Music::setMidizator(Midizator* m)
{
	delete midizator;
	midizator = m;
}