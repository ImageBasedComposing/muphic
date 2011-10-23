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

        /* Por ahora definimos los tipos como enteros */

        typedef int Clave;
        typedef int Ritmo;
        typedef int Tempo;

        Music();
        virtual ~Music();

        string toMidi();

/*------Getters------*/
        string getName();
        string getcomposer();
        Voces* getVoces();
        int getMidizator();
        int getTempo();
        int getRitmo();
        int getClave();

/*------Setters------*/
        void setName(string n);
        void setComposer(string c);
        void setVoces(Voces* voces);
        void setMidizator(int m);
        void setTempo(Tempo t);
        void setRitmo(Ritmo r);
        void setClave(Clave c);

    protected:

    private:
        string name;
        string composer;

        Voces* voces;
        Midizator* midizator;

        Tempo tempo;
        Ritmo ritmo;
        Clave clave;
};

#endif // MUSIC_H
