#pragma once

#ifndef SIMBOLOS_H
#define SIMBOLOS_H

#include "Music/Simbolo.h"

#include <list>

using namespace std;

class Simbolos
{
    public:
        Simbolos();
        virtual ~Simbolos();

        /* envoltorio de la lista stl */

		void pushBack(Simbolo* s);
		bool insert(int n, Simbolo* s);		//Añade un elemento en la pos n empujando el que ya estaba

		Simbolo* getAt(int n);

		bool empty();
		int size();


    protected:
    private:
		list<Simbolo*> simbolos;
};

#endif // SIMBOLOS_H
