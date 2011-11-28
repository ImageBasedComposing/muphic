#pragma once

#ifndef PATTERNS_H
#define PATTERNS_H

#include <list>

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
		static bool compare (pair<T, float> a, pair<T, float> b)
		{
			return a.second > b.second;
		};


    public:
		SimplePattern() {};
		virtual ~SimplePattern() {};

		list< pair<T, float> > createPattern(list< pair<T, float> > partes)
		{
            partes.sort(&SimplePattern::compare);

            pair<T, float> tmp;
            typename list< pair<T, float> >::iterator it = partes.end();
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





#endif // PATTERNS_H
