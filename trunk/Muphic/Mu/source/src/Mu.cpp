#include "Mu.h"
#include "Compositors/ComposerDemo.h"
#include "Compositors/ComposerMultiple.h"
#include "Compositors/ComposerTimothy.h"
#include "Music/Acorde.h"

Mu::Mu()
{
    //ctor
}

Mu::~Mu()
{
    //dtor
	delete usrConf;
}

void showUsage()
{
	cout << "Mu.exe userConfPath analyzedImagePath" << endl;
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
    std::string analysedPic = argv[2];

    /* Iniciar compositor y hacer que rule */

    UsrConf* usrConf = new UsrConf();
	usrConf->readMu(usrConfPath);

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

	/*
	Figuras* f = new Figuras();
	f->cargar("test1");
	f->setParentSonStructure();*/

	return 0;
}
