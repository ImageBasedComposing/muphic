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

//Clase ScriabinColor que identifica colores por remodelar a RGB por ejemplo.
class ScriabinColor : public ColorSystem
{

	public:
		ScriabinColor()
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

		~ScriabinColor(){};

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


//Clase NewtonColor Solo tiene 7 de las 12 notas de la escala cromática
class NewtonColor : public ColorSystem
{

	public:
		NewtonColor()
		{
			newton.push_back(pair<Color,int>(Color(255,0,0), DO_C)); //Rojo
			newton.push_back(pair<Color,int>(Color(255,127,0), RE_C)); //Naranja
			newton.push_back(pair<Color,int>(Color(255,255,0), MI_C)); //Amarillo
			newton.push_back(pair<Color,int>(Color(51,204,51), FA_C)); //Verde
			newton.push_back(pair<Color,int>(Color(127,139,253), SOL_C)); //AzulMarino
			newton.push_back(pair<Color,int>(Color(187,117,252), LA_C)); //Indigo
			newton.push_back(pair<Color,int>(Color(144,0,255), SI_C)); //Violeta
		}

		~NewtonColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = newton.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != newton.end())
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
			list< pair<Color,int> > newtonPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = newton.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != newton.end() )
			{
				if( tb->containsTone(it->second) )
					newtonPart.push_back((*it));
				it++;
			}
			
			it = newtonPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != newtonPart.end())
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
		list< pair<Color,int> > newton;
};


//Clase BertrandCastelColor contiene los 12 colores de forma gradiente
class BertrandCastelColor : public ColorSystem
{

	public:
		BertrandCastelColor()
		{
			castel.push_back(pair<Color,int>(Color(28,13,130), DO_C)); //Blue
			castel.push_back(pair<Color,int>(Color(27,144,129), RE_F_C)); //Blue-green
			castel.push_back(pair<Color,int>(Color(20,144,51), RE_C)); //Green
			castel.push_back(pair<Color,int>(Color(112,146,38), MI_F_C)); //Olive-green
			castel.push_back(pair<Color,int>(Color(251,250,60), MI_C)); //yellow
			castel.push_back(pair<Color,int>(Color(241,210,59), FA_C)); //yellow-orange
			castel.push_back(pair<Color,int>(Color(248,128,16), SOL_F_C)); //orange
			castel.push_back(pair<Color,int>(Color(250,11,12), SOL_C)); //red
			castel.push_back(pair<Color,int>(Color(160,12,9), LA_F_C)); //crimson
			castel.push_back(pair<Color,int>(Color(215,19,134), LA_C)); //violet
			castel.push_back(pair<Color,int>(Color(75,14,125), SI_F_C)); //agate
			castel.push_back(pair<Color,int>(Color(127,8,124), SI_C)); //indigo
		}

		~BertrandCastelColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = castel.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != castel.end())
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
			list< pair<Color,int> > castelPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = castel.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != castel.end() )
			{
				if( tb->containsTone(it->second) )
					castelPart.push_back((*it));
				it++;
			}
			
			it = castelPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != castelPart.end())
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
		list< pair<Color,int> > castel;
};


//Clase GFieldColor Atencion, solo contiene 7 de las 12 notas de una escala cromática
class GFieldColor : public ColorSystem
{

	public:
		GFieldColor()
		{
			field.push_back(pair<Color,int>(Color(28,13,130), DO_C)); //Blue
			field.push_back(pair<Color,int>(Color(127,8,124), RE_C)); //indigo
			field.push_back(pair<Color,int>(Color(250,11,12), MI_C)); //red
			field.push_back(pair<Color,int>(Color(248,128,16), FA_C)); //orange
			field.push_back(pair<Color,int>(Color(251,250,60), SOL_C)); //yellow
			field.push_back(pair<Color,int>(Color(112,146,38), LA_C)); //Olive-green
			field.push_back(pair<Color,int>(Color(20,144,51), SI_C)); //Green		
		}

		~GFieldColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = field.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != field.end())
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
			list< pair<Color,int> > fieldPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = field.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != field.end() )
			{
				if( tb->containsTone(it->second) )
					fieldPart.push_back((*it));
				it++;
			}
			
			it = fieldPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != fieldPart.end())
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
		list< pair<Color,int> > field;
};


//Clase JamesonColor contiene los 12 colores
class JamesonColor : public ColorSystem
{

	public:
		JamesonColor()
		{
			jameson.push_back(pair<Color,int>(Color(255,0,0), DO_C)); //Red
			jameson.push_back(pair<Color,int>(Color(244,71,18), RE_F_C)); //red-orange
			jameson.push_back(pair<Color,int>(Color(248,128,16), RE_C)); //orange
			jameson.push_back(pair<Color,int>(Color(241,210,59), MI_F_C)); //orange-yellow
			jameson.push_back(pair<Color,int>(Color(251,250,60), MI_C)); //yellow
			jameson.push_back(pair<Color,int>(Color(20,144,51), FA_C)); //Green
			jameson.push_back(pair<Color,int>(Color(27,144,129), SOL_F_C)); //Blue-green
			jameson.push_back(pair<Color,int>(Color(28,13,130), SOL_C)); //Blue
			jameson.push_back(pair<Color,int>(Color(75,14,125), LA_F_C)); //blue-purple
			jameson.push_back(pair<Color,int>(Color(127,8,124), LA_C)); //purple
			jameson.push_back(pair<Color,int>(Color(166,21,134), SI_F_C)); //purple-violet
			jameson.push_back(pair<Color,int>(Color(215,19,134), SI_C)); //violet			
		}

		~JamesonColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = jameson.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != jameson.end())
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
			list< pair<Color,int> > jamesonPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = jameson.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != jameson.end() )
			{
				if( tb->containsTone(it->second) )
					jamesonPart.push_back((*it));
				it++;
			}
			
			it = jamesonPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != jamesonPart.end())
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
		list< pair<Color,int> > jameson;
};


//Clase SeemanColor contiene los 12 colores
class SeemanColor : public ColorSystem
{

	public:
		SeemanColor()
		{
			jameson.push_back(pair<Color,int>(Color(196,10,9), DO_C)); //Carmine
			jameson.push_back(pair<Color,int>(Color(250,11,12), RE_F_C)); //scarlet
			jameson.push_back(pair<Color,int>(Color(248,128,16), RE_C)); //orange
			jameson.push_back(pair<Color,int>(Color(241,210,59), MI_F_C)); //yellow-orange
			jameson.push_back(pair<Color,int>(Color(251,250,60), MI_C)); //yellow
			jameson.push_back(pair<Color,int>(Color(20,144,51), FA_C)); //Green
			jameson.push_back(pair<Color,int>(Color(27,144,129), SOL_F_C)); //Blue-green
			jameson.push_back(pair<Color,int>(Color(28,13,130), SOL_C)); //Blue
			jameson.push_back(pair<Color,int>(Color(127,8,124), LA_F_C)); //indigo
			jameson.push_back(pair<Color,int>(Color(215,19,134), LA_C)); //violet
			jameson.push_back(pair<Color,int>(Color(106,28,28), SI_F_C)); //brown
			jameson.push_back(pair<Color,int>(Color(7,7,7), SI_C)); //black
						
		}

		~SeemanColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = jameson.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != jameson.end())
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
			list< pair<Color,int> > jamesonPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = jameson.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != jameson.end() )
			{
				if( tb->containsTone(it->second) )
					jamesonPart.push_back((*it));
				it++;
			}
			
			it = jamesonPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != jamesonPart.end())
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
		list< pair<Color,int> > jameson;
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
