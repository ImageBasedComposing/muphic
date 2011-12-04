#pragma once

#ifndef TABLESCALE_H
#define TABLESCALE_H

#include <vector>
#include <string>
#include "music_elements.h"

class TableScale
{
private:
	vector<int> scaleSteps; //Distancia para la siguiente nota medida en semitonos
	int firstNote; //La nota por la que empieza la escala.

	//Dada una escala y la nota por la que empieza.
	TableScale(vector<int> steps, int note)
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

	// Devuelve la siguiente nota en la escala dado la ultima nota.
	int nextTone(int lasTone)
	{
		if(lasTone == 0) //si es silencio devolvemos tmb silencio
			return lasTone;

		int absNote = lasTone%PER8; //ESCALA Y PER8 es lo mismo, la escala es una octava
		if(absNote == 0)
			absNote = SI;
		int actualScale = (lasTone-1)/ESCALA;
		if(firstNote > absNote)  //si la nota en la que estamos se encuentra debajo de la que empieza la escala
		{
			absNote += PER8;
			actualScale--;
		}

		int nexTone = firstNote; //El tono que devolvemos
		int step = 0;	// pasitos que damos en la escala
		while(nexTone <= absNote)
		{ //Recorremos la escala hasta que superemos lasTone.
			nexTone += scaleSteps.at(step);
			step = (step+1)%scaleSteps.size();
		}
		//nexTone forma parte de la escala y además es el siguiente a lasTone
		nexTone = nexTone + actualScale*ESCALA; //La ubicamos en la escala adecuada
		return nexTone;

		if(nexTone > ESCALA*7)  //No nos pasemos de la escala
			return -1;
		else
			return nexTone;
	}

	//Devuelve la nota vecina por abajo en la escala dado una nota.
	int prevTone(int lasTone)
	{
		if(lasTone == 0)  //si es silencio, devolvemos silencio
			return lasTone;

		int absNote = lasTone%PER8;
		if(absNote == 0)
			absNote = SI;
		int actualScale = (lasTone-1)/ESCALA;
		int auxFirstNoteScale = firstNote;
		if(firstNote < absNote)
			auxFirstNoteScale+= PER8;


		int prevtone = auxFirstNoteScale; //El tono que devolvemos
		int step = 0;	// pasitos que damos en la escala
		while(prevtone >= absNote)
		{ //Recorremos la escala hasta que superemos lasTone.
			prevtone -= scaleSteps.at(step);
			step = (step+1)%scaleSteps.size();
		}
		//prevtone forma parte de la escala y además es el siguiente a lasTone
		prevtone = prevtone + actualScale; //La ubicamos en la escala adecuada

		if(prevtone < 0)
			return -1; //Es un error, se produce cuando no se puede bajar mas en la escala.
		else
			return prevtone;
	}

	//Función que devuelve la nota en la escala varios tonos hacia los agudos moviendose siempre en la escala dada.
	int nextNTone(int lasTone, int steps)
	{
		if(lasTone == 0 || steps == 0)  //silencio o con 0 pasos es el propio tono
			return lasTone;

		int absNote = lasTone%PER8; //ESCALA Y PER8 es lo mismo, la escala es una octava
		if(absNote == 0)
			absNote = SI;
		int actualScale = (lasTone-1)/ESCALA;
		if(firstNote > absNote)  //si la nota en la que estamos se encuentra debajo de la que empieza la escala
		{
			absNote += PER8;
			actualScale--;
		}

		int nexTone = firstNote; //El tono que devolvemos
		int step = 0;	// pasitos que damos en la escala
		while(nexTone <= absNote)
		{ //Recorremos la escala hasta que superemos lasTone.
			nexTone += scaleSteps.at(step);
			step = (step+1)%scaleSteps.size();
		}
		while (steps > 0)
		{
			nexTone += scaleSteps.at(step);
			step = (step+1)%scaleSteps.size();
			steps--;
		}
		//nexTone forma parte de la escala y además es el siguiente a lasTone
		nexTone = nexTone + actualScale*ESCALA; //La ubicamos en la escala adecuada

		if(nexTone > ESCALA*7)  //No nos pasemos de la escala
			return -1;
		else
			return nexTone;
	}

	int prevNTone(int lasTone, int steps)
	{
		if(lasTone == 0 || steps == 0)  //si es silencio, devolvemos silencio o sin pasos, es la propia nota.
			return lasTone;

		int absNote = lasTone%PER8;
		if(absNote == 0)
			absNote = SI;
		int actualScale = (lasTone-1)/ESCALA;
		int auxFirstNoteScale = firstNote;
		if(firstNote < absNote)
			auxFirstNoteScale+= PER8;


		int prevtone = auxFirstNoteScale; //El tono que devolvemos
		int step = 0;	// pasitos que damos en la escala
		while(prevtone >= absNote)
		{ //Recorremos la escala hasta que superemos lasTone.
			prevtone -= scaleSteps.at(step);
			step = (step+1)%scaleSteps.size();
		}
		while (steps > 0)
		{
			prevtone -= scaleSteps.at(step);
			step = (step+1)%scaleSteps.size();
			steps--;
		}
		//prevtone forma parte de la escala y además es el siguiente a lasTone
		prevtone = prevtone + actualScale; //La ubicamos en la escala adecuada

		if(prevtone < 0)
			return -1; //Es un error, se produce cuando no se puede bajar mas en la escala.
		else
			return prevtone;
	}

	// Devuelve el grado N de la escala. Ej: 5º Grado -> Dominante.
	int getNDegree(int nDegree)
	{
		int note = firstNote;
		for(int i = 0; i < (nDegree-1); i++)
			note += scaleSteps.at(i % scaleSteps.size());
		return note;
	}
};


struct MajorScale
{
	vector <int> scaleSteps;

	MajorScale()
	{
		scaleSteps.push_back(MAJ2); //De Tónica a supertónica
		scaleSteps.push_back(MAJ2); //Llegamos a mediante
		scaleSteps.push_back(MIN2); //Subdominante
		scaleSteps.push_back(MAJ2); //Dominante
		scaleSteps.push_back(MAJ2); //Submediante
		scaleSteps.push_back(MAJ2); //Sensible
		scaleSteps.push_back(MIN2); //Tonica de nuevo
	}

	vector<int> getScaleSteps(){	return scaleSteps;	}
};

struct MinorScale
{
	vector <int> scaleSteps;

	MinorScale()
	{
		scaleSteps.push_back(MAJ2); //De Tónica a supertónica
		scaleSteps.push_back(MIN2); //Llegamos a mediante
		scaleSteps.push_back(MAJ2); //Subdominante
		scaleSteps.push_back(MAJ2); //Dominante
		scaleSteps.push_back(MIN2); //Submediante
		scaleSteps.push_back(MAJ2); //Sensible
		scaleSteps.push_back(MAJ2); //Tonica de nuevo
	}

	vector<int> getScaleSteps(){	return scaleSteps;	}
};

struct DoricoScale
{
	vector <int> scaleSteps;

	DoricoScale()
	{
		scaleSteps.push_back(MAJ2);
		scaleSteps.push_back(MIN2); 
		scaleSteps.push_back(MAJ2);
		scaleSteps.push_back(MAJ2); 
		scaleSteps.push_back(MAJ2); 
		scaleSteps.push_back(MIN2); 
		scaleSteps.push_back(MAJ2);
	}

	vector<int> getScaleSteps(){	return scaleSteps;	}
};

struct PentatonicMajScale
{
	vector <int> scaleSteps;

	PentatonicMajScale()
	{
		scaleSteps.push_back(MAJ2);
		scaleSteps.push_back(MAJ2); 
		scaleSteps.push_back(MIN3);
		scaleSteps.push_back(MAJ2); 
		scaleSteps.push_back(MIN3); 
	}

	vector<int> getScaleSteps(){	return scaleSteps;	}
};

struct PentatonicMinScale
{
	vector <int> scaleSteps;

	PentatonicMinScale()
	{
		scaleSteps.push_back(MIN3);
		scaleSteps.push_back(MAJ2);
		scaleSteps.push_back(MAJ2); 
		scaleSteps.push_back(MIN3);
		scaleSteps.push_back(MAJ2); 		 
	}

	vector<int> getScaleSteps(){	return scaleSteps;	}
};

#endif