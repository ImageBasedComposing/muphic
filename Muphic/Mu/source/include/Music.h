#pragma once

#ifndef MUSIC_H
#define MUSIC_H

#include <string>

#include "Midizator.h"
#include "Voces.h"
#include "music_elements.h"

using namespace std;

class Midizator;

class Music
{
    public:

        /* TYPE DECLARATION */
		/*
			typedef int Clave;
			struct Metrica {
				int upper;
				int lower;
				Metrica(int a = 4, int b = 4)
				{
					upper = a;
					lower = b;
				}
			};
			typedef int Tempo;
			/*
		/* TYPE DECLARATION */

        Music();
        virtual ~Music();

        string toMidi();

/*------Getters------*/
        string getName();
        string getComposer();
        Clave getClave();

		Voces* getVoces();
        Midizator* getMidizator();

/*------Setters------*/
        void setName(string n);
        void setComposer(string c);
		void setClave(Clave c);

		void setVoces(Voces* v);
        void setMidizator(Midizator* m);

    protected:

    private:
        string name;
        string composer;

        Voces* voces;
        Midizator* midizator;        
};

#endif // MUSIC_H
