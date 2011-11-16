#pragma once

#ifndef PATTERNS_H
#define PATTERNS_H

#include <list>

using namespace std;

class Pattern
{
    public:
		Pattern() {};
		virtual ~Pattern() {};

		virtual list< pair<int, float> > createPattern(list< pair<int, float> > partes) { return partes; }

    protected:
    private:
};


class SimplePattern : public Pattern
{
	private:
		static bool compare (pair<int, float> a, pair<int, float> b)
		{
			return a.second > b.second;
		};


    public:
		SimplePattern() {};
		virtual ~SimplePattern() {};

		list< pair<int, float> > createPattern(list< pair<int, float> > partes)
		{
			partes.sort(&SimplePattern::compare);

			pair<int, float> tmp;
			list< pair<int, float> >::iterator it = partes.end();
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
