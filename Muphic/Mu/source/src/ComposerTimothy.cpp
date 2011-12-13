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
	Figuras* fgs = new Figuras();
	fgs->cargar(pic);

	//PatternGen<Figura*>* pg = new PatternGen<Figura*>();
	PriorityPattern* p = new PriorityPattern();
	
	std::list<Figura*> padres;

	for(int i = 0; i < fgs->sizePadre(); i++)
		padres.push_back(fgs->getPadreAt(i));

	std::list<Figura*> fPatronizada = p->createPatternFig(padres);

	std::list< std::pair<Figura*, int> > aux = calcularDuracion(fPatronizada);

	PentatonicMajScale scale;
	TableScale* tbScale = new TableScale(scale.getScaleSteps(), DO);

	ComposerFigMelody* fm = new ComposerFigMelody(tbScale);
	ComposerFigRitmo* fr = new ComposerFigRitmo();
	Segmentos* segs1 = new Segmentos();
	Segmentos* segs2 = new Segmentos();
	Segmento* seg;
	// We make the calls to the different composers
	for(std::list< std::pair<Figura*, int> >::iterator it = aux.begin(); it != aux.end(); it++)
	{
		seg = new Segmento();
		fm->compMelodyFig((*it).first, seg, (*it).second);
		segs1->pushBack(seg);

		seg = new Segmento();
		fr->compRythmFig((*it).first, seg, (*it).second);
		segs2->pushBack(seg);
	}

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

	Music* m = new Music();
	m->setComposer("Timothy");
	m->setBaseLenght(std::make_pair(1,WHOLE));
	m->setName("MelodyTimothy");
	m->setVoces(vs);
	m->setMidizator(new MidizatorABC());

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
	std::list< std::pair<Figura*, int> > sol;

	for(std::list<Figura*>::iterator it = f.begin(); it != f.end(); it++)
		sol.push_back(std::make_pair((*it),ceil(DURACION*(*it)->getVistosidad())));

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

