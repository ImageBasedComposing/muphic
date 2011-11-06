#include "MidizatorABC.h"
#include "aux_functions.h"

#ifdef __LINUX
    #include <unistd.h>
    #include <sys/wait.h>
#endif

#include <process.h>

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

	//Escribimos en el fichero
	*f << "X:1\n";
	*f << "T:" + fName << endl;
	*f << "M:";
	*f << music->getTempo().upper;
	*f << '/';
	*f << music->getTempo().lower;
	*f << endl;
	//*f << "K:" + music->getClave();

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
