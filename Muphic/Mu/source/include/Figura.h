#pragma once

#ifndef FIGURA_H
#define FIGURA_H

#include <list>
#include <string>
#include "Vertice.h"
#include "math_functions.h"


class Vertice;

using namespace std;

struct Color{ float r; float g; float b;};

class Figura
{
	friend class Figuras;

    public:
		Figura(); // Arbitrario y por defecto
        virtual ~Figura();

/*------Funciones Publicas------*/
		static bool compare(Figura* f1, Figura* f2) {return f1->getVistosidad() > f2->getVistosidad();};
		std::pair<int,int> getSimpleCenter();
		std::pair<int,int> getBarycenter();

		list< std::pair<float,float> > polarize();
		int* Figura::radialDivision(int ndiv, float initAlpha);

/*------envoltorio de la lista stl------*/
		void colocarVertice(Vertice* v);
		void colocarHijo(Figura* f);
		void insertarVertice(Vertice* v, int n);		//Añade un elemento en la pos n empujando el que ya estaba
		void insertarHijo(Figura* f, int n);
		void sortHijo();

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
		Color getRGB();
		int getNumVertices();
		int getId();
		Figura* getParent();
		int getArea();
		float getVistosidad();
		float getColorDifference();


/*------Setters------*/
        void setRGB(float r, float , float b);
		void setColor(string c);
		void setNumVertices(int n);
		void setId(int id);
		void setParent(Figura* p = NULL);
		void setArea(int a);
		void setColorDifference(float c);
		int calcularVistosidad(int sHeight, int sWidth);
		void setVistosidad(float v);

    protected:
		string color;
		Color rgb;
		float vistosidad;
		int numVertices;
		list<Vertice*> listaVertices;
		int id;
		Figura* padre;
		int area;
		list<Figura*> hijos;

		// Establishes the distance between this figure color and the average color of the sheet
		float colorDifference;

    private:
		float distanceCenter(int sHeight, int sWidth);
		float getSaturation();

		// vistosidad priority consts
		float A;
		float B;
		float C;
		
		// Color priority consts
		float pR;
		float pG;
		float pB;
};

#endif // FIGURA_H
