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

        virtual string toMidi(Music* music);

    protected:
    private:
};

#endif // MIDIZATOR_H
