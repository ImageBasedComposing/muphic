#pragma once

#ifndef MUSIC_ELEMS_H
#define MUSIC_ELEMS_H

#include <list>
#include <string>

using namespace std;

const int QUARTERNOTE = 16;

typedef int Clave;
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

//Tamaño de la escala cromática 12 semitonos:
#define ESCALA 12

//Escala inicial, sirve para luego añadirle escalas.
#define DO 1
#define RE 3
#define MI 5
#define FA 6
#define SOL 8
#define LA 10
#define SI 12
//Por ejemplo, DO_C = DO + ESCALA * 3 = 37 (hemos subido 3 escalas el do, nos encontramos en el principio de la 4º escala)

//Escala central del piano:
#define DO_C 37
#define RE_C 39
#define MI_C 41
#define FA_C 42
#define SOL_C 44
#define LA_C 46
#define SI_C 48

//Armaduras: 0    0     1     1     2     2     3     3     4     4     5      5      6     6     7     7
enum Tonalidad{ DOM, LAm, SOLM,  MIm,  REM,  SIm,  LAM, FASm,  MIM, DOSm,  SIM, SOLSm,  FASM, RESm, DOSM, LASm,  //Sostenidos
					   FAM,  REm, SIBM, SOLm, MIBM,  DOm, LABM,  FAm, REBM,  SIBm, SOLBM, MIBm, DOBM, LABm}; //Bemoles
//						FA#/SIb  |  DO#/MIb  | SOL#/LAb  |  RE#/REb  |  LA#/SOLb  |  MI#/DOb   |  SI#/FAb  | //los sostenidos o bemoles que hay en la armadura


//Clase que ayuda a la hora de transformar nuestros simbolos/sonidos en notas que reconoce ABC
class TablaEscala
{
private:
	string t1;	//semitono 1er de la escala
	string t2; //...
	string t3;
	string t4;
	string t5;
	string t6;
	string t7;
	string t8;
	string t9;
	string t10;
	string t11;
	string t0;
	list< pair<int,int> > armadura;  //Sostenidos y bemoles de la tonalidad
	list< pair<int,int> > accidentes;//Accidentes que se vacían cuando termina el compás.

	//Buscamos en las listas.
	bool findPairInList(list< pair<int,int> > lista, pair<int, int> parBuscado)
	{
		list< pair<int,int> >::iterator it = lista.begin();
		bool found = false;
		while(!found && it != lista.end())
		{
			found = (*it) == parBuscado;
			it++;
		}
		return found;
	}

public:
	TablaEscala()
	{ //por defecto la escala Do Mayor
		t1 = "C";  //DO
		t2 = "";
		t3 = "D";  //RE
		t4 = "";
		t5 = "E";  //MI
		t6 = "F";  //FA
		t7 = "";
		t8 = "G";  //SOL
		t9 = "";
		t10 = "A"; //LA
		t11 = "";
		t0 = "B"; //SI
		accidentes.clear();
		armadura.clear();
	}

	// Devuelve el valor de una nota en la tabla
	string getNota(int pos)
	{
		switch(pos){
		case 1: return t1;
		case 2: return t2;
		case 3: return t3;
		case 4: return t4;
		case 5: return t5;
		case 6: return t6;
		case 7: return t7;
		case 8: return t8;
		case 9: return t9;
		case 10: return t10;
		case 11: return t11;
		case 0: return t0;
		default: return "";
		}
		return "";
	}

	//Función que te devuelve el string asociado a una tonalidad dada.
	std::string transformTonalidad(Tonalidad t)
	{
		switch(t){
			case 0: return "C";
			case 1: return "Am";
				// Con sostenidos
			case 2: return "G";
			case 3: return "Em";
			case 4: return "D";
			case 5: return "Bm";
			case 6: return "A";
			case 7: return "F#m";
			case 8: return "E";
			case 9: return "C#m";
			case 10: return "B";
			case 11: return "G#m";
			case 12: return "F#";
			case 13: return "D#m";
			case 14: return "C#";
			case 15: return "A#m";
				// Con bemoles
			case 16: return "F";
			case 17: return "Dm";
			case 18: return "Bb";
			case 19: return "Gm";
			case 20: return "Eb";
			case 21: return "Cm";
			case 22: return "Ab";
			case 23: return "Fm";
			case 24: return "Db";
			case 25: return "Bbm";
			case 26: return "Gb";
			case 27: return "Ebm";
			case 28: return "Cb";
			case 29: return "Abm";

			default: return "";
		}
	}

	// Cambia una nota en la tabla por la entrada
	void setNota(int pos, string nota)
	{
		switch(pos){
		case 1: t1 = nota; break;
		case 2: t2 = nota; break;
		case 3: t3 = nota; break;
		case 4: t4 = nota; break;
		case 5: t5 = nota; break;
		case 6: t6 = nota; break;
		case 7: t7 = nota; break;
		case 8: t8 = nota; break;
		case 9: t9 = nota; break;
		case 10: t10 = nota; break;
		case 11: t11 = nota; break;
		case 0: t0 = nota; break;
		default: break;
		}
	}

	bool swapNota(int pos1, int pos2)
	{
		if(pos1 > 11 || pos1 < 0 || pos2 > 11 || pos2 < 0)
			return false;
		else
		{
			string tAux = getNota(pos2);
			setNota(pos2, getNota(pos1));
			setNota(pos1, tAux);
			return true;
		}			
	}

	//Funcion que te devuelve el candidato a ocupar la posicion dada con un accidente.
	int setNuevaNota(int nuevaPos)
	{
		bool candidato1 = false, candidato2 = false;
		int subNota = (nuevaPos-1)%ESCALA;
		int superNota = (nuevaPos+1)%ESCALA;

		//la anterior está libre sin modificar? (suponemos que no vamos ha hacer nunca doble sostenido)
		if(!getNota(subNota).empty() //Hay subnota para poder hacer #?
		&& !findPairInList(armadura, make_pair(subNota, (nuevaPos-2)%ESCALA)) //Esa subnota no esté ya con #? en la armadura
		&& !findPairInList(accidentes, make_pair(subNota, (nuevaPos-2)%ESCALA))) //Esa subnota no esté ya con #? en accidentes
		{

			if(!findPairInList(accidentes, make_pair(subNota, nuevaPos)))  //No podemos poner un sostenido sobre un bemol.
			{
				addAccidente(nuevaPos, subNota); //ponemos sostenido a la nota.
				return nuevaPos-1; //devolvemos la nota anterior para que le ponga un sostenido
			}
			else //Si se ha disminuido la nota anterior respecto a la nueva, entonces podemos poner un becuadro
			{
				//removeAccidente(make_pair((nuevaPos-1)%ESCALA, nuevaPos))
				candidato1 = true;
			}
		}
		//la siguiente está libre sin modificar? (suponemos que no vamos ha hacer nunca doble bemol)
		if(!getNota(superNota).empty()
		&& !findPairInList(armadura, make_pair(superNota, (nuevaPos+2)%ESCALA))
		&& !findPairInList(accidentes, make_pair(superNota, (nuevaPos+2)%ESCALA)))
		{
			if(!findPairInList(accidentes, make_pair(superNota, nuevaPos))) //La nota superior no viene de abajo
			{
				addAccidente(nuevaPos, superNota); //ponemos sostenido a la nota.
				return nuevaPos+1; //devolvemos la nota anterior para que le ponga un sostenido
			}
			else
			{	//Podemos hacer un becuadro
				candidato2 = true;
			}
		}

		//Vamos a usar becuadros:
		if(candidato1)
		{
			removeAccidente(subNota, nuevaPos);
			return 0;  //cero especial, significa que hemos usado un becuadro
		}
		else if(candidato2)
		{
			removeAccidente(superNota, nuevaPos);
			return 0;
		}

		return -1;  //No se ha conseguido nada
	}

	//Se trata de poner como cambian las posiciones dentro de la tabla. un sostenido es subir en uno una nota: (i+1, i)
	bool addAccidente(int nuevaPos, int antPos)
	{
		if(getNota(nuevaPos).empty() && !(getNota(antPos).empty()))
		{
			//setNota(nuevaPos, getNota(antPos)); //ponemos la nueva nota
			//setNota(antPos, "");				//liberamos su antiguo espacio
			swapNota(nuevaPos, antPos);
			accidentes.push_back(make_pair(nuevaPos, antPos));
			return true;
		}
		return false;
	}

	//se trata de quitar un accidente, quita todos los repetidos también
	bool removeAccidente(int nuevaPos, int antPos)
	{
		if(!getNota(nuevaPos).empty() && getNota(antPos).empty())
		{
 			//setNota(nuevaPos, getNota(antPos)); //ponemos la nueva nota
			//setNota(antPos, "");				//liberamos su antiguo espacio
			swapNota(antPos, nuevaPos);
			accidentes.remove(make_pair(nuevaPos, antPos)); //Suponemos no hay repetidos, porque si los hay, los elimina
			return true;
		}
		return false;
	}

	//Desacemos los cambios por los accidentes que hemos metido.
	//Esto se debe hacer cada vez que cambiamos de compás.
	void cleanAccidents()
	{
		if(!accidentes.empty())
		{
			list< pair<int,int> >::iterator it = accidentes.begin();
			while(it != accidentes.end())
			{
				swapNota(it->first, it->second);
				it++;
			}
			accidentes.clear();
		}
	}

	TablaEscala(Tonalidad m){
		//La escala normal sin nada en la armadura:
		t1 = "C";  //DO
		t2 = "";
		t3 = "D";  //RE
		t4 = "";
		t5 = "E";  //MI
		t6 = "F";  //FA
		t7 = "";
		t8 = "G";  //SOL
		t9 = "";
		t10 = "A"; //LA
		t11 = "";
		t0 = "B"; //SI

		armadura.clear();

		switch(m){

		//Las tonalidades con sostenidos:
		case 15:
		case 14:
			t0 = "";
			t1 = "B"; //SI#
			armadura.push_back(make_pair(1, 0));
		case 13:
		case 12:
			t5 = "";
			t6 = "E"; //MI#
			armadura.push_back(make_pair(6, 5));
		case 11:
		case 10:
			t10 = "";
			t11 = "A"; //LA#
			armadura.push_back(make_pair(11, 10));
		case 9:
		case 8:
			t3 = "";
			t4 = "D";  //RE#
			armadura.push_back(make_pair(4, 5));
		case 7:
		case 6:
			t8 = "";
			t9 = "G";  //SOL#
			armadura.push_back(make_pair(9, 8));
		case 5:
		case 4:
			t1 = "";
			t2 = "C";  //DO#
			armadura.push_back(make_pair(2, 1));
		case 3:
		case 2:
			t6 = "";
			t7 = "F";  //FA#
			armadura.push_back(make_pair(7, 6));
			break;

		//Las tonalidades con bemoles:
		case 29:
		case 28:
			t6 = "";
			t5 = "F";  //FAb
			armadura.push_back(make_pair(5, 6));
		case 27:
		case 26:
			t1 = "";
			t0 = "C";  //DOb
			armadura.push_back(make_pair(0, 1));
		case 25:
		case 24:
			t8 = "";
			t7 = "G";  //SOLb
			armadura.push_back(make_pair(7, 8));
		case 23:
		case 22:
			t3 = "";
			t2 = "D"; //REb
			armadura.push_back(make_pair(2, 3));
		case 21:
		case 20:
			t10 = "";
			t9 = "A"; //LAb
			armadura.push_back(make_pair(9, 10));
		case 19:
		case 18:
			t5 = "";
			t4 = "E"; //MIb
			armadura.push_back(make_pair(4, 5));
		case 17:
		case 16:
			t0 = "";
			t11 = "B"; //SIb
			armadura.push_back(make_pair(11, 0));
			break;
		default:
			break; //No hay nada que hacer, tenemos o DOM o LAm
		}
	}

};

//Mierda Temporal
class Scriabin
{
	public:
		Scriabin()
		{
			scriabin.push_back(pair<string,int>("Rojo",DO_C));
			scriabin.push_back(pair<string,int>("Naranja",SOL_C));
			scriabin.push_back(pair<string,int>("Amarillo",RE_C));
			scriabin.push_back(pair<string,int>("Verde",LA_C));
			scriabin.push_back(pair<string,int>("Cian",MI_C));
			scriabin.push_back(pair<string,int>("Azul",SI_C));
			scriabin.push_back(pair<string,int>("AzulMarino",SOL_C - 1));
			scriabin.push_back(pair<string,int>("Purpura",RE_C - 1));
			scriabin.push_back(pair<string,int>("Violeta",LA_C - 1));
			scriabin.push_back(pair<string,int>("Morado",MI_C - 1));
			scriabin.push_back(pair<string,int>("Salmon",SI_C - 1));
			scriabin.push_back(pair<string,int>("Granate",FA_C));
		}

		~Scriabin(){};

		int getNota(string color)
		{
			list<pair<string,int>>::iterator it = scriabin.begin();
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
		list<pair<string,int>> scriabin;
};

#endif // MUSIC_ELEMS
