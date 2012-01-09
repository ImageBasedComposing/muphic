#include "PolygonMaker.h"

/*--- Builders & Destroyers ---*/
PolygonMaker::PolygonMaker()
{
}

PolygonMaker::~PolygonMaker()
{
	polygon.clear();
}

/*--- Main Functions ---*/
std::vector< Polygon > PolygonMaker::makePolygons(std::vector< Mask* > masks)
{
	Mask* mask;
	FigureImg* f;
	Polygon p;

	// We take each element from the mask array and make its adequate Polygon
	for(std::vector<Mask*>::iterator it = masks.begin(); it != masks.end(); it++)
	{
		// We adquire the next mask
		mask = (*it);

		// We create a new figure where to add the colected data
		f = new FigureImg();

		// We make the polygon asociated to that mask
		makePolygon(*it,f);

		// We add the collected data to a Polygon type
		p.first = *it;
		p.second = f;

		// We add the data to the solution we will be returning
		polygon.push_back(p);
	}

	return polygon;
}

void PolygonMaker::makePolygon(Mask* m, FigureImg* f)
{
	bool found = false;
	vector<bool>* aux;
	std::pair<int,int> newVertex;
	std::pair<int,int> startingPos;
	bool* isVertex = new bool();
	*isVertex = false;
	int* dir = new int();
	*dir = -361;
	Vertice* v = new Vertice();

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
				newVertex = checkDirection(i,j, m, startingPos, dir, isVertex);
				found = true;
			}
		}
	}

	// We go through the contour of the polygon looking for its vertexes
//	while(newVertex != startingPos)
	for(int i = 1; i < 6; i++)	//TEMPORAL ESTA MIERDA NO VA
	{
		newVertex = checkDirection(newVertex.first, newVertex.second, m, startingPos, dir, isVertex);
		if(*isVertex)
		{
			v = new Vertice();
			v->x = newVertex.first;
			v->y = newVertex.second;
			f->colocarVertice(v);
		}
	}

	delete dir;
	delete isVertex;
}

/*--- Private Functions ---*/

// This funcion checks if were in the border of the mask or if its the border of the figure
bool PolygonMaker::isBorder(int i, int j, Mask* m)
{
	if (m->at(i)->at(j) == 1)
	{
		if (i == 0 || j == 0 || i == m->size() - 1 || j == m->at(i)->size() - 1)
			return 1;
		else
			return (m->at(i)->at(j - 1) == 0	 || m->at(i)->at(j + 1) == 0	 ||
					m->at(i - 1)->at(j) == 0	 || m->at(i + 1)->at(j) == 0	 ||
					m->at(i - 1)->at(j - 1) == 0 || m->at(i - 1)->at(j + 1) == 0 ||
					m->at(i + 1)->at(j - 1) == 0 || m->at(i + 1)->at(j + 1) == 0);
	}
	return 0;
}

// Polygons will be made 4 by 4 bits, which means that when we find a corner it may
// create a diagonal instead of drawing the corner correctly
std::pair<int,int> PolygonMaker::checkDirection(int i, int j, Mask* m, std::pair<int,int> ip, int* dir, bool* isVertex)
{
	std::pair<int,int> newVertex;
	int *newDir = new int();
	bool end = false;
	*isVertex = false;

	if(*dir != -361)
	{
		//We check the direction per quadrant to choose wich sorrounding pixels we're going to analyze
		if((*dir >= 0 && *dir < 90) || *dir == 360)
		{
			for(int k = i; k >= 0 && k > i - VAR && !end; k--)
			{
				for(int t = j; t < m->at(i)->size() && t < j + VAR && !end; t++)
				{
					if((t == ip.second && k == ip.first))
					{
						newVertex = ip;
						*newDir = 0;
						end = true;
					}
					if(m->at(i)->at(j) == 1 && isBorder(i,j,m))
					{
						newVertex = std::make_pair(k,t);
						*newDir = vectorAngle(i,j,newVertex.first,newVertex.second);
					}
				}
			}
			
		}
		else if(*dir >= 90 && *dir < 180)
		{
			for(int k = i; k >= 0 && k > i - VAR && !end; k--)
			{
				for(int t = j; t >= 0 && t > j - VAR && !end; t--)
				{
					if((t == ip.second && k == ip.first))
					{
						newVertex = ip;
						*newDir = 0;
						end = true;
					}
					if(m->at(i)->at(j) == 1 && isBorder(i,j,m))
					{
						newVertex = std::make_pair(k,t);
						*newDir = vectorAngle(i,j,newVertex.first,newVertex.second);
					}
				}
			}
			
		}
		else if(*dir >= 180 && *dir < 270)
		{
			for(int k = i; k < m->size() && k < i + VAR && !end; k++)
			{
				for(int t = j; t >= 0 && t > j - VAR && !end; t--)
				{
					if((t == ip.second && k == ip.first))
					{
						newVertex = ip;
						*newDir = 0;
						end = true;
					}
					if(m->at(i)->at(j) == 1 && isBorder(i,j,m))
					{
						newVertex = std::make_pair(k,t);
						*newDir = vectorAngle(i,j,newVertex.first,newVertex.second);
					}
				}
			}
			
		}
		else if(*dir >= 270 && *dir < 360)
		{
			for(int k = i; k < m->size() && k < i + VAR && !end; k++)
			{
				for(int t = j; t < m->at(i)->size() && t < j + VAR && !end; t++)
				{
					if((t == ip.second && k == ip.first))
					{
						newVertex = ip;
						*newDir = 0;
						end = true;
					}
					if(m->at(i)->at(j) == 1 && isBorder(i,j,m))
					{
						newVertex = std::make_pair(k,t);
						*newDir = vectorAngle(i,j,newVertex.first,newVertex.second);
					}
				}
			}
			
		}
		if(fabs((float) *dir - *newDir) > ERR)
		{
			*dir = *newDir;
			newVertex = std::make_pair(i,j);
			*isVertex = true;
		}
	}
	else
	{
		bool found = false;
		// We look down from the point and to the right because it's the first point we found
		for(int k = i; k < m->size() && k < i + VAR; k++)
		{
			for(int t = j; j < m->at(i)->size() && t < j + VAR; t++)
				if(m->at(i)->at(j) == 1 && isBorder(i,j,m))
				{
					newVertex = std::make_pair(k,t);
					*dir = vectorAngle(i,j,newVertex.first,newVertex.second);
				}
		}
		
	}

	return newVertex;
}

/*--- Getters & Setters ---*/