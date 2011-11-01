#ifndef MIDIZATORABC_H
#define MIDIZATORABC_H

#include <string>
#include "Midizator.h"

using namespace std;

class Midizator;

class MidizatorABC : public Midizator
{
    public:
        MidizatorABC();
        virtual ~MidizatorABC();

        string toMidi(Music* music);

		//Recibe la path del ficheor a convertir y la path del programa que se usara para ello
		string toMidi(std::string music, std::string converter = "");

    protected:
    private:
		std::string changeExtension(std::string picPath, std::string extension);
};

#endif // MIDIZATORABC_H