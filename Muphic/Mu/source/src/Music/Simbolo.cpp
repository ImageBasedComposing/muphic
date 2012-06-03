#include "Music/Simbolo.h"

Simbolo::Simbolo(int duracion)
{
    this->duracion = duracion;
}

Simbolo::~Simbolo()
{

}

Simbolo* Simbolo::clone()
{
	Simbolo* out = new Simbolo(duracion);
	return out;
}

//------Getters------//
int Simbolo::getDuracion()
{
	return duracion;
}

//------Setters------//
void Simbolo::setDuracion(int d)
{
	duracion = d;
}