#pragma once

#ifndef VERTICE_H
#define VERTICE_H

class Vertice
{
    public:
		Vertice(int x = 0, int y = 0, bool centro = 0);
        virtual ~Vertice();

		int x;
		int y;
		bool centro;

    protected:
    private:

};

#endif // VERTICE_H
