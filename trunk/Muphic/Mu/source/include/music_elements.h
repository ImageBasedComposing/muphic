#pragma once

#ifndef MUSIC_ELEMS_H
#define MUSIC_ELEMS_H

#include "music_const.h"
#include <list>
#include <string>
#include "string.h"
#include "instruments.h"


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



//Clase Scriabin que identifica colores por remodelar a RGB por ejemplo.
class Scriabin
{
	public:
		Scriabin()
		{
			scriabin.push_back(pair<string,int>("Rojo", DO_C));
			scriabin.push_back(pair<string,int>("Naranja", SOL_C));
			scriabin.push_back(pair<string,int>("Amarillo", RE_C));
			scriabin.push_back(pair<string,int>("Verde", LA_C));
			scriabin.push_back(pair<string,int>("Cian", MI_C));
			scriabin.push_back(pair<string,int>("Azul", SI_C));
			scriabin.push_back(pair<string,int>("AzulMarino", SOL_C - 1));
			scriabin.push_back(pair<string,int>("Purpura", RE_C - 1));
			scriabin.push_back(pair<string,int>("Violeta", LA_C - 1));
			scriabin.push_back(pair<string,int>("Morado", MI_C - 1));
			scriabin.push_back(pair<string,int>("Salmon", SI_C - 1));
			scriabin.push_back(pair<string,int>("Granate", FA_C));
		}

		~Scriabin(){};

		int getNota(string color)
		{
			list< pair<string,int> >::iterator it = scriabin.begin();
			bool found = false;
			int sol = -1;

			while(!found && it != scriabin.end())
			{
				if(strcmp(it->first.c_str(), color.c_str())==0)
				{
					sol = it->second;
					found = true;
				}
				it++;
			}

			return sol;
		}

	protected:
	private:
		list< pair<string,int> > scriabin;
};


#endif // MUSIC_ELEMS
