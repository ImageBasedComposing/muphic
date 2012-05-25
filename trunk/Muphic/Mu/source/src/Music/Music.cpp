#include "Music/Music.h"

Music::Music()
{
    name = "Untitled";
	composer = "";

	midizator = new Midizator();
	voces = new Voces();
	//Por defecto L=1/8, es decir, duración base corchea
	bl = make_pair(1,8);
}

Music::Music(Midizator * mdztor)
{
	name = "Untitled";
	composer = "";

	midizator = mdztor;
	voces = new Voces();
	//Por defecto L=1/8, es decir, duración base corchea
	bl = make_pair(1,8);
}

Music::~Music()
{
	delete voces;
}

string Music::toMidi()
{
	return midizator->toMidi(this);
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

pair<int,int> Music::getBaseLenght()
{
	return bl;
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

void Music::setBaseLenght(pair<int,int> baseLenght)
{
	bl = baseLenght;
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

void Music::changeTempo(int t)
{

}
