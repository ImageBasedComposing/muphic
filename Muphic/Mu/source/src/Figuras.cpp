#include "Figuras.h"

Figuras::Figuras()
{
    figuras.clear();
}

Figuras::~Figuras()
{
    figuras.clear();
}

bool Figuras::emptyFig()
{
	return figuras.empty();
}

bool Figuras::emptyPadre()
{
	return figPadre.empty();
}

int Figuras::sizeFig()
{
	return figuras.size();
}

int Figuras::sizePadre()
{
	return figPadre.size();
}

void Figuras::colocarFig(Figura* s)
{
	figuras.push_back(s);
}

void Figuras::colocarPadre(Figura* s)
{
	figPadre.push_back(s);
}

void Figuras::insertFig(Figura* s, int n)
{
	list<Figura*>::iterator it = figuras.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	figuras.insert(it,s);
}

void Figuras::insertPadre(Figura* s, int n)
{
	list<Figura*>::iterator it = figPadre.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	figPadre.insert(it,s);
}

Figura* Figuras::getFigAt(int n)
{
	list<Figura*>::iterator it = figuras.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}

Figura* Figuras::getPadreAt(int n)
{
	list<Figura*>::iterator it = figPadre.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}