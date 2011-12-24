#pragma once

#ifndef MIDIZATORABC_H
#define MIDIZATORABC_H


#include "Midizator.h"
#include "TableTransform.h"

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
		string toMidi(std::string music);

    protected:

    private:
		TableTransform* tablaTransf;

		string transformNota(Nota* n, pair<int,int> duracionBase);
		string transformAcorde(Acorde* a, pair<int,int> duracionBase);
		string imprimeNota(Simbolo* simbolo, pair<int,int> duracionBase);
		string printInstrumento(Instrumento i);
};

#endif // MIDIZATORABC_H