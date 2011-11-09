#pragma once

#ifndef VOZ_H
#define VOZ_H

#include "Segmentos.h"
#include "music_elements.h"

using namespace std;

class Voz
{
    public:

        /* Por ahora definimos los tipos como enteros */


        Voz();
        virtual ~Voz();

/*------Getters------*/
        int getInstrumento();
        Segmentos* getSegmentos();

/*------Setters------*/
        void setInstrumento(int i);
        void setSegmentos(Segmentos* s);

    protected:

    private:
        Instrumento instrumento;
		Segmentos* segmentos;
};

#endif // VOZ_H