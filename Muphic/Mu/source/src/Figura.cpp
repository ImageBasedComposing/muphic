#include "Figura.h"

Figura::Figura()
{
	colorDifference = -1;
	vistosidad = -1;
	rgb.r = -1;
	rgb.b = -1;
	rgb.g = -1;

	// vistosidad priority consts
	A = 0.5;
	B = 0.3;
	C = 0.2;
		
	// Color priority consts
	pR = 0.45;
	pG = 0.35;
	pB = 0.20;
}

Figura::~Figura()
{
	listaVertices.clear();
}

//------Getters------//
string Figura::getColor()
{
	return color;
}

Color Figura::getRGB()
{
	return rgb;
}

int Figura::getNumVertices()
{
	return numVertices;
}

int Figura::getId()
{
	return id;
}

Figura* Figura::getParent()
{
	return padre;
}

int Figura::getArea()
{
	return area;
}

float Figura::getVistosidad()
{
	return vistosidad;
}

float Figura::getColorDifference()
{
	return colorDifference;
}
//------Setters------//
void Figura::setRGB(float r, float g, float b)
{
	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
}

void Figura::setColor(string c)
{
	color = c;
}

void Figura::setNumVertices(int n)
{
	numVertices = n;
}
void Figura::setId(int id)
{
	this->id = id;
}

void Figura::setParent(Figura* p)
{
	padre = p;
}

void Figura::setArea(int a)
{
	area = a;
}

int Figura::calcularVistosidad(int sHeight, int sWidth)
{
	if (rgb.r == -1)
		return -1;
	else if (vistosidad == -1)
	{
		vistosidad = A*getSaturation()*(rgb.r*pR + rgb.g*pG + rgb.b*pB) + B*area + C*distanceCenter(sHeight, sWidth);
	}
	return vistosidad;
}

void Figura::setVistosidad(float v)
{
	vistosidad = v;
}

void Figura::setColorDifference(float c)
{
	colorDifference = c;
}

//------Envoltorio de la lista stl------//
bool Figura::emptyVertices()
{
	return listaVertices.empty();
}

bool Figura::emptyHijos()
{
	return hijos.empty();
}

int Figura::sizeVertices()
{
	return listaVertices.size();
}

int Figura::sizeHijos()
{
	return hijos.size();
}

void Figura::colocarVertice(Vertice* v)
{
	listaVertices.push_back(v);
}

void Figura::colocarHijo(Figura* f)
{
	hijos.push_back(f);
}

void Figura::insertarVertice(Vertice* v, int n)
{
	list<Vertice*>::iterator it = listaVertices.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	listaVertices.insert(it,v);
}

void Figura::insertarHijo(Figura* f, int n)
{
	list<Figura*>::iterator it = hijos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	hijos.insert(it,f);
}

void Figura::sortHijo()
{
	hijos.sort(compare);
}

Vertice* Figura::getVerticeAt(int n)
{
	list<Vertice*>::iterator it = listaVertices.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}

Vertice* Figura::verticeSig(Vertice* v)
{
	list<Vertice*>::iterator it = listaVertices.begin();
	int i = listaVertices.size();

	while(v != *it && i >= 0)
	{
		it++;
		i--;
	}

	if(i == 0)
		return *listaVertices.begin();

	return *(it++);
}

Vertice* Figura::verticeAnt(Vertice* v)
{
	list<Vertice*>::iterator it = listaVertices.begin();
	list<Vertice*>::iterator aux = listaVertices.begin();

	int i = listaVertices.size();

	if(*it == v)
		return *listaVertices.end();

	it++;
	i -= 1;

	while(v != *it && i >= 0)
	{
		it++;
		aux++;
	}

	return *aux;
}

Figura* Figura::getHijoAt(int n)
{
	list<Figura*>::iterator it = hijos.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}

//-----Other funcs-----//


// calcula el centro de una figura con m�s de dos v�rtices
std::pair<int,int> Figura::getSimpleCenter()
{
	list<Vertice*>::iterator it = listaVertices.begin();
	int xmax,ymax,xmin,ymin;

	xmax = (*it)->x;
	ymax = (*it)->y;
	xmin = xmax;
	ymin = ymax;

	it++;

	while( it != listaVertices.end())
	{
		if ((*it)->centro)
		{
			it++;
			continue;
		}

		if ((*it)->x > xmax)
			xmax = (*it)->x;
		else if ((*it)->x < xmin)
			xmin = (*it)->x;

		if ((*it)->y > ymax)
			ymax = (*it)->y;
		else if ((*it)->y < ymin)
			ymin = (*it)->y;
		
		it++;
	}

	std::pair<int,int> out;

	out.first = (xmax + xmin) / 2;
	out.second = (ymax + ymin) / 2;

	return out;
}

// calcula el centro de una figura con m�s de dos v�rtices
std::pair<int,int> Figura::getBarycenter()
{
	return calculateBarycenter(listaVertices);
}

// devuelve la figura como una lista de v�rtices en coordenadas psuedo-polares (�ngulo y longitudes relativas, sin punto de origen)
list< std::pair<float,float> > Figura::polarize()
{
	// set iterator at initial vertex
	list<Vertice*>::iterator it = listaVertices.begin();
	// for now it's the first vertex, but that can change
	Vertice* currentVertex;
	Vertice* nextVertex;
	int n = 0;
	std::pair<float, float> tmpVertex;
	list< pair<float, float> > polarizedFigure;
	float oldalpha = 0, newalpha = 0;
	float length;
	float angleIncr;
	while (n < getNumVertices())
	{
		// get current vertex
		currentVertex = (*it);
		// get next vertex
		it++;
		if (it == listaVertices.end())
			it = listaVertices.begin();
		nextVertex = (*it);

		// module
		length = vectorModule(currentVertex->x, nextVertex->x, currentVertex->y, nextVertex->y);

		// angle = acos((x2 - x1) / module)
		newalpha = vectorAngle(currentVertex->x, nextVertex->x, currentVertex->y, nextVertex->y, length);

		// turn angle
		angleIncr = turnAngle(oldalpha, newalpha);

		// put vertex
		tmpVertex.first = angleIncr;
		tmpVertex.second = length;
		polarizedFigure.push_back(tmpVertex);

		// current values are now old values
		oldalpha = newalpha;

		// advance
		n++;
	}

	// first vertex was fixed at 0� degrees, let's fix that
	currentVertex = (*it); // startpoint vertex
	it++;
	// perhaps we didn't start at the first vertex
	if (it == listaVertices.end())
		it = listaVertices.begin();
	nextVertex = (*it);		// next vertex

	// angle
	newalpha = vectorAngle(currentVertex->x, nextVertex->x, currentVertex->y, nextVertex->y, (*polarizedFigure.begin()).second);
	// increment
	angleIncr = turnAngle(oldalpha, newalpha);

	// put vertex
	(*polarizedFigure.begin()).first = angleIncr;

	return polarizedFigure;
}
/*
float Figura::vectorModule(int x1, int x2, int y1, int y2)
{
	// module = ((x2 - x1)^2 + (y2 - y1)^2)^0.5
	return sqrt(pow((float) x2 - x1, 2) + pow((float)y2 - y1, 2));
}*/


// Calculates the distance from the figure to the center of the drawing Sheet
float Figura::distanceCenter(int sHeight, int sWidth)
{
	// We calculate the center of the drawing sheet
	std::list<Vertice*> sheet;
	sheet.push_back(new Vertice(0,0));
	sheet.push_back(new Vertice(0,sHeight));
	sheet.push_back(new Vertice(sWidth,0));
	sheet.push_back(new Vertice(sWidth,sHeight));

	std::pair<int,int> centro = calculateBarycenter(sheet);

	std::list<Vertice*>::iterator it = listaVertices.begin();
	float minDist = dist2DPoints((*it)->getPair(),centro);
	
	// We calculate the distance of the nearer vertex to the center
	for(it; it != listaVertices.end(); it++)
	{
		if (minDist > dist2DPoints((*it)->getPair(),centro))
			minDist = dist2DPoints((*it)->getPair(),centro);
	}

	// We return that distance
	return minDist;
}

float Figura::getSaturation()
{
	float max = -1;
	float min = 500;

	// We calculate the max and the min from the rgb values
	if(rgb.r >= rgb.b)
	{
		min = rgb.b;
		max = rgb.r;
		if(rgb.r < rgb.g)
			max = rgb.g;
		if(rgb.b > rgb.g)
			min = rgb.g;
	}
	else 
	{
		min = rgb.r;
		max = rgb.b;
		if(rgb.b <= rgb.g)
			max = rgb.g;
		if(rgb.r >= rgb.g)
			min = rgb.g;
	}

	// We apply the formula to get the saturation if max = 0 then 0 else 1 - min / max
	if(max == 0)
		return 0;
	else
		return (1 - (min / max));
}

int* Figura::radialDivision(int ndiv, float initAlpha)
{
	pair<int, int> center = getBarycenter();

	int* points = new int[ndiv];
	int s = sizeVertices();
	Vertice* p;
	initAlpha = initAlpha * PI / 180; // radians

	for (int i = 0; i < ndiv; i++)
	{
		points[i] = 0;
	}

	for (int i = 0; i < s; i++)
	{
		p = getVerticeAt(i);
		if (!p->centro)
		{
			points[locateLocalSector(p->x, p->y, center.first, center.second, ndiv, initAlpha)]++;
		}
	}
	return points;
}