#pragma once

#ifndef PATTERNGEN_H
#define PATTERNGEN_H

#include <list>

#include "Patterns.h"
#include "Segmento.h"

using namespace std;


class PatternGen
{
    public:
        PatternGen();
        virtual ~PatternGen();

		list< pair<int, float> > getPattern(list< pair<int, float> > partes);


		list< pair<Segmento*, int> > getPattern(list< pair<Segmento*, int> > partes);
		list< pair < list<Segmento*>* , int> > getPattern(list< pair < list<Segmento*>* , int> > partes);

    protected:
		list< pair<void*, int> > getPatternV(list< pair <void* , int> > partes);

    private:
};

#endif // PATTERNGEN_H
