#pragma once

#ifndef MUSIC_ELEMS_H
#define MUSIC_ELEMS_H

using namespace std;

typedef int Clave;
struct Metrica {
	int upper;
	int lower;
	Metrica(int a = 4, int b = 4)
	{
		upper = a;
		lower = b;
	}
};

typedef int Tempo;

typedef int Instrumento;

#endif // MUSIC_ELEMS
