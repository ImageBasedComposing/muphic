#pragma once

#ifndef PATTERNGEN_H
#define PATTERNGEN_H

#include <list>

#include "Patterns.h"
#include "Segmento.h"

using namespace std;

template <class T>
class PatternGen
{
    public:
        PatternGen();
        virtual ~PatternGen();

		list< pair< T, int> >* getPattern(list< pair<T, int> >* partes);

    protected:

		list< pair<T, float> > getPattern(list< pair<T, float> > partes);
    private:
};

template <class T>
PatternGen<T>::PatternGen()
{
}

template <class T>
PatternGen<T>::~PatternGen()
{
}

template <class T>
list< pair<T, float> > PatternGen<T>::getPattern(list< pair<T, float> > partes)
{
	// tratar la lista

	// seleccionar patron (o algoritmo-que-hace-patrón) en función de la lista
	Pattern<T>* p = new SimplePattern<T>();

	//devolverlo
	return p->createPattern(partes);
}

template <class T>
list< pair< T, int> >* PatternGen<T>::getPattern(list< pair<T, int> >* partes)
{
	list< pair<T, float> > tmpin, tmpout;
	list< pair<T, int> >* out = new list< pair<T, int> >();

	int nsegmentos = 0;

	for (typename list< pair<T, int> >::iterator it = partes->begin(); it != partes->end(); it++)
	{
		tmpin.push_back(make_pair((*it).first,(*it).second));
		nsegmentos += (*it).second;
	}

	tmpout = getPattern(tmpin);

	int tmpSum = 0;
	int i = 0;
	int tmpSeg;
	for (typename list< pair<T, float> >::iterator it = tmpout.begin(); it != tmpout.end(); it++)
	{
		tmpSum += (*it).second;
		if (i == tmpout.size() - 1)
			tmpSeg = nsegmentos - tmpSum + (*it).second;
		else
			tmpSeg = (*it).second;

		out->push_back(make_pair((*it).first,tmpSeg));
		i++;
	}

	return out;
}

#endif // PATTERNGEN_H
