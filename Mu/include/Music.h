#ifndef MUSIC_H
#define MUSIC_H

#include <string>

#include "Midizator.h"
#include "Voz.h"

using namespace std;

class Midizator;

class Music
{
    public:
        Music();
        virtual ~Music();

        string toMidi();

/*------Getters------*/
        string getName();
        string getcomposer();
        Voz* getVoz();
        int getMidizator(); //presupongoq ue lo manejaremos con algun tipo de clave
        int getTempo();
        int getRitmo();
        int getClave();

/*------Setters------*/
        void setName(string n);
        void setComposer(string c);
        void setVoz(); //todavia no sabemos parametros de entrada
        void setMidizator(int m);
        void setTempo(int t);
        void setRitmo(int r);
        void setClave(int c);

    protected:

    private:
        string name;
        string composer;
        Voz* voz;
        Midizator* midizator;
        int tempo;
        int ritmo;
        int clave;
};

#endif // MUSIC_H
