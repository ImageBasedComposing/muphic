#pragma once

#ifndef TABLESCALE_H
#define TABLESCALE_H

#include <vector>
#include <string>
#include "Music/music_const.h"

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

/****************************************************************/

class TableScale
{

private:
	vector<int> scaleSteps; //Distancia para la siguiente nota medida en semitonos
	int firstNote; //La nota por la que empieza la escala.

public:
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

	int getFirstNote(){ return firstNote;}
	vector<int> getScaleSteps(){ return scaleSteps;}
	void setFirstNote(int fNote)
	{ 
		if(fNote > 0){
			firstNote = fNote%ESCALA;
		}
		if(firstNote == 0)
			firstNote = SI;
	}

	void setScaleSteps(vector<int> scaSteps)
	{
		scaleSteps = scaSteps;
	}


	//**************************************//

	//Devuelve si la nota pertenece o no a la escala actual.
	bool containsTone(int tone)
	{
		if( tone < 1 ) //Silencio o tono incorrecto
			return false;

		int absNote = tone%ESCALA;

		int auxNote = firstNote;
		bool found = auxNote%ESCALA == absNote;
		int i = 1;
		while(i <= (int)scaleSteps.size() && !found)
		{
			auxNote += scaleSteps.at(i-1);
			i++;
			found = auxNote%PER8 == absNote;
		}

		return found;
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
		int step = scaleSteps.size()-1;	// pasitos que damos en la escala
		while(prevtone >= absNote)
		{ //Recorremos la escala hasta que superemos lasTone.
			prevtone -= scaleSteps.at(step);
			step = mod((step-1),scaleSteps.size());
		}
		//prevtone forma parte de la escala y además es el siguiente a lasTone
		prevtone = prevtone + actualScale*ESCALA; //La ubicamos en la escala adecuada

		if(prevtone < 0)
			return -1; //Es un error, se produce cuando no se puede bajar mas en la escala.
		else
			return prevtone;
	}

	//Función que devuelve la nota en la escala varios tonos hacia los agudos moviendose siempre en la escala dada.
	int nextNTone(int lasTone, int steps)
	{
		steps = abs(steps);
		if(lasTone == 0 || steps == 0 || lasTone == -1)  //silencio o con 0 pasos es el propio tono
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
		steps--;
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
		steps = abs(steps);
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
		int step = scaleSteps.size()-1;	// pasitos que damos en la escala
		while(prevtone >= absNote)
		{ //Recorremos la escala hasta que llegamos a la nota justamente previa a lastnote.
			prevtone -= scaleSteps.at(step);
			step = mod((step-1),scaleSteps.size());
		}
		steps--; //hemos bajado un escalón en la escala
		while (steps > 0)
		{
			prevtone -= scaleSteps.at(step);
			step = mod((step-1),scaleSteps.size());
			steps--;
		}
		//prevtone forma parte de la escala y además es el siguiente a lasTone
		prevtone = prevtone + actualScale*ESCALA; //La ubicamos en la escala adecuada

		if(prevtone < 0)
			return -1; //Es un error, se produce cuando no se puede bajar mas en la escala.
		else
			return prevtone;
	}

	//**********************************//
	// FUNCIONES CON GRADOS
	/* ATENCION, Funciones pensadas para escalas diatónicas (7 notas) */

	// Devuelve el grado N de la escala. Ej: 5º Grado -> Dominante.
	int getToneDegree(int nDegree)
	{
		int note = firstNote;
		for(int i = 0; i < (nDegree-1); i++)
			note += scaleSteps.at(i % scaleSteps.size());
		note = note % ESCALA;
		if(note == 0)
			note = SI;
		return note;
	}

	// Devuelve el grado que es la nota si es que está en la escala. Sino devuelve 0.
	int getDegreeTone(int tone)
	{
		if( tone < 1 ) //Silencio o tono incorrecto
			return 0;

		int absNote = tone%ESCALA;

		int auxNote = firstNote;
		bool found = auxNote%ESCALA == absNote;
		int i = 1;
		while(i <= (int)scaleSteps.size() && !found)
		{
			auxNote += scaleSteps.at(i-1);
			i++;
			found = auxNote%PER8 == absNote;
		}

		if(!found)
			i = 0;

		return i;
	}

	// Dado un grado, devuelve todos los tonos que pertenecen al acorde de grado.
	//Especial el 5º Grado que tiene la 7º. Sino, son 3 notas.
	vector<int> getTonesDegree(int nDegree, bool seventh = false)
	{
		int noteDegree = getToneDegree(nDegree);
		vector<int> out;
		out.push_back(noteDegree);
		out.push_back(nextNTone(out.back(), 2));
		out.push_back(nextNTone(out.back(), 2));
		if(nDegree == DOMINANTE && seventh)
			out.push_back(nextNTone(out.back(), 2));

		return out;
	}

	//Devuelve la nota más cercana que pertenezca al grado dado.
	//Si up, en caso de empate se coge la de arriba, sino la de abajo
	int getDegreeToneNear(int nDegree, int lasTone, bool up)
	{
		int actualScale = (lasTone-1)/ESCALA; 
		vector<int> tonesDegree = getTonesDegree(nDegree);
		//Comprobamos primero si ya es un noteDegree
		for(int i = 0; i < tonesDegree.size(); i++)
			if((tonesDegree.at(i) % ESCALA) == (lasTone % ESCALA))
				return lasTone;
		//Buscamos la note degree más cercana
		int interval = 0, minDist = ESCALA, pos = 0;
		for(int i = 0; i < tonesDegree.size(); i++)
		{
			tonesDegree.at(i) += actualScale*ESCALA;
			if( tonesDegree.at(i) >= lasTone )
				interval = tonesDegree.at(i)-lasTone;
			else
				interval = lasTone-tonesDegree.at(i);
			
			if(interval > PER5)
			{
				interval = ESCALA - interval;
				tonesDegree.at(i) -= ESCALA;
			}
			
			if(minDist >= interval)
			{
				if(minDist > interval)
				{//Si el intervalo es menor, pues es mas cercano
					minDist = interval;
					pos = i;
				}
				else if(up && tonesDegree.at(i) > tonesDegree.at(pos))
				{//si el intervalo es el mismo, pero la nota está por encima
					minDist = interval;
					pos = i;
				}
				else if(!up && tonesDegree.at(i) < tonesDegree.at(pos))
				{//si el intervalo es igual, pero la nota está por debajo
					minDist = interval;
					pos = i;
				}
			}	
		}

		return tonesDegree.at(pos);
	}

	// Devuelve la siguiente nota en el acorde del grado dado. Ejemplo: Grado 1º (Tonica) I -(next)> III -> V -> I(octava encima)
	int nextDegreeTone(int nDegree, int lasTone, bool seventh = false)
	{
		int noteDegree = getToneDegree(nDegree);
		int noteDegree2 = nextNTone(noteDegree, 2);
		int noteDegree3;
		if(nDegree == DOMINANTE && seventh)
			noteDegree3 = nextNTone(noteDegree2, 4); //Ponemos la 7º
		else
			noteDegree3 = nextNTone(noteDegree2, 2);

		lasTone = getDegreeToneNear(nDegree, lasTone, false);

		if(lasTone%ESCALA == noteDegree3%ESCALA)
			if(nDegree == DOMINANTE && seventh)
				return nextNTone(lasTone, 1);
			else
				return nextNTone(lasTone, 3);
		else
			return nextNTone(lasTone, 2);
	}

	// Devuelve la nota previa dentro del acorde del grado de la escala
	int prevDegreeTone(int nDegree, int lasTone, bool seventh = false)
	{
		int noteDegree = getToneDegree(nDegree);

		lasTone = getDegreeToneNear(nDegree, lasTone, true);

		if(lasTone%ESCALA == noteDegree%ESCALA)
			if(nDegree == DOMINANTE && seventh)
				return prevNTone(lasTone, 1);
			else
				return prevNTone(lasTone, 3);
		else
			return prevNTone(lasTone, 2);
	}

	// Devuelve la siguiente N nota dentro del acorde. ej: si steps=3 entonces subimos una octava
	int nextNDegreeTone(int nDegree, int lasTone, int steps, bool seventh = false)
	{
		steps = abs(steps);
		int nexTone = lasTone;
		if(lasTone == 0 || steps == 0 || lasTone == -1)  //silencio o con 0 pasos es el propio tono
			return nexTone;

		for(int i = 0; i < steps; i++)
			nexTone = nextDegreeTone(nDegree, nexTone, seventh);

		return nexTone;

		/*int i = 0;
		int noteDegree = getToneDegree(nDegree);
		int noteDegree2 = nextNTone(noteDegree, 2);
		int noteDegree3 = nextNTone(noteDegree2, 2);
		if( noteDegree%ESCALA == lasTone%ESCALA )
			i = 0;
		else if( noteDegree2%ESCALA == lasTone%ESCALA )
				i = 1;
		else
				i = 2;

		int step = 0; //Pasos que vamos a dar en la escala
		while (steps > 0)
		{
			if( i < 2)
				step = step + 2;
			else
				step = step + 3;		
			steps--;
			i = (i+1) % 3; 
		}
		nexTone = nextNTone(lasTone, step);

		if(nexTone > ESCALA*7)  //No nos pasemos de la escala
			return -1;  //ERROR!
		else
			return nexTone;*/
	}

	// Devuelve la N nota previa dentro del acorde.
	int prevNDegreeTone(int nDegree, int lasTone, int steps, bool seventh = false)
	{
		steps = abs(steps);
		int prevtone = lasTone;
		if(lasTone == 0 || steps == 0 || lasTone == -1)  //silencio o con 0 pasos es el propio tono
			return prevtone;

		for(int i = 0; i < steps; i++)
			prevtone = prevDegreeTone(nDegree, prevtone, seventh);

		return prevtone;

		/*int i = 0;
		int noteDegree = getToneDegree(nDegree);
		int noteDegree2 = nextNTone(noteDegree, 2);
		int noteDegree3 = nextNTone(noteDegree2, 2);
		if( noteDegree%ESCALA == lasTone%ESCALA )
			i = 0;
		else if( noteDegree2%ESCALA == lasTone%ESCALA )
				i = 1;
		else
				i = 2;

		int step = 0; //Pasos que vamos a dar en la escala
		while (steps > 0)
		{
			if( i == 0)
				step = step + 3;
			else
				step = step + 2;		
			steps--;
			i = (i+1) % 3; 
		}
		prevtone = prevNTone(lasTone, step);

		if(prevtone < 0)
			return -1; //ERROR, se produce cuando no se puede bajar mas en la escala.
		else
			return prevtone;*/
	}



};

#endif