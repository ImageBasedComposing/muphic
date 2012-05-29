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
			seeman.push_back(pair<Color,int>(Color(196,10,9), DO_C)); //Carmine
			seeman.push_back(pair<Color,int>(Color(250,11,12), RE_F_C)); //scarlet
			seeman.push_back(pair<Color,int>(Color(248,128,16), RE_C)); //orange
			seeman.push_back(pair<Color,int>(Color(241,210,59), MI_F_C)); //yellow-orange
			seeman.push_back(pair<Color,int>(Color(251,250,60), MI_C)); //yellow
			seeman.push_back(pair<Color,int>(Color(20,144,51), FA_C)); //Green
			seeman.push_back(pair<Color,int>(Color(27,144,129), SOL_F_C)); //Blue-green
			seeman.push_back(pair<Color,int>(Color(28,13,130), SOL_C)); //Blue
			seeman.push_back(pair<Color,int>(Color(127,8,124), LA_F_C)); //indigo
			seeman.push_back(pair<Color,int>(Color(215,19,134), LA_C)); //violet
			seeman.push_back(pair<Color,int>(Color(106,28,28), SI_F_C)); //brown
			seeman.push_back(pair<Color,int>(Color(7,7,7), SI_C)); //black
						
		}

		~SeemanColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = seeman.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != seeman.end())
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
			list< pair<Color,int> > seemanPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = seeman.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != seeman.end() )
			{
				if( tb->containsTone(it->second) )
					seemanPart.push_back((*it));
				it++;
			}
			
			it = seemanPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != seemanPart.end())
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
		list< pair<Color,int> > seeman;
};


//Clase WallaceRimingtonColor contiene los 12 colores
class WallaceRimingtonColor : public ColorSystem
{

	public:
		WallaceRimingtonColor()
		{
			wallace.push_back(pair<Color,int>(Color(250,11,12), DO_C)); //Deep red
			wallace.push_back(pair<Color,int>(Color(160,12,9), RE_F_C)); //crimson
			wallace.push_back(pair<Color,int>(Color(244,71,18), RE_C)); //orange-crimson
			wallace.push_back(pair<Color,int>(Color(248,128,16), MI_F_C)); //orange
			wallace.push_back(pair<Color,int>(Color(251,250,60), MI_C)); //yellow
			wallace.push_back(pair<Color,int>(Color(112,146,38), FA_C)); //yellow-Green
			wallace.push_back(pair<Color,int>(Color(20,144,51), SOL_F_C)); //green
			wallace.push_back(pair<Color,int>(Color(39,164,129), SOL_C)); //Blueish green
			wallace.push_back(pair<Color,int>(Color(27,144,129), LA_F_C)); //Blue green
			wallace.push_back(pair<Color,int>(Color(127,8,124), LA_C)); //indigo
			wallace.push_back(pair<Color,int>(Color(28,13,130), SI_F_C)); //deep blue
			wallace.push_back(pair<Color,int>(Color(215,19,134), SI_C)); //violet
						
		}

		~WallaceRimingtonColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = wallace.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != wallace.end())
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
			list< pair<Color,int> > wallacePart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = wallace.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != wallace.end() )
			{
				if( tb->containsTone(it->second) )
					wallacePart.push_back((*it));
				it++;
			}
			
			it = wallacePart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != wallacePart.end())
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
		list< pair<Color,int> > wallace;
};


//Clase BishopColor contiene los 12 colores
class BishopColor : public ColorSystem
{

	public:
		BishopColor()
		{
			bishop.push_back(pair<Color,int>(Color(250,11,12), DO_C)); //red
			bishop.push_back(pair<Color,int>(Color(160,12,9), RE_F_C)); //scarlet
			bishop.push_back(pair<Color,int>(Color(248,128,16), RE_C)); //orange
			bishop.push_back(pair<Color,int>(Color(246,209,17), MI_F_C)); //gold or yellow-orange
			bishop.push_back(pair<Color,int>(Color(251,250,60), MI_C)); //yellow or green-gold
			bishop.push_back(pair<Color,int>(Color(188,224,57), FA_C)); //yellow-green
			bishop.push_back(pair<Color,int>(Color(20,144,51), SOL_F_C)); //green
			bishop.push_back(pair<Color,int>(Color(39,164,129), SOL_C)); //greenish-blue or aquamarine
			bishop.push_back(pair<Color,int>(Color(127,8,124), LA_F_C)); //indigo or violet-blue
			bishop.push_back(pair<Color,int>(Color(215,19,134), LA_C)); //violet
			bishop.push_back(pair<Color,int>(Color(217,25,81), SI_F_C)); //violet-red
			bishop.push_back(pair<Color,int>(Color(250,11,10), SI_C)); //red
						
		}

		~BishopColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = bishop.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != bishop.end())
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
			list< pair<Color,int> > bishopPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = bishop.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != bishop.end() )
			{
				if( tb->containsTone(it->second) )
					bishopPart.push_back((*it));
				it++;
			}
			
			it = bishopPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != bishopPart.end())
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
		list< pair<Color,int> > bishop;
};


//Clase HemlholtzColor contiene los 12 colores
class HemlholtzColor : public ColorSystem
{

	public:
		HemlholtzColor()
		{
			hemlholtz.push_back(pair<Color,int>(Color(245,244,60), DO_C)); //yellow
			hemlholtz.push_back(pair<Color,int>(Color(20,144,51), RE_F_C)); //green
			hemlholtz.push_back(pair<Color,int>(Color(27,144,129), RE_C)); //greenish blue
			hemlholtz.push_back(pair<Color,int>(Color(28,91,160), MI_F_C)); //cayan-blue
			hemlholtz.push_back(pair<Color,int>(Color(127,8,124), MI_C)); //indigo blue
			hemlholtz.push_back(pair<Color,int>(Color(215,19,134), FA_C)); //violet
			hemlholtz.push_back(pair<Color,int>(Color(157,14,85), SOL_F_C)); //end of red
			hemlholtz.push_back(pair<Color,int>(Color(250,11,10), SOL_C)); //red
			hemlholtz.push_back(pair<Color,int>(Color(211,44,10), LA_F_C)); //red-carmin
			hemlholtz.push_back(pair<Color,int>(Color(211,44,11), LA_C)); //red-carmin
			hemlholtz.push_back(pair<Color,int>(Color(246,46,13), SI_F_C)); //red orange
			hemlholtz.push_back(pair<Color,int>(Color(241,122,15), SI_C)); //orange
						
		}

		~HemlholtzColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = hemlholtz.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != hemlholtz.end())
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
			list< pair<Color,int> > hemlholtzPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = hemlholtz.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != hemlholtz.end() )
			{
				if( tb->containsTone(it->second) )
					hemlholtzPart.push_back((*it));
				it++;
			}
			
			it = hemlholtzPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != hemlholtzPart.end())
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
		list< pair<Color,int> > hemlholtz;
};


//Clase KleinColor contiene los 12 colores
class KleinColor : public ColorSystem
{

	public:
		KleinColor()
		{
			klein.push_back(pair<Color,int>(Color(196,10,9), DO_C)); //dark red
			klein.push_back(pair<Color,int>(Color(255,11,12), RE_F_C)); //red
			klein.push_back(pair<Color,int>(Color(244,71,18), RE_C)); //red orange
			klein.push_back(pair<Color,int>(Color(248,128,16), MI_F_C)); //orange
			klein.push_back(pair<Color,int>(Color(245,244,60), MI_C)); //yellow
			klein.push_back(pair<Color,int>(Color(188,224,57), FA_C)); //yellow green
			klein.push_back(pair<Color,int>(Color(20,144,51), SOL_F_C)); //green
			klein.push_back(pair<Color,int>(Color(27,144,129), SOL_C)); //blue-green
			klein.push_back(pair<Color,int>(Color(28,13,130), LA_F_C)); //blue
			klein.push_back(pair<Color,int>(Color(120,24,135), LA_C)); //blue violet
			klein.push_back(pair<Color,int>(Color(215,19,134), SI_F_C)); //violet
			klein.push_back(pair<Color,int>(Color(157,14,85), SI_C)); //dark violet
						
		}

		~KleinColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = klein.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != klein.end())
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
			list< pair<Color,int> > kleinPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = klein.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != klein.end() )
			{
				if( tb->containsTone(it->second) )
					kleinPart.push_back((*it));
				it++;
			}
			
			it = kleinPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != kleinPart.end())
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
		list< pair<Color,int> > klein;
};


//Clase AeppliColor contiene los 12 colores
class AeppliColor : public ColorSystem
{

	public:
		AeppliColor()
		{
			//Falta por asignar bien:
			klein.push_back(pair<Color,int>(Color(196,10,9), DO_C)); //dark red
			klein.push_back(pair<Color,int>(Color(255,11,12), RE_F_C)); //red
			klein.push_back(pair<Color,int>(Color(244,71,18), RE_C)); //red orange
			klein.push_back(pair<Color,int>(Color(248,128,16), MI_F_C)); //orange
			klein.push_back(pair<Color,int>(Color(245,244,60), MI_C)); //yellow
			klein.push_back(pair<Color,int>(Color(188,224,57), FA_C)); //yellow green
			klein.push_back(pair<Color,int>(Color(20,144,51), SOL_F_C)); //green
			klein.push_back(pair<Color,int>(Color(27,144,129), SOL_C)); //blue-green
			klein.push_back(pair<Color,int>(Color(28,13,130), LA_F_C)); //blue
			klein.push_back(pair<Color,int>(Color(120,24,135), LA_C)); //blue violet
			klein.push_back(pair<Color,int>(Color(215,19,134), SI_F_C)); //violet
			klein.push_back(pair<Color,int>(Color(157,14,85), SI_C)); //dark violet
						
		}

		~AeppliColor(){};

		//Devuelve la nota correspondiente al color según Scriabin
		int getNota(Color color)
		{
			list< pair<Color,int> >::iterator it = klein.begin();
			bool found = false;
			double minDist = 38.85/2; //Minima distancia entre dos colores contiguos(/2) para saber que es el color buscado sin pasar por todos
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			found = distBetter < minDist;
			it++;
			while(!found && it != klein.end())
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
			list< pair<Color,int> > kleinPart; //Solo vamos a colocar parte de scribin aqui
			list< pair<Color,int> >::iterator it = klein.begin();
			//Cogemos solo las notas que aparecen en la escala
			while( it != klein.end() )
			{
				if( tb->containsTone(it->second) )
					kleinPart.push_back((*it));
				it++;
			}
			
			it = kleinPart.begin();
			int note = SILENCIO; //Voy a dejarlo que ponga silencio si no lo encuentra, que -1 me da errores
			double dist, distBetter;

			distBetter = dist3DPoints(color.r, color.g, color.b, it->first.r, it->first.g, it->first.b);
			note = it->second;
			it++;
			while(it != kleinPart.end())
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
		list< pair<Color,int> > klein;
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
