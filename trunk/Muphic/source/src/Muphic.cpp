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

int main( int argc, const char* argv[] )
{
    /* Toma de parámetros de entrada */
	
	if (argc < 2)
	{
		cout << "Too few arguments in function call";
		// showUsage();
		return 1;
	}

    std::string usrConfPath = argv[0];
    std::string picPath = argv[1];
    std::string phicExe = "Phic.exe";
    std::string muExe = "Mu.exe";

    /* Ejecutar phic */
	
    cout << "Comienza el analisis de la imagen" << endl;

    std::string picExeFile = phicExe + " " + usrConfPath + " " + picPath;
    system(picExeFile.c_str());
	
    cout << "Finaliza el analisis de la imagen" << endl;
    system("PAUSE");

    /* Ejecutar mu*/
	
    cout << "Comienza la composicion" << endl;

	std::string analyzedPicPath = changeExtension(picPath, "rec");

    std::string muExeFile = phicExe + " " + usrConfPath + " " + analyzedPicPath;
    system(muExeFile.c_str());

    cout << "Finaliza la composicion" << endl;
    system("PAUSE");

	return 0;
}
