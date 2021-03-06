#pragma once

#ifndef SEGMENTOS_H
#define SEGMENTOS_H

#include "Music/Segmento.h"

#include <list>

using namespace std;

class Segmentos
{
	public:
		Segmentos();
		~Segmentos();

        /* envoltorio del vector stl */

		void pushBack(Segmento* s);
		bool insert(int n, Segmento* s);		//A�ade un elemento en la pos n empujando el que ya estaba

		Segmento* getAt(int n);

		bool empty();
		int size();

    protected:
    private:
		list<Segmento*> segmentos;
};

#endif // SEGMENTOS_H