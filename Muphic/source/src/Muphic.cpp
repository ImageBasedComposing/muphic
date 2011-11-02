#include "Muphic.h"

Muphic::Muphic()
{
    //ctor
}

Muphic::~Muphic()
{
    //dtor
}

void showUsage()
{
	cout << "Muphic.exe userConfPath imagePath" << endl;
}

int main( int argc, const char* argv[] )
{
    /* Toma de parámetros de entrada */

	if (argc < 3)
	{
		cout << "Too few arguments in function call" << endl;
		showUsage();
		cin.get();
		cin.ignore(cin.rdbuf()->in_avail());

		return 1;
	}

    std::string usrConfPath = argv[1];
    std::string picPath = argv[2];

	std::string executionPath = getPath(argv[0]);
    std::string phicExe = executionPath + "Phic.exe";
    std::string muExe = executionPath + "Mu.exe";

    /* Ejecutar phic */

    cout << "Image analysis beginning" << endl << endl;

    std::string picExeFile = phicExe + " " + usrConfPath + " " + picPath;
    system(picExeFile.c_str());
	
    cout << endl << "Image analysis completed" << endl;
	cin.get();
	cin.ignore(cin.rdbuf()->in_avail());

    /* Ejecutar mu*/

    cout << "Image-based composing beginning" << endl << endl;

	std::string analyzedPicPath = changeExtension(picPath, "");

    std::string muExeFile = muExe + " " + usrConfPath + " " + analyzedPicPath;
    system(muExeFile.c_str());

    cout << endl << "Image-based composing completed" << endl;
	cin.get();
	cin.ignore(cin.rdbuf()->in_avail());

	return 0;
}
