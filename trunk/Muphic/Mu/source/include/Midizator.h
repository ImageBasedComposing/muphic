#pragma once

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
		virtual string toMidi(std::string music, std::string converter = "");

    protected:
    private:
};

#endif // MIDIZATOR_H
