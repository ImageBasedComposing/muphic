#pragma once

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include "music_elements.h"

class Simbolo
{
    public:
		Simbolo(int duracion = QUARTERNOTE); //Por defecto una negra.
        virtual ~Simbolo();

		/*------Getters------*/
        virtual int getDuracion();

		/*------Setters------*/
        virtual void setDuracion(int d);

    protected:
		//Representa la duración del simbolo/sonido.
		// 1 = semifusa; 2 = fusa; 4 = semicorchea; 8 = corchea; 16 = negra; 32 = blanca ...
		int duracion;
    private:

};

#endif // SIMBOLO_H
