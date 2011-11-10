#include "Simbolo.h"

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