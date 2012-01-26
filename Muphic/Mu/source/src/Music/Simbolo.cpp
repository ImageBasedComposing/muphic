#include "Music/Simbolo.h"

Simbolo::Simbolo(int duracion)
{
    this->duracion = duracion;
}

Simbolo::~Simbolo()
{

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