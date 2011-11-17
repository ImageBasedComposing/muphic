#pragma once

#ifndef FIGURA_H
#define FIGURA_H

#include <list>
#include <string>
#include "Vertice.h"

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

    private:

};

#endif // FIGURA_H
