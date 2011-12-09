#include "Vertice.h"

Vertice::Vertice(int x, int y, bool centro)
{
	this->x = x;
	this->y = y;
	this->centro = centro;
}

Vertice::~Vertice()
{
}

std::pair<int,int> Vertice::getPair()
{
	return make_pair(x, y);
}