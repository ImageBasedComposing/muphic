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
	// you sure?
	//*f << "M:" << music->getBaseLenght().first << "/" << music->getBaseLenght().second << endl;

	// Conseguimos las voces
	Voz* v;
	Segmento* s;
	Simbolo* simb;
	Nota* n;
	Acorde* a;

	// DURACION DEL COMPAS: negra * (first * negra / second)
	float duracionCompas, duracionsimboriginal, tmpduracion, tmpnota1, tmpnota2;

	for( int i = 0; i < music->getVoces()->size(); i++)
	{
		v = music->getVoces()->getAt(i);
		
		*f << "V:" << i << endl;
		*f << "K:" << v->getClave() << endl;

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
						*f << imprimeNota(simb);

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

						*f << imprimeNota(simb);

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


string MidizatorABC::imprimeNota(Simbolo* simbolo)
{
	// Trabajamos con notas
	if (Nota* n = dynamic_cast<Nota *> (simbolo))
	{
		n = (Nota*) simbolo;
					
		return transformNota(n);
	} // Nota
	// Trabajamos con acordes
	else if (Acorde* a = dynamic_cast<Acorde *> (simbolo))
	{
		a = (Acorde*) simbolo;

		return transformAcorde(a);
	} // Acorde
}

string MidizatorABC::transformNota(Nota* n)
{
	// salida debug
	std::stringstream ostr;
	ostr << "a" << n->getDuracion() << " ";
	return ostr.str();

	//return "a";
}

string MidizatorABC::transformAcorde(Acorde* a)
{
	return "a";
}