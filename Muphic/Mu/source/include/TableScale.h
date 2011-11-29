#pragma once

#ifndef TABLESCALE_H
#define TABLESCALE_H

#include <list>
#include <string>
#include "music_elements.h"

class TableScale
{
private:
	list<int> scaleSteps; //Distancia para la siguiente nota medida en semitonos
	int firstNote; //La nota por la que empieza la escala.

	//Dada una escala y la nota por la que empieza.
	TableScale(list<int> steps, int note)
	{
		scaleSteps = steps;
		firstNote = note%ESCALA;
		if(firstNote == 0)
			firstNote = SI;
	}

	TableScale()
	{
		MajorScale scale;  //Hacemos la escala en DoM
		scaleSteps = scale.getScaleSteps();
		firstNote = DO;
	}

	int getNextTone(int lastTone)
	{
		int absNote = lastTone%P8; //ESCALA Y P8 es lo mismo, la escala es una octava
		if(firstNote > absNote)
			absNote+P8;
		int nextTone = 0;
		int step = 0;
		while(nextTone <= lastTone)
			nextTone += scaleSteps.;
	}

};


struct MajorScale
{
	list <int> scaleSteps;

	MajorScale()
	{
		scaleSteps.push_back(M2); //De Tónica a supertónica
		scaleSteps.push_back(M2); //Llegamos a mediante
		scaleSteps.push_back(MIN2); //Subdominante
		scaleSteps.push_back(M2); //Dominante
		scaleSteps.push_back(M2); //Submediante
		scaleSteps.push_back(M2); //Sensible
		scaleSteps.push_back(MIN2); //Tonica de nuevo
	}

	list<int> getScaleSteps(){	return scaleSteps;	}
};

struct MinorScale
{
	list <int> scaleSteps;

	MinorScale()
	{
		scaleSteps.push_back(M2); //De Tónica a supertónica
		scaleSteps.push_back(MIN2); //Llegamos a mediante
		scaleSteps.push_back(M2); //Subdominante
		scaleSteps.push_back(M2); //Dominante
		scaleSteps.push_back(MIN2); //Submediante
		scaleSteps.push_back(M2); //Sensible
		scaleSteps.push_back(M2); //Tonica de nuevo
	}

	list<int> getScaleSteps(){	return scaleSteps;	}
};

struct DoricoScale
{
	list <int> scaleSteps;

	DoricoScale()
	{
		scaleSteps.push_back(M2);
		scaleSteps.push_back(MIN2); 
		scaleSteps.push_back(M2);
		scaleSteps.push_back(M2); 
		scaleSteps.push_back(M2); 
		scaleSteps.push_back(MIN2); 
		scaleSteps.push_back(M2);
	}

	list<int> getScaleSteps(){	return scaleSteps;	}
};

struct PentatonicMajScale
{
	list <int> scaleSteps;

	PentatonicMajScale()
	{
		scaleSteps.push_back(M2);
		scaleSteps.push_back(M2); 
		scaleSteps.push_back(MIN3);
		scaleSteps.push_back(M2); 
		scaleSteps.push_back(MIN3); 
	}

	list<int> getScaleSteps(){	return scaleSteps;	}
};

struct PentatonicMinScale
{
	list <int> scaleSteps;

	PentatonicMinScale()
	{
		scaleSteps.push_back(MIN3);
		scaleSteps.push_back(M2);
		scaleSteps.push_back(M2); 
		scaleSteps.push_back(MIN3);
		scaleSteps.push_back(M2); 		 
	}

	list<int> getScaleSteps(){	return scaleSteps;	}
};

#endif