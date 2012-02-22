#pragma once

#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "Music/Simbolos.h"
#include "Music/music_elements.h"

using namespace std;

class Segmento
{
	public:
		Segmento();
		~Segmento();

/*------Getters------*/
        Simbolos* getSimbolos();
		Simbolo* getAt(int i);

        Metrica getMetrica();
		Tempo getTempo();

/*------Setters------*/
        void setSimbolos(Simbolos* s);
		void addSimbolos(Simbolos* s);

		void setTempo(Tempo t);
		void setMetrica(Metrica m);

    private:
        Simbolos* simbolos;

		Metrica metrica;
		Tempo tempo;		
};

#endif // SEGMENTO_H