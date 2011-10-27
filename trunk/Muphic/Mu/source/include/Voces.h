#ifndef VOCES_H
#define VOCES_H

#include <list>
#include "Voz.h"

using namespace std;

class Voces
{
    public:
        Voces();
        virtual ~Voces();

        /* envoltorio del vector stl */
		void addElem(Voz* v);
		void addInPos(Voz* v, int n);		//Añade un elemento en la pos n empujando el que ya estbaa
		Voz* getInPos(int n);
		bool empty();
		int size();

    protected:
    private:
		list<Voz*> voces;
};

#endif // VOCES_H
