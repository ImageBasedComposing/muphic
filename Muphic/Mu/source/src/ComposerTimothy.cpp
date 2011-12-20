#include "ComposerTimothy.h"

ComposerTimothy::ComposerTimothy()
{
    //ctor
}

ComposerTimothy::~ComposerTimothy()
{
    //dtor
}


string ComposerTimothy::compose() 
{ 
	// We read the figures from the XML
	Figuras* fgs = new Figuras();
	fgs->cargar(pic);

	// We create the pattern with whom we will compose in this composer
	//PatternGen<Figura*>* pg = new PatternGen<Figura*>();
	PriorityPattern* p = new PriorityPattern();
	
	// Auxiliary list to get the main figures
	std::list<Figura*> padres;

	for(int i = 0; i < fgs->sizePadre(); i++)
		padres.push_back(fgs->getPadreAt(i));

	// Pattern made from the list we retrieved
	std::list<Figura*> fPatronizada = p->createPatternFig(padres);

	// We calculate the duration we must assign to each figure
	std::list< std::pair<Figura*, int> > aux = calcularDuracion(fPatronizada);

	// We create the scale by which we pretend to work, set by default to DOM
	PentatonicMajScale scale;
	TableScale* tbScale = new TableScale(scale.getScaleSteps(), DO);

	// We create the composers we will use to make the melody and rithm
	ComposerFigMelody* fm = new ComposerFigMelody(tbScale);
	ComposerFigRitmo* fr = new ComposerFigRitmo();

	// We create the segments where we will put the different notes from the melody
	Segmentos* segs1 = new Segmentos();
	Segmentos* segs2 = new Segmentos();
	Segmento* seg;

	// We make the calls to the different composers with different figures sorted by vistosidad and with their timing assigned
	for(std::list< std::pair<Figura*, int> >::iterator it = aux.begin(); it != aux.end(); it++)
	{
		seg = new Segmento();
		fm->compMelodyFig((*it).first, seg, (*it).second);
		segs1->pushBack(seg);

		seg = new Segmento();
		fr->compRythmFig((*it).first, seg, (*it).second);
		segs2->pushBack(seg);
	}

	// We create the voices we will use in this song and we assign them the segments we created
	Voz* v1 = new Voz();
	v1->setSegmentos(segs1);
	// TO DO BY EGGTOR
	v1->setTonalidad(DOM);

	Voz* v2 = new Voz();
	v2->setSegmentos(segs2);
	v2->setTonalidad(DOM);
	v2->setInstrumento(WOODBLOCK);

	Voces* vs = new Voces();

	vs->pushBack(v1);
	vs->pushBack(v2);

	// We set the parameters in music, and also we asign the voices previously created to this music
	Music* m = new Music();
	m->setComposer("Timothy");
	m->setBaseLenght(std::make_pair(1,WHOLE));
	m->setName("MelodyTimothy");
	m->setVoces(vs);
	
	// We assign the element that will create the music from our structures
	m->setMidizator(new MidizatorABC());

	// We make the music using the midizator previously selected
	return m->toMidi(); 
}

string ComposerTimothy::compose(string picPath, string usrConfPath) 
{	
	setPic(picPath);
	setUsrConfFile(usrConfPath);

	return compose();
}

/*------Otras Funciones------*/
std::list< std::pair<Figura*, int> > ComposerTimothy::calcularDuracion(std::list<Figura*> f)
{
	//Normalizamos las duraciones:

	int durBase = EIGHTHNOTE; //Duración base (mínimo indivisible)
	int dur = DURACION / durBase; // Normalizamos la duración
	int durAsigned = 0; //Duración que asignamos a cada figura
	int durTotal = 0;
	std::list< std::pair<Figura*, int> > sol;

	for(std::list<Figura*>::iterator it = f.begin(); it != f.end(); it++)
	{
		durAsigned = floor(dur*(*it)->getVistosidad());
		sol.push_back(std::make_pair((*it),durAsigned*durBase));
		durTotal += durAsigned*durBase;
	}

	if(durTotal < DURACION)
		sol.back().second += DURACION-durTotal;

	return sol;
}

/*------Getters------*/
Conf* ComposerTimothy::getConfig()
{
	return config;
}

string ComposerTimothy::getUsrConfFile()
{
	return usrConfFile;
}

string ComposerTimothy::getPic()
{
	return pic;
}

string ComposerTimothy::getTmpMIDIPath()
{
	return tmpMIDIPath;
}

/*------Setters------*/
void ComposerTimothy::setConfig(string c)
{
	config->read(c);
}

void ComposerTimothy::setUsrConfFile(string f)
{
	usrConfFile = f;
}

void ComposerTimothy::setPic(string p)
{
	pic = p;
}

void ComposerTimothy::setTmpMIDIPath(string m)
{
	tmpMIDIPath = m;
}

