#include "Mu.h"
#include "Compositors/ComposerDemo.h"
#include "Compositors/ComposerMultiple.h"
#include "Compositors/ComposerTimothy2.h"
#include "Compositors/ComposerFigMelody2.h"
#include "Compositors/ComposerFigBass2.h"
#include "Compositors/ComposerFigRitmo2.h"
#include "launcher.h"
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
	//Color system we use in the composition:
	ColorSystem* cs;
	switch(usrConf->getMuReconColors()){
		case 2:	
			cs = new Scriabin(); break;
		default : 
			cs = new Scriabin();
	}
	//All the compositors:
	ComposerVoice* compVoice1;
	switch(usrConf->getMuCompVoice1()){
		case 2:	
			compVoice1 = new ComposerFigMelody2(cs); break;
		default : 
			compVoice1 = new ComposerFigMelody2(cs);
	}
	ComposerVoice* compVoice2;
	switch(usrConf->getMuCompVoice2()){
		case 2:	
			compVoice2 = new ComposerFigMelody2(cs); break;
		default : 
			compVoice2 = new ComposerFigMelody2(cs);
	}
	ComposerVoice* compVoice3;
	switch(usrConf->getMuCompVoice3()){
		case 2:	
			compVoice3 = new ComposerFigBass2(cs); break;
		default : 
			compVoice3 = new ComposerFigBass2(cs);
	}
	ComposerVoice* compVoice4;
	switch(usrConf->getMuCompVoice4()){
		case 2:	
			compVoice4 = new ComposerFigRitmo2(cs); break;
		default : 
			compVoice4 = new ComposerFigRitmo2(cs);
	}

	//Now we assign the instruments
	//Se podría hacer mientras se crea el compositor (dentro del switch)
	vector<int> instruments;
	instruments.clear();
	instruments.push_back(PIZZICATO_STRINGS);
	compVoice1->setInstruments(instruments);
	instruments.clear();
	instruments.push_back(FLUTE);
	compVoice2->setInstruments(instruments);
	instruments.clear();
	instruments.push_back(ELECTRIC_BASS_PICK);
	compVoice3->setInstruments(instruments);
	instruments.clear();
	instruments.push_back(17);
	instruments.push_back(36);
	compVoice4->setInstruments(instruments);
	instruments.clear();

	//The compositor that is going to mix everything
	Composer* compMix;
	switch(usrConf->getMuCompMix()){
		case 2:	
			compMix = new ComposerTimothy2(compVoice1,compVoice2,compVoice3,compVoice4); break;
		default : 
			compMix = new ComposerTimothy2(compVoice1,compVoice2,compVoice3,compVoice4);
	}
	
	compMix->setTmpMIDIPath(analysedPic);
	compMix->compose(analysedPic, usrConfPath);

	Launcher* l = new Launcher();
	string args[] = {analysedPic+".mid", "-Ow", "-o", analysedPic+".wav"};

	l->launch(4, Launcher::TIMIDITY, args);

	delete l;
	delete compMix;
	delete compVoice1;
	delete compVoice2;
	delete compVoice3;
	delete compVoice4;
	delete cs;
	delete usrConf;

	return 0;
}
