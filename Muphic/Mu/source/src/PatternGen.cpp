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

		
list< pair<Segmento*, int> > PatternGen::getPattern(list< pair<Segmento*, int> > partes)
{
	list< pair<int, float> > tmpin, tmpout;
	list< pair<Segmento*, int> > out;

	int nsegmentos = 0;

	for (list< pair<Segmento*, int> >::iterator it = partes.begin(); it != partes.end(); it++)
	{
		tmpin.push_back(make_pair((int) (*it).first,(*it).second));
		nsegmentos += (*it).second;
	}

	tmpout = getPattern(tmpin);
	
	int tmpSum = 0;
	int i = 0;
	int tmpSeg;
	for (list< pair<int, float> >::iterator it = tmpout.begin(); it != tmpout.end(); it++)
	{
		tmpSum += (*it).second;
		if (i == tmpout.size() - 1)
			// el último siempre es lo que queda (o quitar lo que sobra)
			tmpSeg = nsegmentos - tmpSum + (*it).second;
		else
			tmpSeg = (*it).second;

		out.push_back(make_pair((Segmento*) (*it).first,tmpSeg));
		i++;
	}

	return out;
}