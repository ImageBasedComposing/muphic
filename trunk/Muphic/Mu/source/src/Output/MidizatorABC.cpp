#include "Outputs/MidizatorABC.h"
#include "aux_functions.h"
#include "launcher.h"

#include <sstream>
#ifdef __LINUX
    #include <unistd.h>
    #include <sys/wait.h>
#endif

MidizatorABC::MidizatorABC()
{
	//ctor
}

MidizatorABC::~MidizatorABC()
{
    //dtor
}

string MidizatorABC::toMidi(std::string music)
{
	Launcher* l = new Launcher();
	string args[] = { music};

	l->launch(1, Launcher::ABC2MIDI, args);

    std::string output = changeExtension(music, "mid");

	return output;
}

string MidizatorABC::toMidi(Music* music)
{

	string fName = music->getName();
	string fileName = fName + ".abc";
	char *const abcFile = const_cast<char*>(fileName.c_str());

	ofstream* f = new ofstream();
	f->open(abcFile);

	// Escribimos en el fichero
	// Cabecera
	*f << "X:23\n";
	*f << "T:" + fName << endl;
	*f << "M:" << "C" << endl;
	*f << "L:" << music->getBaseLenght().first << "/" << music->getBaseLenght().second << endl;
	*f << "%            End of header, start of tune body:" << endl;

	// Conseguimos las voces
	Voz* v;
	Segmento* s;
	Simbolo* simb;


	// DURACION DEL COMPAS: negra * (first * negra / second)
	int duracionCompas, duracionsimboriginal, tmpduracion, tmpnota1, tmpnota2, numCompasesLinea = 0;
	int lastMetricUpper = 0, lastMetricLower = 0, lastTempo = 0;
	bool changedMetric = false;

	for( int i = 0; i < music->getVoces()->size(); i++)
	{
		v = music->getVoces()->getAt(i);
		tablaTransf = new TableTransform(v->getTonalidad());
		*f << "V:" << i << endl;
		*f << printInstrumento(v->getInstrumento()) << endl;
		*f << "K:" << tablaTransf->transformTonalidad(v->getTonalidad()); //<< endl; Ya se hace cuando se pone metrica por primera vez
		lastTempo = 0;  //Por cada voz que se escriba el tempo y metrica.
		lastMetricUpper = 0;
		lastMetricLower = 0;

		tmpduracion = 0;

		bool compasCompleto = false;
		// Trabajamos con cada segmento
		for( int j = 0; j < v->getSegmentos()->size(); j++)
		{
			s = v->getSegmentos()->getAt(j);

			// en cada cambio de métrica se cambia la longitud de un compás
			if(lastMetricUpper != s->getMetrica().upper || lastMetricLower != s->getMetrica().lower)
			{
				//Si estamos a principio de un nuevo compas
				if(tmpduracion == 0)
					*f << endl;
				else //estamos en medio de un compas, luego lo introducimos como [M: x/y]
					*f << " [";
				*f << "M:" << s->getMetrica().upper << "/" << s->getMetrica().lower;
				lastMetricUpper = s->getMetrica().upper;
				lastMetricLower = s->getMetrica().lower;
				duracionCompas = s->getMetrica().upper * (QUARTERNOTE * 4 / s->getMetrica().lower); //Cambiamos la duracion de compas
				changedMetric = true;
				if(tmpduracion == 0)
					*f << endl;
				else
					*f << "]";
			}

			if(lastTempo != s->getTempo())
			{
				// No ha hecho salto de linea Metrica y además estamos al principio de compas
				if(!changedMetric && tmpduracion == 0)
					*f << endl;
				else if(tmpduracion != 0)
					*f << " [";
				*f << "Q:" << s->getTempo();
				lastTempo = s->getTempo();
				changedMetric = false;
				if(tmpduracion == 0)
					*f << endl;
				else
					*f << "]";
			}

			
			// Trabajamos con cada símbolo
			for( int k = 0; k < s->getSimbolos()->size(); k++)
			{
				simb = s->getSimbolos()->getAt(k);

				duracionsimboriginal = simb->getDuracion();
				tmpduracion = tmpduracion + duracionsimboriginal; //tmpduracion lo que ocupa en nuevo sonido + los anteriores en un compas


				// encajar la nota a la métrica
				do
				{
					// no cabe la nota en el compás
					if (tmpduracion > duracionCompas)
					{
						compasCompleto = true;
						// imprimir lo que quepa de la nota
						tmpnota1 = duracionCompas - (tmpduracion - simb->getDuracion());
						tmpnota2 = simb->getDuracion() - tmpnota1;

						if (tmpnota1 == 0) //En el caso que no quepa nada de la nota, se cierra compás y nos vamos al nuevo
							*f << " |";
						else
						{
							simb->setDuracion(tmpnota1);
							*f << imprimeNota(simb, music->getBaseLenght());

							// imprimir ligadura, fin de compás
							// lo que queda de la nota se escribe en la siguiente iteración
							if (Nota* n = dynamic_cast<Nota *> (simb))
							{
								// si es silencio, no se liga
								if (n->getTono() != 0)
									*f << "-";
							}
							// si es acorde, se liga (¿?¿?)
							else
								*f << "-";
							
							// fin de compás
							*f << "|";

							if (numCompasesLinea > 5)
							{
								*f << endl; //Salto de linea para no crear una linea enorme
								numCompasesLinea = 0;
							}
							numCompasesLinea++;
						}
						tablaTransf->cleanAccidents();

						// actualizar duracion de compas
						tmpduracion = tmpnota2;

						// queda símbolo por escribir
						simb->setDuracion(tmpnota2);
					}
					// cabe la nota en el compás
					// se acaba el compás?
					else
					{
						// imprimir nota

						*f << imprimeNota(simb, music->getBaseLenght());
						compasCompleto = false;
						if (tmpduracion == duracionCompas)
						{
							// imprimir barra de compas
							*f << " |";
							compasCompleto = true;
							if (numCompasesLinea > 5 && k+1 < s->getSimbolos()->size())
							{//cuidado de no meter eol al final de la obra, que luego hay que poner "]"
								*f << endl; //Salto de linea para no crear una linea enorme
								numCompasesLinea = 0;
							}
							numCompasesLinea++;
							tablaTransf->cleanAccidents();

							// reiniciar duracion de compas
							tmpduracion = 0;
						}

						// el símbolo se ha agotado
						simb->setDuracion(0);
					}
				}
				// si queda símbolo por escribir, seguimos
				while (simb->getDuracion());

				// (si, actualizamos sobre el símbolo porque somos unas guarras, pero luego lo limpiamos)
				simb->setDuracion(duracionsimboriginal);

			} // Simbolos
		} // Segmentos
		if(compasCompleto)
			*f << "|" << endl; //termina la obra para esta voz
		else
			*f << "||" << endl; //termina la obra para esta voz
	} //VocesS
	f->close();


	Launcher* l = new Launcher();
	string args[] = {fName + ".abc"};

	l->launch(1, Launcher::ABC2MIDI, args);

    return fName + ".mid";
}


string MidizatorABC::imprimeNota(Simbolo* simbolo, pair<int,int> duracionBase)
{
	// Trabajamos con notas
	if (Nota* n = dynamic_cast<Nota *> (simbolo))
	{
		n = (Nota*) simbolo;

		return transformNota(n, duracionBase);
	} // Nota
	// Trabajamos con acordes
	else if (Acorde* a = dynamic_cast<Acorde *> (simbolo))
	{
		a = (Acorde*) simbolo;

		return transformAcorde(a, duracionBase);
	} // Acorde
	else
	{
		// LANZAR ERROR DE SÍMBOLO!!
		return "";
	}
}

string MidizatorABC::transformNota(Nota* n, pair<int,int> duracionBase)
{  /*
	// salida debug
	std::stringstream ostr;
	ostr << "a" << n->getDuracion() << " ";
	return ostr.str();

	//return "a";
	*/
	string prefijo = ""; // Si tiene algo delante la nota (ej: ^ sostenido, ...)
	int tono = n->getTono(); //el tono que nos dan, si 0 es silencio
	int tonoModif; //la nota que cambiamos para sacar el sonido/tono que nos piden
	string sufijo = ""; // Los sufijos, vease la escala y la duracion
	string nota = ""; // La propia nota.

	//Primero consultamos la tabla y ponemos accidentes si los necesita:
	if(tono > 0)
		nota = tablaTransf->getNota(tono%ESCALA);
	else
		nota = "z"; //Tenemos un silencio.
	if(nota.empty()) //si no hemos recuperado una nota es que nos toca modificar alguna.
	{				 //No hay nota que sea como la que tenemos, pasamos a añadir accidente
		tonoModif = tablaTransf->setNuevaNota(tono%ESCALA);
		if( tonoModif != -1)
		{
			if( (tonoModif+1) == tono%ESCALA) //Le hemos puesto un sostenido
				prefijo += "^";
			else if ( tonoModif == 0)
				prefijo += "=";
			else
				prefijo += "_";

			//Ahora ya nos devuelve el char de la nota
			nota = tablaTransf->getNota(tono%ESCALA);
		}
		else
		{
			//LANZAR ERROR DE TRANSFORMACION!!
		}
	}

	//Ahora vamos a ver en que escala está:
	int numEscala = (tono-1)/ESCALA;
	if(tono > 0)
		switch(numEscala){
			case 0: sufijo += ",";
			case 1: sufijo += ",";
			case 2: sufijo += ","; //Se van acumulando las ','
			case 3:
				break; //Hasta aqui la escala central
			case 6: sufijo += "'";
			case 5: sufijo += "'";
			case 4: nota = *(nota.c_str()) + 32;  //Convertimos a Minusculas, imprescindible que nota sea un string de una sola letra
				break;
			default: break; //La dejamos en la escala central, Posible error out of range
		}
	else //Es un silencio, no hace falta añadirle escalas
		sufijo += "";

	// Y por ultimo la duración de la nota.
	int duracion = n->getDuracion();
	duracion = (duracion * duracionBase.second) / 64; //Ej: 16(negra) * 8/64 (nuestra L:1/8) = 2.
												//64 porque nuestra duración minima es semifusa, no contemplamos más abajo
	stringstream convertString; // stringstream used for the conversion

	convertString << duracion;//add the value of Number to the characters in the stream

	sufijo += convertString.str();

	//Componemos la nota:

	nota = " " + prefijo + nota + sufijo;

	return nota;
}

string MidizatorABC::transformAcorde(Acorde* a, pair<int,int> duracionBase)
{
	return "a";
}

string MidizatorABC::printInstrumento(Instrumento i)
{
	std::ostringstream out;
	out << "%%MIDI";

	if (i < 128)
	{
		out << " program " << i;
	}
	else if (i == 128)
	{
		out << " channel 10";
	}

	return out.str();
}