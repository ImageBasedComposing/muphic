#ifndef SIMBOLOS_H
#define SIMBOLOS_H

#include "Simbolo.h"

#include <list>

using namespace std;

class Simbolos
{
    public:
        Simbolos();
        virtual ~Simbolos();

        /* envoltorio de la lista stl */

		void pushBack(Simbolo* s);
		void insert(Simbolo* s, int n);		//Añade un elemento en la pos n empujando el que ya estaba

		Simbolo* getAt(int n);

		bool empty();
		int size();


    protected:
    private:
		list<Simbolo*> simbolos;
};

#endif // SIMBOLOS_H
