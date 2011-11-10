#include "MidizatorABC.h"
#include "aux_functions.h"

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

string MidizatorABC::toMidi(Music* music)
{
	string fName = music->getName();
	char *const abcFile = const_cast<char*>((fName + ".abc").c_str());

	ofstream* f = new ofstream();
	f->open(abcFile);

	// Escribimos en el fichero
	// Cabecera
	*f << "X:1\n";
	*f << "T:" + fName << endl;
	*f << "L:" << music->getBaseLenght().first << "/" << music->getBaseLenght().second << endl;

	// Conseguimos las voces
	Voz* v;
	Segmento* s;
	Simbolo* simb;
	Nota* n;
	Acorde* a;

	for( int i = 0; i < music->getVoces()->size(); i++)
	{
		v = music->getVoces()->getAt(i);

		*f << "V:" << i << endl;
		*f << "K:" << v->getClave() << endl;
		
		// Trabajamos con cada segmento
		for( int j = 0; j < v->getSegmentos()->size(); j++)
		{
			s = v->getSegmentos()->getAt(j);

			*f << "M:" << s->getMetrica().upper << "/" << s->getMetrica().lower << endl;
			
			// Trabajamos con cada símbolo
			for( int k = 0; k < s->getSimbolos()->size(); k++)
			{
				simb = s->getSimbolos()->getAt(k);

				*f << "Q:" << simb->getDuracion() << endl;

				// Trabajamos con notas
				if(typeid(simb) == typeid(Nota))
				{
					n = (Nota*) simb;
					
					*f << transformNota(n) << " ";
				} // Nota
				// Trabajamos con acordes
				else if(typeid(simb) == typeid(Acorde))
				{
					a = (Acorde*) simb;

					*f << transformAcorde(a) << " ";
				} // Acorde

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

string MidizatorABC::transformNota(Nota* n)
{
	return "";
}

string MidizatorABC::transformAcorde(Acorde* a)
{
	return "";
}