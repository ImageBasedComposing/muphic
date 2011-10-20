#ifndef MIDIZATOR_H
#define MIDIZATOR_H

#include <string>
 
#include "Music.h"

using namespace std;

class Music;

class Midizator
{
    public:
        Midizator();
        virtual ~Midizator();

        string toMidi(Music* music); //no recuerdo como evitar recursividad asiq ue no se como poner el music de aqui

    protected:
    private:
};

#endif // MIDIZATOR_H
