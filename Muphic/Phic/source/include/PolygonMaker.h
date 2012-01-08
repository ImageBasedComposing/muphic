#pragma once

#ifndef POLYGONMAKER_H
#define POLYGONMAKER_H

#include "aux_elements.h"

using namespace std;

class PolygonMaker
{
	public:
		PolygonMaker();
		virtual ~PolygonMaker();

		std::vector< Polygon >* makePolygons(std::vector< Mask >* masks);
		void makePolygon(Mask m, FigureImg* f);

	protected:
		std::vector< Polygon >* polygon;
	
	private:
		bool isBorder(int i, int j, Mask m);
		std::pair<int,int> checkDirection(int i, int j, Mask m, int* dir);
};

#endif // POLYGONMAKER_H