#include "Figura.h"

Figura::Figura()
{
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

//------Setters------//
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

// calcula el centro de una figura con más de dos vértices
pair<int,int> Figura::getSimpleCenter()
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
			continue;

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

	pair<int,int> out;

	out.first = (xmax + xmin) / 2;
	out.second = (ymax + ymin) / 2;

	return out;
}

// calcula el centro de una figura con más de dos vértices
pair<int,int> Figura::getBarycenter()
{
	list<Vertice*>::iterator it = listaVertices.begin();
	int xcont = 0;
	int ycont = 0;

	while( it != listaVertices.end())
	{
		if ((*it)->centro)
			continue;

		xcont += (*it)->x;
		ycont += (*it)->y;

		it++;
	}

	pair<int,int> out;

	out.first = xcont / listaVertices.size();
	out.second = ycont / listaVertices.size();

	return out;
}

// devuelve la figura como una lista de vértices en coordenadas psuedo-polares (ángulo y longitudes relativas, sin punto de origen)
list< pair<float,float> > Figura::polarize()
{
	// initialize random
	srand( time(NULL) );

	// Choose initial vertex
	int n = rand() % getNumVertices();
	
	// set iterator at initial vertex
	list<Vertice*>::iterator it = listaVertices.begin();
	for(int i = 0; i < n; i++)
	{
		it++;
	}

	Vertice* currentVertex;
	Vertice* nextVertex;
	n = 0;
	pair<float, float> tmpVertex;
	list< pair<float, float> > polarizedFigure;
	float oldalpha = 0, newalpha = 0;
	float length;
	float angleIncr;
	float cos;
	float sin;
	while (n < getNumVertices())
	{
		// get current vertex
		currentVertex = (*it);
		// get next vertex
		it++;
		if (it == listaVertices.end())
			it = listaVertices.begin();
		nextVertex = (*it);


		// module = ((x2 - x1)^2 + (y2 - y1)^2)^0.5
		length = sqrt(pow((float) nextVertex->x - currentVertex->x, 2) + pow((float) nextVertex->y - currentVertex->y, 2));
		
		// angle = acos((x2 - x1) / module)
		// it's important to check sin's behaviour as well
		cos = ((float) nextVertex->x - currentVertex->x) / length;
		sin = ((float) nextVertex->y - currentVertex->y) / length;
		if (sin >= 0)
		{
			newalpha = acos(cos); // sin 0 gives angle 0, not 360
		}
		else
		{
			newalpha = 2*PI - acos(cos);
		}
		// cast to decimal angles
		newalpha *= (180/PI);


		// increment
		angleIncr = newalpha - oldalpha;
		// increments are limited to (-180, 180)
		// case 1: 0 < increment < 180: left turn, stays as it is
		// case 2: 180 <= increment: right turn
		if (angleIncr >= 180)
			angleIncr = -(360 - angleIncr); // right turns are negative increments
		// case 3: increment <= -180: left turn
		else if (angleIncr <= -180) 
			angleIncr = 360 + angleIncr; // left turns are positive increments
		// case 4: -180 < increment < 0: right turn, stays as it is

		// put vertex
		tmpVertex.first = angleIncr;
		tmpVertex.second = length;
		polarizedFigure.push_back(tmpVertex);

		// current values are now old values
		oldalpha = newalpha;

		// advance
		n++;
	}

	return polarizedFigure;
}