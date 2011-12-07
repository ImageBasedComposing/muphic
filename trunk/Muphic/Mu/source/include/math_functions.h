#pragma once

#ifndef MATH_FUNCTIONS__H
#define MATH_FUNCTIONS__H

#include <math.h>

// Distancia entre dos puntos en el mismo plano (2D)
float dist2DPoints(pair<int, int> p1, pair<int, int> p2)
{
	float dist = sqrt(pow((double)p2.first - p1.first, (int)2) + pow((double)p2.second - p1.second, (int)2));
	return dist;
}

// Devuelve la pendiente de una recta dados dos puntos de ella.
float slopeOfLine(pair<int, int> p1, pair<int, int> p2)
{
	return float((p2.second - p1.second)) / float((p2.first - p1.first));
}

//Dados dos rectas definidas por 3 vertices (el 2º es el punto de corte) devuelve el ángulo que forman.
float angleOf2Lines(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
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

#endif // MATH_FUNCTIONS__H