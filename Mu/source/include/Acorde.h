#pragma once

#ifndef ACORDE_H
#define ACORDE_H

#include "Nota.h"

class Acorde : public Simbolo
{
	public:
		Acorde();
		Acorde(int d);
		Acorde(int d, int n1, int n2);
		Acorde(int d, int n1, int n2, int n3);
		Acorde(int d, int n1, int n2, int n3, int n4);


		Acorde(Nota* notas);
		Acorde(Nota notas[], int length);
		Acorde(int d, Nota* notas);
		Acorde(int d, Nota notas[], int length);

		~Acorde();

		Nota* getNotas();

	private:

		Nota* notas;
};

#endif // ACORDE_H
