#include "Figura.h"

Figura::Figura()
{
	vistosidad = -1;
	rgb.r = -1;
	rgb.b = -1;
	rgb.g = -1;
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

//------Setters------//
void Figura::setRGB(int r, int g, int b)
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

int Figura::calcularVistosidad()
{
	if (rgb.r == -1)
		return -1;
	else if (vistosidad == -1)
	{
		vistosidad = rgb.r*3 + rgb.g*2 + rgb.b;
	}
	return vistosidad;
}

void Figura::setVistosidad(float r, float g, float b)
{
	vistosidad = r*3+g*2+b;
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
		{
			it++;
			continue;
		}

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
	// set iterator at initial vertex
	list<Vertice*>::iterator it = listaVertices.begin();
	// for now it's the first vertex, but that can change
	Vertice* currentVertex;
	Vertice* nextVertex;
	int n = 0;
	pair<float, float> tmpVertex;
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

	// first vertex was fixed at 0º degrees, let's fix that
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

float Figura::vectorModule(int x1, int x2, int y1, int y2)
{
	// module = ((x2 - x1)^2 + (y2 - y1)^2)^0.5
	return sqrt(pow((float) x2 - x1, 2) + pow((float)y2 - y1, 2));

}

float Figura::vectorAngle(int x1, int x2, int y1, int y2, float module)
{
	// angle = acos((x2 - x1) / module)
	// it's important to check sin's behaviour as well
	float angle;
	float cos = ((float) x2 - x1) / module;
	float sin = ((float) y2 - y1) / module;
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

float Figura::vectorAngle(int x1, int x2, int y1, int y2)
{
	return vectorAngle(x1, x2, y1, y2, vectorModule(x1, x2, y1, y2));
}

float Figura::turnAngle(float alpha1, float alpha2)
{
	float angleIncr;
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