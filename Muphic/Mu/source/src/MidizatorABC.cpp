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
	return NULL; 
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