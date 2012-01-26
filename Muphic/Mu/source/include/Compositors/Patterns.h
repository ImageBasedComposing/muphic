#pragma once

#ifndef PATTERNS_H
#define PATTERNS_H

#include <list>
#include "Music/FigureMusic.h"

class FigureMusic;

using namespace std;

template <class T>
class Pattern
{
    public:
		Pattern() {};
		virtual ~Pattern() {};

		virtual list< pair<T, float> > createPattern(list< pair<T, float> > partes) { return partes; }

    protected:
    private:
};

template <class T>
class SimplePattern : public Pattern<T>
{
	private:
		static bool compare (std::pair<T, float> a, std::pair<T, float> b)
		{
			return a.second > b.second;
		};


    public:
		SimplePattern() {};
		virtual ~SimplePattern() {};

		list< std::pair<T, float> > createPattern(std::list< std::pair<T, float> > partes)
		{
            partes.sort(&SimplePattern::compare);

            std::pair<T, float> tmp;
            typename list< std::pair<T, float> >::iterator it = partes.end();
            it--;
            while (it != partes.begin())
            {
                it--;
                (*it).second /= 2;
                tmp = (*it);
                partes.push_back(tmp);
            }
            return partes;
        };

    protected:
    private:
};

// Pattern that works with figures, it doesnt admit templates due to the recursive nature of Figure
class PriorityPattern : public Pattern<FigureMusic*>
{	public:
		PriorityPattern() {};
		virtual ~PriorityPattern() {};

		list<FigureMusic*> createPatternFig(std::list<FigureMusic*> partes)
		{
			std::list<FigureMusic*>* sol = new list<FigureMusic*> ();

			partes.sort(FigureMusic::compare);

			for(std::list<FigureMusic*>::iterator it = partes.begin(); it != partes.end(); it++)
			{
				sol->push_back((*it));
				createPatternRec((*it), sol);
			}

			return (*sol);

		}
	
	private:
		void createPatternRec(FigureMusic* f, std::list<FigureMusic*>* sol)
		{
			f->sortHijo();
			for(int i = 0; i < f->sizeHijos(); i++)
			{
				sol->push_back((FigureMusic*) f->getHijoAt(i));
				createPatternRec((FigureMusic*) f->getHijoAt(i),sol);
			}
		}
};

#endif // PATTERNS_H
