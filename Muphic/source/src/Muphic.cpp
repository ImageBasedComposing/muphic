#include "Muphic.h"

Muphic::Muphic()
{
    //ctor
}

Muphic::~Muphic()
{
    //dtor
}

int main( int argc, const char* argv[] )
{
    /* Toma de parámetros de entrada */

    std::string usrConfPath = "";
    std::string picPath = "";
    std::string phicExe = "Phic.exe";
    std::string muExe = "Mu.exe";

    /* Ejecutar phic */

    cout << "Comienza el analisis de la imagen" << endl;

    std::string picExeFile = phicExe + " " + usrConfPath + " " + picPath;
    system(picExeFile.c_str());
    std::string analyzedPicPath = "";

    cout << "Finaliza el analisis de la imagen" << endl;
    system("PAUSE");


    /* Ejecutar mu*/

    cout << "Comienza la composicion" << endl;

    std::string muExeFile = phicExe + " " + usrConfPath + " " + analyzedPicPath;
    system(muExeFile.c_str());

    cout << "Finaliza la composicion" << endl;
    system("PAUSE");


	return 0;
}
