#pragma once

#ifndef VOCES_H
#define VOCES_H

#include "Voz.h"

#include <list>

using namespace std;

class Voces
{
    public:
        Voces();
		Voces(Voces* v);
        virtual ~Voces();

        /* envoltorio del vector stl */

		void pushBack(Voz* v);
		void insert(Voz* v, int n);		//Añade un elemento en la pos n empujando el que ya estaba

		Voz* getAt(int n);

		bool empty();
		int size();

    protected:
    private:
		list<Voz*> voces;
};

#endif // VOCES_H
