#include "Muphic.h"

Muphic::Muphic()
{
    //ctor
}

Muphic::~Muphic()
{
    //dtor
}

// works
std::string changeExtension(std::string picPath, std::string extension)
{
	int i = picPath.find_last_of('.');

	return picPath.substr(0, i) + '.' + extension;
}

std::string getPath(std::string exeFile)
{
	int i = exeFile.find_last_of("/\\");

	if (i > 0)
		return exeFile.substr(0, i);
	else
		return "";
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
		system("PAUSE");
		return 1;
	}

    std::string usrConfPath = argv[1];
    std::string picPath = argv[2];

	std::string executionPath = getPath(argv[0]);
    std::string phicExe = executionPath + "\\Phic.exe";
    std::string muExe = executionPath + "\\Mu.exe";

    /* Ejecutar phic */

    cout << "Comienza el analisis de la imagen" << endl << endl;

    std::string picExeFile = phicExe + " " + usrConfPath + " " + picPath;
    system(picExeFile.c_str());
	
    cout << endl << "Finaliza el analisis de la imagen" << endl;
	cin.get();
	cin.ignore(cin.rdbuf()->in_avail());

    /* Ejecutar mu*/

    cout << "Comienza la composicion" << endl << endl;

	std::string analyzedPicPath = changeExtension(picPath, "rec");

    std::string muExeFile = muExe + " " + usrConfPath + " " + analyzedPicPath;
    system(muExeFile.c_str());

    cout << endl << "Finaliza la composicion" << endl;
	cin.get();
	cin.ignore(cin.rdbuf()->in_avail());

	return 0;
}
