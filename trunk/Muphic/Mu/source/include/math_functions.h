#pragma once

#ifndef MATH_FUNCTIONS__H
#define MATH_FUNCTIONS__H

#include <math.h>
#include <stdlib.h>
#include "Vertice.h"

using namespace std;

// Distancia entre dos puntos en el mismo plano (2D)
inline float dist2DPoints(std::pair<int, int> p1, std::pair<int, int> p2)
{
	float dist = sqrt(pow((double)p2.first - p1.first, (int)2) + pow((double)p2.second - p1.second, (int)2));
	return dist;
}

// Devuelve la pendiente de una recta dados dos puntos de ella.
inline float slopeOfLine(std::pair<int, int> p1, std::pair<int, int> p2)
{
	return float((p2.second - p1.second)) / float((p2.first - p1.first));
}

//Dados dos rectas definidas por 3 vertices (el 2º es el punto de corte) devuelve el ángulo que forman.
inline float angleOf2Lines(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3)
{
	//Hallamos las pendientes
	float m1 = slopeOfLine(p1,p2);
	float m2 = slopeOfLine(p2,p3);

	//			|m2 - m1|	|m2 - m1|				    (No estoy muy seguro)    (|m2 - m1|)
	// tan a =  |_______| =  _______ ;  => a = atan(...)       ~~           atan2( _______ )
	//			|1+m2*m1|	|1+m2*m1|											 (|1+m2*m1|)

	float alpha = atan2(abs(m2 - m1) , abs(1+(m2*m1)));

	return alpha;
}

//Dada una lista de vertices devuelve el baricentro de la figura.
inline std::pair<int,int> calculateBarycenter(std::list<Vertice*> listaVertices)
{
	std::list<Vertice*>::iterator it = listaVertices.begin();
	int xcont = 0;
	int ycont = 0;

	while( it != listaVertices.end())
	{
		if ((*it)->centro)
		{
			it++;
			continue;
		}

		xcont += (*it)->x;
		ycont += (*it)->y;

		it++;
	}

	std::pair<int,int> out;

	out.first = xcont / listaVertices.size();
	out.second = ycont / listaVertices.size();

	return out;
}

#endif // MATH_FUNCTIONS__H
