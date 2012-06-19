#include "Mu.h"

#include "Compositors/ComposerTimothy.h"
#include "Compositors/ComposerTimothy2.h"
#include "Compositors/ComposerFigSilence.h"
#include "Compositors/ComposerFigMelody.h"
#include "Compositors/ComposerFigMelody2.h"
#include "Compositors/ComposerFigBass2.h"
#include "Compositors/ComposerFigRitmo.h"
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
		case 0:
			cs = new NewtonColor(); break;
		case 1:
			cs = new BertrandCastelColor(); break;
		case 2:	
			cs = new ScriabinColor(); break;
		case 3:
			cs = new GFieldColor(); break;
		case 4:
			cs = new JamesonColor(); break;
		case 5:
			cs = new SeemanColor(); break;
		case 6:
			cs = new WallaceRimingtonColor(); break;
		case 7:
			cs = new BishopColor(); break;
		case 8:
			cs = new HemlholtzColor(); break;
		case 9:
			cs = new KleinColor(); break;
		case 10:
			cs = new AeppliColor(); break;
		default : 
			cs = new ScriabinColor();
	}

	//All the compositors:
	vector<int> instruments;

	//1º Voice
	ComposerVoice* compVoice1;
	switch(usrConf->getMuCompVoice1()){
		case -1:
			compVoice1 = new ComposerFigSilence(cs); break;
		case 0:	
			compVoice1 = new ComposerFigMelody(cs); break;
		case 1:	
			compVoice1 = new ComposerFigMelody2(cs); break;
		case 2:
			compVoice1 = new ComposerFigBass2(cs); break;
		default : 
			compVoice1 = new ComposerFigMelody2(cs);
	}
	instruments.clear();
	instruments.push_back(usrConf->getMuInstrVoice1());
	compVoice1->setInstruments(instruments);

	//2º Voice
	ComposerVoice* compVoice2;
	switch(usrConf->getMuCompVoice2()){
		case -1:
			compVoice2 = new ComposerFigSilence(cs); break;
		case 0:	
			compVoice2 = new ComposerFigMelody2(cs); break;
		default : 
			compVoice2 = new ComposerFigMelody2(cs);
	}
	instruments.clear();
	instruments.push_back(usrConf->getMuInstrVoice2());
	compVoice2->setInstruments(instruments);

	//3º Voice
	ComposerVoice* compVoice3;
	switch(usrConf->getMuCompVoice3()){
		case -1:
			compVoice3 = new ComposerFigSilence(cs); break;
		case 0:	
			compVoice3 = new ComposerFigBass2(cs); break;
		case 1:
			compVoice3 = new ComposerFigMelody(cs); break;
		case 2: 
			compVoice3 = new ComposerFigMelody2(cs); break;
		default : 
			compVoice3 = new ComposerFigBass2(cs);
	}
	instruments.clear();
	instruments.push_back(usrConf->getMuInstrVoice3());
	compVoice3->setInstruments(instruments);

	//4º Voice
	ComposerVoice* compVoice4;
	switch(usrConf->getMuCompVoice4()){
		case -1:
			compVoice4 = new ComposerFigSilence(cs); break;
		case 0:	
			compVoice4 = new ComposerFigRitmo(cs); break;
		case 1:	
			compVoice4 = new ComposerFigRitmo2(cs); break;
		default : 
			compVoice4 = new ComposerFigRitmo2(cs);
	}
	instruments.clear();
	switch(usrConf->getMuInstrVoice4())
	{
		case 128:
			instruments.push_back(17);
			instruments.push_back(36); break;
		default:
			instruments.push_back(17);
			instruments.push_back(36);
	}
	compVoice4->setInstruments(instruments);


	//The compositor that is going to mix everything
	Composer* compMix;
	switch(usrConf->getMuCompMix()){
		case 0:	
			compMix = new ComposerTimothy(compVoice1,compVoice2,compVoice3,compVoice4); break;
		case 1:	
			compMix = new ComposerTimothy2(compVoice1,compVoice2,compVoice3,compVoice4); break;
		default : 
			compMix = new ComposerTimothy2(compVoice1,compVoice2,compVoice3,compVoice4);
	}

	compMix->setTempo(usrConf->getMuTempo());
	
	
	string midiPath = usrConf->getMuOutputFile();
	if(midiPath.compare("") == 0)
		compMix->setTmpMIDIPath(analysedPic);
	else
		compMix->setTmpMIDIPath(midiPath);


	/* Componemos la música y la pasamos a midi*/
	compMix->compose(analysedPic, usrConfPath);


	/* Ahora vamos a pasarla a wav */
	Launcher* l = new Launcher();
	string args[] = {compMix->getTmpMIDIPath()+".mid", "-R 700", "-OwU", "-o", compMix->getTmpMIDIPath()+".wav"};
	cout << endl << "Making wav output..." << endl;
	l->launch(5, Launcher::TIMIDITY, args);

	delete l;

	l = new Launcher();
	string args2[] = {compMix->getTmpMIDIPath()+".abc", "-X", "-O", compMix->getTmpMIDIPath()+".xhtml"};
	cout << endl << "Making pdf output..." << endl;
	l->launch(4, Launcher::ABC2PS, args2);


	delete compMix;
	delete cs;

	if(usrConf->getMuDebug()){
		system("PAUSE");
	}

	delete usrConf;

	return 0;
}
