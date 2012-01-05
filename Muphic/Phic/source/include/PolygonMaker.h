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

		std::vector< Polygon > makePolygons(std::vector< Mask > masks);

	protected:
	
	private:
};

#endif // POLYGONMAKER_H