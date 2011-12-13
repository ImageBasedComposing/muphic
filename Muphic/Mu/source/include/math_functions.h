#pragma once

#ifndef MATH_FUNCTIONS__H
#define MATH_FUNCTIONS__H

#include <math.h>
#include <float.h>
#include <list>
#include <stdlib.h>
#include "Vertice.h"


//using namespace std;


#define PI 3.1415926535897932384626433832795

// Distancia entre dos puntos en el mismo plano (2D)
inline float dist2DPoints(std::pair<int, int> p1, std::pair<int, int> p2)
{
	float dist = sqrt(pow((double)p2.first - p1.first, (int)2) + pow((double)p2.second - p1.second, (int)2));
	return dist;
}

// Devuelve la pendiente de una recta dados dos puntos de ella.
inline float slopeOfLine(std::pair<int, int> p1, std::pair<int, int> p2)
{
	float upper = float(p2.second - p1.second);
	float down = float(p2.first - p1.first);
	if (upper == 0)
		if(down < 0)
			return -0.0;
		else
			return 0.0;
	else
		if(down == 0)
			if(upper < 0)
				return FLT_MAX; //Valor máximo de un float
			else
				return -FLT_MAX;
		else
			return upper/down;
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

	float alpha = atan2((m2 - m1) , abs(1+(m2*m1)));

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

inline float vectorModule(int x1, int x2, int y1, int y2)
{
	// module = ((x2 - x1)^2 + (y2 - y1)^2)^0.5
	return sqrt(pow((float) x2 - x1, 2) + pow((float)y2 - y1, 2));
}

// Dado un punto (x,y), y una división en ndiv sectores con centro (centerX, centerY), y comienzo initAlpha,
// calcula en qué sector cae el punto
// input is in radians
inline int locateLocalSector(int x, int y, int centerX, int centerY, int ndiv, float initAlpha)
{
	float originY = centerY + (sin(initAlpha) * vectorModule(x, y, centerX, centerY));
	float originX = centerX + (cos(initAlpha) * vectorModule(x, y, centerX, centerY));

	float alpha = angleOf2Lines(make_pair(x,y), make_pair(centerX,centerY), make_pair(originX, originY));

	alpha = 180 - (alpha * 180 / PI); // external angle

	if (alpha < 0)
		alpha = 360 + alpha;

	return ((int) alpha) % ndiv;
}


#endif // MATH_FUNCTIONS__H
