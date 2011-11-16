#include "MidizatorABC.h"
#include "aux_functions.h"
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

string MidizatorABC::toMidi(std::string music, std::string converter)
{
	if (converter == "")
		converter = "abc2midi.exe";


    #ifdef __WINDOWS

		std::string picExeFile = converter + " " + music;
		system(picExeFile.c_str());

	#endif


    #ifdef __LINUX

        converter = "abc2midi_linux.exe";
        char *const params[] = {const_cast<char*>(converter.c_str()), const_cast<char*>(music.c_str()), NULL};


        pid_t pid;

        if ((pid = fork()) ==-1)
            cout << "fork error";
         else if (pid == 0) {
            execv(params[0], params);
            cout << "Return not expected. Must be an execv error.";
         }
         else
         {
            int status;
            while(wait(&status) > 0);
         }

     #endif

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
	*f << "X:1\n";
	*f << "T:" + fName << endl;
	*f << "L:" << music->getBaseLenght().first << "/" << music->getBaseLenght().second << endl;
	*f << "%            End of header, start of tune body:" << endl;

	// Conseguimos las voces
	Voz* v;
	Segmento* s;
	Simbolo* simb;
	Nota* n;
	Acorde* a;

	// DURACION DEL COMPAS: negra * (first * negra / second)
	int duracionCompas, duracionsimboriginal, tmpduracion, tmpnota1, tmpnota2;

	for( int i = 0; i < music->getVoces()->size(); i++)
	{
		v = music->getVoces()->getAt(i);
		tablaTransf = new TablaEscala(v->getTonalidad());
		*f << "V:" << i << endl;
		*f << "K:" << tablaTransf->transformTonalidad(v->getTonalidad()) << endl;
		

		tmpduracion = 0;

		// Trabajamos con cada segmento
		for( int j = 0; j < v->getSegmentos()->size(); j++)
		{
			s = v->getSegmentos()->getAt(j);

			// en cada cambio de métrica se cambia la longitud de un compás
			*f << "M:" << s->getMetrica().upper << "/" << s->getMetrica().lower << endl;
			duracionCompas = s->getMetrica().upper * (QUARTERNOTE * 4 / s->getMetrica().lower);

			// Trabajamos con cada símbolo
			for( int k = 0; k < s->getSimbolos()->size(); k++)
			{
				simb = s->getSimbolos()->getAt(k);

				// pero somos subnormales o que pasa? xD
				///*f << "Q:" << simb->getDuracion() << endl;

				tmpduracion = tmpduracion + simb->getDuracion();
				duracionsimboriginal = simb->getDuracion();

				// encajar la nota a la métrica
				do
				{
					// no cabe la nota en el compás
					if (tmpduracion > duracionCompas)
					{
						// imprimir lo que quepa de la nota
						tmpnota1 = duracionCompas - (tmpduracion - simb->getDuracion());
						tmpnota2 = simb->getDuracion() - tmpnota1;

						simb->setDuracion(tmpnota1);
						*f << imprimeNota(simb, music->getBaseLenght());

						// imprimir ligadura, fin de compás
						// lo que queda de la nota se escribe en la siguiente iteración
						*f << "-|";
					
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

						if (tmpduracion == duracionCompas)
						{
							// imprimir barra de compas
							*f << "|";

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
	} //VocesS

	f->close();

	string converter = "abc2midi.exe";

	#ifdef __WINDOWS

		std::string picExeFile = converter + " " + fName + ".abc";
		system(picExeFile.c_str());

	#endif


    #ifdef __LINUX

		converter = "abc2midi_linux.exe";

		char *const params[] = {const_cast<char*>(converter.c_str()), abcFile, NULL};

        pid_t pid;

        if ((pid = fork()) ==-1)
            cout << "fork error";
         else if (pid == 0) {
            execv(params[0], params);
            cout << "Return not expected. Must be an execv error.";
        }
         else
        {
            int status;
            while(wait(&status) > 0);
        }

    #endif

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
	string nota = "";
	int tono = n->getTono();
	int tonoModif;

	//Primero consultamos la tabla y ponemos accidentes si los necesita:
	string aux = tablaTransf->getNota(tono%ESCALA);
	if(aux.empty())
	{ //No hay nota que sea como la que tenemos, pasamos a añadir accidente
		tonoModif = tablaTransf->setNuevaNota(tono%ESCALA);
		if( tonoModif != -1)
		{
			if( (tonoModif+1)%ESCALA == tono) //Le hemos puesto un sostenido
				nota += "^";
			else if ( tonoModif == 0)
				nota += "=";
			else
				nota += "_";

			aux += tablaTransf->getNota(tono%ESCALA);
		}
		else
		{
			//LANZAR ERROR DE TRANSCRIPCION!!
		}		
	}

	//Ahora vamos a ver en que escala está:
	int numEscala = tono/ESCALA;
	switch(numEscala){
		case 1: aux += ",";
		case 2: aux += ",";
		case 3: aux += ","; //Se van acumulando las ','
		case 4: 
			break; //Hasta aqui la escala central
		case 5: aux = aux.c_str() + 32;  //Convertimos a Minusculas
			break;
		case 6: aux = aux.c_str() + 32; aux += "'";
			break;
		case 7: aux = aux.c_str() + 32; aux += "''";
			break;
		default: break; //La dejamos en la escala central.
	}
	nota += aux;

	// Y por ultimo la duración de la nota.
	int duracion = n->getDuracion();
	duracion = duracion * (duracionBase.first/duracionBase.second); //Ej: 16(negra) * 1/8 (nuestra L:1/8) = 2.
	printf(aux.c_str(),"%d",duracion);
	nota += aux;

	return nota;
}

string MidizatorABC::transformAcorde(Acorde* a, pair<int,int> duracionBase)
{
	return "a";
}