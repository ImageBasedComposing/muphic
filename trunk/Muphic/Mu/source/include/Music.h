#ifndef MUSIC_H
#define MUSIC_H

#include <string>

#include "Midizator.h"
#include "Voces.h"

using namespace std;

class Midizator;

class Music
{
    public:

        /* TYPE DECLARATION */

			typedef int Clave;
			struct Tempo {
				int upper;
				int lower;
				Tempo(int a = 4, int b = 4)
				{
					upper = a;
					lower = b;
				}
			};
			typedef int Ritmo;

		/* TYPE DECLARATION */

        Music();
        virtual ~Music();

        string toMidi();

/*------Getters------*/
        string getName();
        string getComposer();
        Tempo getTempo();
        Ritmo getRitmo();
        Clave getClave();

		Voces* getVoces();
        Midizator* getMidizator();

/*------Setters------*/
        void setName(string n);
        void setComposer(string c);
        void setTempo(Tempo t);
        void setRitmo(Ritmo r);
        void setClave(Clave c);

		void setVoces(Voces* v);
        void setMidizator(Midizator* m);

    protected:

    private:
        string name;
        string composer;
		Tempo tempo;
        Ritmo ritmo;
        Clave clave;

        Voces* voces;
        Midizator* midizator;        
};

#endif // MUSIC_H
