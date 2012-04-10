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


inline double vectorModule(int x1, int x2, int y1, int y2)
{
	// module = ((x2 - x1)^2 + (y2 - y1)^2)^0.5
	return sqrt(pow((double)x2 - x1, 2) + pow((double)y2 - y1, 2));
}

// Distancia entre dos puntos en el mismo plano (2D)
inline double dist2DPoints(std::pair<int, int> p1, std::pair<int, int> p2)
{
	double dist = sqrt(pow((double)p2.first - p1.first, (int)2) + pow((double)p2.second - p1.second, (int)2));
	return dist;
}

inline double dist3DPoints(int x1, int y1, int z1, int x2, int y2, int z2)
{
	double dist = sqrt(pow(double(x2-y2), int(2)) + pow(double(y2-y1), int(2)) + pow(double(z2-z1), int(2)));
	return dist;
}

// Devuelve la pendiente de una recta dados dos puntos de ella.
inline double slopeOfLine(std::pair<int, int> p1, std::pair<int, int> p2)
{
	double upper = double(p2.second - p1.second);
	double down = double(p2.first - p1.first);
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
inline double angleOf2Lines(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3)
{
	//Hallamos las pendientes
	double m1 = slopeOfLine(p1,p2);
	double m2 = slopeOfLine(p2,p3);

	//			|m2 - m1|	|m2 - m1|				    (No estoy muy seguro)    (|m2 - m1|)
	// tan a =  |_______| =  _______ ;  => a = atan(...)       ~~           atan2( _______ )
	//			|1+m2*m1|	|1+m2*m1|											 (|1+m2*m1|)

	double alpha = atan2((m2 - m1) , abs(1+(m2*m1)));

	return alpha;
}

// returns the angle a vector (x2-x1,y2-y1) with the x axis
inline double vectorAngle(int x1, int x2, int y1, int y2, double module)
{
	// angle = acos((x2 - x1) / module)
	// it's important to check sin's behaviour as well
	double angle;
	double cos = (x2 - x1) / module;
	double sin = (y2 - y1) / module;
	if (sin >= 0)
	{
		angle = acos(cos); // sin 0 gives angle 0, not 360
	}
	else
	{
		angle = 2*PI - acos(cos);
	}
	// cast to decimal angles
	angle *= (180/PI);

	return angle;
}

// returns the angle a vector (x2-x1,y2-y1) with the x axis
inline double vectorAngle(int x1, int x2, int y1, int y2)
{
	return vectorAngle(x1, x2, y1, y2, vectorModule(x1, x2, y1, y2));
}

// given an angle alpha1, and a new angle alpha2, returns if the second one means a right turn (-180,0) or a left turn (0,180)
// works with decimal angles
inline double turnAngle(double alpha1, double alpha2)
{
	double angleIncr;
	// increment
	angleIncr = alpha2 - alpha1;
	// increments are limited to (-180, 180)
	// case 1: 0 < increment < 180: left turn, stays as it is
	// case 2: 180 <= increment: right turn
	if (angleIncr >= 180)
		angleIncr = -(360 - angleIncr); // right turns are negative increments
	// case 3: increment <= -180: left turn
	else if (angleIncr <= -180) 
		angleIncr = 360 + angleIncr; // left turns are positive increments
	// case 4: -180 < increment < 0: right turn, stays as it is

	return angleIncr;
}

//Dados dos rectas de p1 a p2 y de p2 a p3, calcula su ángulo
inline double angleOf2Lines2(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3, std::pair<int, int> p4)
{
	double alpha1 = vectorAngle(p1.first, p2.first, p1.second, p2.second);
	double alpha2 = vectorAngle(p3.first, p4.first, p3.second, p4.second);

	return turnAngle(alpha1, alpha2);
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


// Dado un punto (x,y), y una división en ndiv sectores con centro (centerX, centerY), y comienzo initAlpha,
// calcula en qué sector cae el punto
// input is in radians
inline int locateLocalSector(int x, int y, int centerX, int centerY, int ndiv, double initAlpha)
{
	double module = vectorModule(x, centerX, y, centerY);
	double originY = centerY + (sin(initAlpha) * module);
	double originX = centerX + (cos(initAlpha) * module);

	double alpha = angleOf2Lines2(make_pair(centerX,centerY), make_pair(x,y), make_pair(centerX,centerY), make_pair(originX, originY));

	if (alpha < 0)
		alpha = 360 + alpha; // positive angle

	float sectordiv = 360.0 / ndiv;
	return (int) (alpha / sectordiv);
}

inline int mod(int num, int div)
{
	if(num < 0)
	{
		num = abs(num);
		num = num%div;
		num = -num;
		num = num+div;
	}
	return num%div;
}

inline double radiusOfArea(double area)
{
	// area = PI * r2 -> area / PI = r2 -> sqrt(area/PI) = r
	double out;
	out = sqrt(area / PI);
	return out;
}


#endif // MATH_FUNCTIONS__H
