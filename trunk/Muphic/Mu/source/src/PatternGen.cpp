#include "PatternGen.h"


PatternGen::PatternGen()
{
}


PatternGen::~PatternGen()
{
}


list< pair<int, float> > PatternGen::getPattern(list< pair<int, float> > partes)
{

	// tratar la lista

	// seleccionar patron (o algoritmo-que-hace-patrón) en función de la lista
	Pattern* p = new SimplePattern();

	//devolverlo
	return p->createPattern(partes);
}