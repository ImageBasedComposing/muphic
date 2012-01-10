#include "Acorde.h"
#include "Nota.h"

Acorde::Acorde() : Simbolo()
{
	notas = new Nota[3];
}

Acorde::Acorde(int d) : Simbolo(d)
{
	notas = new Nota[3];
}

Acorde::Acorde(int d, int n1, int n2) : Simbolo(d)
{
	notas = new Nota[2];
	notas[0].setTono(n1);
	notas[1].setTono(n2);
}

Acorde::Acorde(int d, int n1, int n2, int n3) : Simbolo(d)
{
	notas = new Nota[3];
	notas[0].setTono(n1);
	notas[1].setTono(n2);
	notas[2].setTono(n3);
}


Acorde::Acorde(int d, int n1, int n2, int n3, int n4) : Simbolo(d)
{
	notas = new Nota[4];
	notas[0].setTono(n1);
	notas[1].setTono(n2);
	notas[2].setTono(n3);
	notas[3].setTono(n4);
}

Acorde::Acorde(Nota* notas) : Simbolo()
{
	this->notas = notas;
}

////////////////////////////////////////////////////////// WTF! lenght? //////////////////////////////////////////
Acorde::Acorde(Nota notas[], int length) : Simbolo()
{
	this->notas = notas;
}

Acorde::Acorde(int d, Nota* notas) : Simbolo(d)
{
	this->notas = notas;
}

Acorde::Acorde(int d, Nota notas[], int length) : Simbolo(d)
{
	this->notas = notas;
}

Acorde::~Acorde()
{
	delete notas;
}

Nota* Acorde::getNotas()
{
	return notas;
}