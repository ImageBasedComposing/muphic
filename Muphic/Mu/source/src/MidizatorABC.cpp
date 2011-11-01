#include "MidizatorABC.h"
#include <iostream>
MidizatorABC::MidizatorABC()
{
    //ctor
}

MidizatorABC::~MidizatorABC()
{
    //dtor
}

string MidizatorABC::toMidi(Music* music) { return NULL; }

string MidizatorABC::toMidi(std::string music, std::string converter)
{ 
	if (converter == "")
		converter = "abc2midi.exe";

	std::string picExeFile = converter + " " + music;
    system(picExeFile.c_str());

	std::string output = changeExtension(music, "mid");
	cout << output;
	cin.get();
	cin.ignore(cin.rdbuf()->in_avail());
	return output;
}

//-----Funciones Privadas-----//
std::string MidizatorABC::changeExtension(std::string picPath, std::string extension)
{
	int i = picPath.find_last_of('.');

	return picPath.substr(0, i) + '.' + extension;
}