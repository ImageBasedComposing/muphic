#pragma once

#ifndef SIMBOLO_H
#define SIMBOLO_H


class Simbolo
{
    public:
        Simbolo();
		Simbolo(float duracion);
        virtual ~Simbolo();

		/*------Getters------*/
        virtual float getDuracion();

		/*------Setters------*/
        virtual void setDuracion(float d);

    protected:

		float duracion;
    private:

};

#endif // SIMBOLO_H
