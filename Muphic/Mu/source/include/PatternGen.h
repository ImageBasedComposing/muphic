#pragma once

#ifndef PATTERNGEN_H
#define PATTERNGEN_H

#include <list>

#include "Patterns.h"

using namespace std;


class PatternGen
{
    public:
        PatternGen();
        virtual ~PatternGen();

		list< pair<int, float> > getPattern(list< pair<int, float> > partes);

    protected:
    private:
};

#endif // PATTERNGEN_H
