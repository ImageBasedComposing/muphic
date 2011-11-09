#pragma once

#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "Simbolos.h"
#include "music_elements.h"

using namespace std;

class Segmento
{
	public:
		Segmento();
		~Segmento();

/*------Getters------*/
        Simbolos* getSimbolos();

        Metrica getMetrica();
		Tempo getTempo();

/*------Setters------*/
        void setSimbolos(Simbolos* s);

		void setTempo(Tempo t);
		void setMetrica(Metrica m);

    private:
        Simbolos* simbolos;

		Metrica metrica;
		Tempo tempo;		
};

#endif // SEGMENTO_H