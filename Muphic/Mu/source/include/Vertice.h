#pragma once

#ifndef VERTICE_H
#define VERTICE_H

#include <utility>

class Vertice
{
    public:
		Vertice(int x = 0, int y = 0, bool centro = 0);
        virtual ~Vertice();

		int x;
		int y;
		bool centro;

		//Devuelve el par x, y. Función para mayor comodidad al programador
		std::pair<int,int> getPair();

    protected:
    private:

};

#endif // VERTICE_H
