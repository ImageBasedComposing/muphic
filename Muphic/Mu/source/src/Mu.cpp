#include "Mu.h"
#include "ComposerDemo.h"
#include "ComposerMultiple.h"
#include "ComposerTimothy.h"
#include "Acorde.h"

Mu::Mu()
{
    //ctor
}

Mu::~Mu()
{
    //dtor
}

void showUsage()
{
	cout << "Mu.exe userConfPath analyzedImagePath" << endl;
}


int main( int argc, const char* argv[] )
{
	/* Toma de parámetros de entrada */
	/*
	if (argc < 3)
	{
		cout << "Too few arguments in function call" << endl;
		showUsage();
		cin.get();
		cin.ignore(cin.rdbuf()->in_avail());

		return 1;
	}*/

    std::string usrConfPath = "a";
    std::string analysedPic = "test1";

    /* Iniciar compositor y hacer que rule */

    UsrConf* usrConf = new UsrConf();

	/* do thingies with usrconf */


	// DEBUGGING TIME
	// Introducing a brand new composer!!
	// ~ * ~CoMp0zer d3M0!!~ * ~

	MidizatorWAV* mdztor = new MidizatorWAV();
	Music* m = new Music(mdztor);

	Composer* comp = new ComposerDemo( m );
	Composer* comp2 = new ComposerMultiple( m );
	Composer* compTimy = new ComposerTimothy();

    //comp->compose(analysedPic, usrConfPath);
	//comp2->compose(analysedPic, usrConfPath);

	compTimy->compose(analysedPic, usrConfPath);

	return 0;
}
