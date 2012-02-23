#include "Muphic.h"
#include "launcher.h"
#include "UsrConf.h"

/*
#ifdef __LINUX
    #include <unistd.h>
    #include <sys/wait.h>
#endif*/

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

    /*std::string usrConfPath = "user_conf.xml";
    std::string picPath = "test1";*/

	std::string executionPath = getPath(argv[0]);

	UsrConf* usrConf = new UsrConf();
	usrConf->readMuphic(usrConfPath);

	Launcher* l;

	if (usrConf->getPhicActive())
	{
    /* Ejecutar phic */

        cout << "Image analysis beginning" << endl << endl;

		l = new Launcher();
		string argsPhic[] = {usrConfPath, picPath};
		l->launch(2, Launcher::PHIC, argsPhic);

        cout << endl << "Image analysis completed" << endl;
        /*cin.get();
        cin.ignore(cin.rdbuf()->in_avail());*/
	}

	if (usrConf->getMuActive())
	{
    /* Ejecutar mu*/

        cout << "Image-based composing beginning" << endl << endl;

        std::string analyzedPicPath = changeExtension(picPath, "");

		l = new Launcher();
		string argsMu[] = {usrConfPath, analyzedPicPath};
		l->launch(2, Launcher::MU, argsMu);

        cout << endl << "Image-based composing completed" << endl;
       /* cin.get();
        cin.ignore(cin.rdbuf()->in_avail());*/
	}

	return 0;
}
