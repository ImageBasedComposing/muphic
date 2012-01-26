#pragma once

#ifndef NOTA_H
#define NOTA_H

#include "Music/Simbolo.h"

class Nota : public Simbolo
{
	public:
		Nota();
		Nota(int tono);
		Nota(int duracion, int tono);

		~Nota();

		/*------Getters------*/
        int getTono();

		/*------Setters------*/
        void setTono(int t);

    private:
		int tono;
};

#endif // NOTA_H
