#pragma once

#ifndef MUSIC_ELEMS_H
#define MUSIC_ELEMS_H

#include "Music/music_const.h"
#include "math_functions.h"
#include "aux_structs.h"
#include <list>
#include <string>
#include "string.h"
#include "Music/instruments.h"
#include "Music/TableScale.h"


using namespace std;

struct Metrica {
	int upper;
	int lower;
	Metrica(int a = 4, int b = 4)
	{
		upper = a;
		lower = b;
	}
};

typedef int Tempo;

typedef int Instrumento;

    //Armaduras: 0    0     1     1     2     2     3     3     4     4     5      5      6     6     7     7
enum Tonalidad{ DOM, LAm, SOLM,  MIm,  REM,  SIm,  LAM, FASm,  MIM, DOSm,  SIM, SOLSm,  FASM, RESm, DOSM, LASm,  //Sostenidos
						   FAM,  REm, SIBM, SOLm, MIBM,  DOm, LABM,  FAm, REBM,  SIBm, SOLBM, MIBm, DOBM, LABm}; //Bemoles
//							FA#/SIb  |  DO#/MIb  | SOL#/LAb  |  RE#/REb  |  LA#/SOLb  |  MI#/DOb   |  SI#/FAb  | //los sostenidos o bemoles que hay en la armadura


//Clase padre para crear sistemas de colores
class ColorSystem
{

	public:
		ColorSystem()
		{}

		virtual ~ColorSystem(){};

		//Devuelve la nota correspondiente al color según el sistema 
		virtual int getNota(Color color){ return 0;}

		//Devuelve la nota más cercana al color dado dentro de una escala.
		virtual int getNota(Color color, TableScale* tb){ return 0;}

	protected:
	private:
};

//Clase Scriabin que identifica colores por remodelar a RGB por ejemplo.
class Scriabin : public ColorSystem
{

	public:
		Scriabin()
		{
			scriabin.push_back(pair<Color,int>(Color(255,0,0), DO_C)); //Rojo
			scriabin.push_back(pair<Color,int>(Color(255,127,0), SOL_C)); //Naranja
			scriabin.push_back(pair<Color,int>(Color(255,255,0), RE_C)); //Amarillo
			scriabin.push_back(pair<Color,int>(Color(51,204,51), LA_C)); //Verde
			scriabin.push_back(pair<Color,int>(Color(195,242,255), MI_C)); //Cian-Blanco
			scriabin.push_back(pair<Color,int>(Color(142,201,255), SI_C)); //Azul
			scriabin.push_back(pair<Color,int>(Color(127,139,253), SOL_F_C)); //AzulMarino
			scriabin.push_back(pair<Color,int>(Color(144,0,255), RE_F_C)); //Purpura
			scriabin.push_back(pair<Color,int>(Color(187,117,252), LA_F_C)); //Violeta
			scriabin.push_back(pair<Color,int>(Color(183,70,139), MI_F_C)); //Morado
			scriabin.push_back(pair<Color,int>(Color(169,103,124), SI_F_C)); //Salmon
			scriabin.push_back(pair<Color,int>(Color(171,0,52), FA_C)); //Granate
		}

		~Scriabin(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = scriabin.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != scriabin.end())
			{
				dist = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
				if(dist < distBetter)
				{	//Hemos encontrado uno mejor
					note = it->second;
					distBetter = dist;
					found = distBetter < minDist; //Si mejora la distancia minima, automaticamente salimos
				}
				it++;
			}

			return note;
		}

		//Devuelve la nota más cercana al color dado dentro de una escala.
		int getNota(Color color, TableScale* tb)
		{
			list< pair<Color,int> > scriabinPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = scriabin.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != scriabin.end() )
			{
				if( tb->containsTone(it->second) )
					scriabinPart.push_back((*it));
				it++;
			}
			
			it = scriabinPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != scriabinPart.end())
			{
				dist = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
				if(dist < distBetter)
				{	//Hemos encontrado uno mejor
					note = it->second;
					distBetter = dist;
				}
				it++;
			}

			return note;

		}

	protected:
	private:
		list< pair<Color,int> > scriabin;
};

inline bool isConsonantInterval(int firstNote, int secondNote)
{
	int interval;
	if(firstNote > secondNote) //Be carefull with which note is the first an the second
		interval = (firstNote - secondNote)%ESCALA;
	else
		interval = (secondNote - firstNote)%ESCALA;

	switch(interval)
	{
		case PER1:
		case MIN3:
		case MAJ3:
		case PER4:
		case PER5:
		case MIN6:
		case MAJ6:
		case PER8:
			return true;
		default:
			return false;
	}
}

inline bool isDissonantInterval(int firstNote, int secondNote)
{
	return !(isConsonantInterval(firstNote, secondNote));
}

#endif // MUSIC_ELEMS
