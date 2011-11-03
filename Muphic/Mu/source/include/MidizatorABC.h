#ifndef MIDIZATORABC_H
#define MIDIZATORABC_H


#include "Midizator.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Midizator;

class MidizatorABC : public Midizator
{
    public:
        MidizatorABC();
        virtual ~MidizatorABC();

        string toMidi(Music* music);

		//Recibe la path del fichero a convertir y la path del programa que se usara para ello
		string toMidi(std::string music, std::string converter = "");

    protected:
    private:
};

#endif // MIDIZATORABC_H