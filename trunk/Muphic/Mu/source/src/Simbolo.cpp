#include "Simbolo.h"

Simbolo::Simbolo()
{
	//por defecto
    duracion = 16; // duracion de una negra
}

Simbolo::Simbolo(float duracion)
{
    this->duracion = duracion;
}

Simbolo::~Simbolo()
{

}

//------Getters------//
float Simbolo::getDuracion()
{
	return duracion;
}

//------Setters------//
void Simbolo::setDuracion(float d)
{
	duracion = d;
}