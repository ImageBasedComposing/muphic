#pragma once

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include "music_elements.h"

class Simbolo
{
    public:
		Simbolo(float duracion = QUARTERNOTE);
        virtual ~Simbolo();

		/*------Getters------*/
        virtual float getDuracion();

		/*------Setters------*/
        virtual void setDuracion(float d);

    protected:

		float duracion;
    private:

};

#endif // SIMBOLO_H
