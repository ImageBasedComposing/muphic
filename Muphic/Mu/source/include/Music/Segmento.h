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
		bool insert(int pos, Simbolo* s);
		void pushBack(Simbolo *s);
		int size() { return simbolos->size(); };

        Metrica getMetrica();
		Tempo getTempo();
		int getDuration();

/*------Setters------*/
        void setSimbolos(Simbolos* s);
		void addSimbolos(Simbolos* s);

		void setTempo(Tempo t);
		void setMetrica(Metrica m);
		void setDuration(int dur);

    private:
        Simbolos* simbolos;
		int duration;

		Metrica metrica;
		Tempo tempo;		
};

#endif // SEGMENTO_H