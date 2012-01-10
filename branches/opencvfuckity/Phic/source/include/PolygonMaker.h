#pragma once

#ifndef POLYGONMAKER_H
#define POLYGONMAKER_H

#include "aux_elements.h"
#include "math_functions.h"

using namespace std;

class PolygonMaker
{
	public:
		PolygonMaker();
		virtual ~PolygonMaker();

		std::vector< Polygon > makePolygons(std::vector< Mask* > masks);
		void makePolygon(Mask* m, FigureImg* f);

	protected:
		std::vector< Polygon > polygon;
	
	private:
		static const int VAR = 3;		//The lower this number the better the polygon aproximation, won't work with 0
		static const int ERR = 5;	//The error margin between the two vectors of a polygon, the lower this number the more exact the polygon will be

		bool isBorder(int i, int j, Mask* m);
		std::pair<int,int> checkDirection(int i, int j, Mask* m, std::pair<int,int> initPos, int* dir, bool* isVertex);
};

#endif // POLYGONMAKER_H