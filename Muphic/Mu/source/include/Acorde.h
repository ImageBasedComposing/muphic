#pragma once

#ifndef ACORDE_H
#define ACORDE_H

#include "Nota.h"

class Acorde : public Simbolo
{
	public:
		Acorde();
		Acorde(float d);
		Acorde(float d, int n1, int n2);
		Acorde(float d, int n1, int n2, int n3);
		Acorde(float d, int n1, int n2, int n3, int n4);


		Acorde(Nota* notas);
		Acorde(Nota notas[], int length);
		Acorde(float d, Nota* notas);
		Acorde(float d, Nota notas[], int length);

		~Acorde();

		Nota* getNotas();

	private:

		Nota* notas;
};

#endif // ACORDE_H
