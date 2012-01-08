#include "PolygonMaker.h"

/*--- Builders & Destroyers ---*/
PolygonMaker::PolygonMaker()
{
}

PolygonMaker::~PolygonMaker()
{
	polygon->clear();
	delete polygon;
}

/*--- Main Functions ---*/
std::vector< Polygon >* PolygonMaker::makePolygons(std::vector< Mask >* masks)
{
	Mask mask;
	FigureImg* f;
	Polygon p;

	// We take each element from the mask array and make its adequate Polygon
	for(std::vector<Mask>::iterator it = masks->begin(); it != masks->end(); it++)
	{
		// We adquire the next mask
		mask = *it;

		// We create a new figure where to add the colected data
		f = new FigureImg();

		// We make the polygon asociated to that mask
		makePolygon(*it,f);

		// We add the collected data to a Polygon type
		p->first = *it;
		p->second = f;

		// We add the data to the solution we will be returning
		polygon->push_back(p);
	}

	return polygon;
}

void PolygonMaker::makePolygon(Mask m, FigureImg* f)
{
	bool found = false;
	vector<bool>* aux;
	std::pair<int,int> newVertex;
	std::pair<int,int> startingPos;
	int* dir;
	*dir = -361;

	// Mirar si es 1, si es 1 mirar si esta rodeado de algun 0 para saber si es borde
	// Si tiene borde comprobar con los 8 siguientes su direccion
	// Si tiene 1 sola dir actualizar i y j, sino ir hasta el punto donde cambia la dir y actualizar i j

	// We search for initial position of the polygon
	for(int i = 0; !found && i < m->size(); i++)
	{
		aux = m->at(i);

		for(int j = 0; !found && j < aux->size(); j++)
		{
			if(isBorder(i,j,m))
			{
				startingPos.first = i;
				startingPos.second = j;
				newVertex = checkDirection(i,j, m, dir);
				found = true;
			}
		}
	}

	// We go through the contour of the polygon looking for its vertexes
	while(newVertex != startingPos)
	{
	}
}

/*--- Private Functions ---*/
bool PolygonMaker::isBorder(int i, int j, Mask m)
{
	return (i == 0 || j == 0 || i == m->size() || j == m->at(i)->size() ); //falta si esta rodeado de algun 0
}

std::pair<int,int> PolygonMaker::checkDirection(int i, int j, Mask m, int* dir)
{
	return std::make_pair(0,0);
}

/*--- Getters & Setters ---*/