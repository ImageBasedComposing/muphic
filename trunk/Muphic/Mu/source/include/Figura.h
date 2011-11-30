#pragma once

#ifndef FIGURA_H
#define FIGURA_H

#include <list>
#include <string>
#include "Vertice.h"
#include <math.h>

#define PI 3.1415926535897932384626433832795

using namespace std;

class Figura
{
    public:
		Figura(); // Arbitrario y por defecto
        virtual ~Figura();

		/* envoltorio de la lista stl */

		void colocarVertice(Vertice* v);
		void colocarHijo(Figura* f);
		void insertarVertice(Vertice* v, int n);		//Añade un elemento en la pos n empujando el que ya estaba
		void insertarHijo(Figura* f, int n);

		Vertice* getVerticeAt(int n);
		Vertice* verticeSig(Vertice* v);
		Vertice* verticeAnt(Vertice* v);
		Figura* getHijoAt(int n);

		bool emptyVertices();
		bool emptyHijos();
		int sizeVertices();
		int sizeHijos();

		static bool compare(Figura* f1, Figura* f2) {return f1->getArea() > f2->getArea();};
		pair<int,int> getSimpleCenter();
		pair<int,int> getBarycenter();

		list< pair<float,float> > polarize();

/*------Getters------*/
        string getColor();
		int getNumVertices();
		int getId();
		Figura* getParent();
		int getArea();


		/*------Setters------*/
        void setColor(string c);
		void setNumVertices(int n);
		void setId(int id);
		void setParent(Figura* p = NULL);
		void setArea(int a);

    protected:
		string color;
		int numVertices;
		list<Vertice*> listaVertices;
		int id;
		Figura* padre;
		int area;
		list<Figura*> hijos;

		float vectorModule(int x1, int x2, int y1, int y2);					// module of a vector
		float vectorAngle(int x1, int x2, int y1, int y2, float module);	// angle of two vectors, in decimal angles
		float vectorAngle(int x1, int x2, int y1, int y2);

		// given an angle alpha1, and a new angle alpha2, returns if the second one means a right turn (-180,0) or a left turn (0,180)
		// works with decimal angles
		float turnAngle(float alpha1, float alpha2);

    private:

};

#endif // FIGURA_H
