#pragma once

#ifndef MIDIZATORWAV_H
#define MIDIZATORWAV_H


#include "Midizator.h"
#include "TableTransform.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Midizator;

class MidizatorWAV : public Midizator
{
    public:
        MidizatorWAV();
        virtual ~MidizatorWAV();

        string toMidi(Music* music);

		//Recibe la path del fichero a convertir y la path del programa que se usara para ello
		string toMidi(std::string music);

    protected:

    private:
		TableTransform* tablaTransf;

		double transfNote2Hz(int Note);
		string transformNota(Nota* n, pair<int,int> duracionBase);
		string transformAcorde(Acorde* a, pair<int,int> duracionBase);
		string imprimeNota(Simbolo* simbolo, pair<int,int> duracionBase);
		string printInstrumento(Instrumento i);
};

#endif // MIDIZATORWAV_H