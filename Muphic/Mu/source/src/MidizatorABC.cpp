#include "MidizatorABC.h"
#include "aux_functions.h"

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
	ofstream* f = new ofstream();
	f->open(fName + ".abc");

	//Escribimos en el fichero
	*f << "X:1\n";
	*f << "T:" + fName + '\n';
	*f << "M:";
	*f << music->getTempo().upper;
	*f << '/';
	*f << music->getTempo().lower;
	*f << '\n';
	//*f << "K:" + music->getClave();
	
	f->close();

	string converter = "abc2midi.exe";

	std::string picExeFile = converter + " " + fName + ".abc";
    system(picExeFile.c_str());

	return fName + ".mid"; 
}

string MidizatorABC::toMidi(std::string music, std::string converter)
{ 
	if (converter == "")
		converter = "abc2midi.exe";

	std::string picExeFile = converter + " " + music;
    system(picExeFile.c_str());

	std::string output = changeExtension(music, "mid");

	return output;
}