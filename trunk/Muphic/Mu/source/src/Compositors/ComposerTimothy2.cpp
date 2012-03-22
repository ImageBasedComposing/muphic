#include "Compositors/ComposerTimothy2.h"

ComposerTimothy2::ComposerTimothy2()
{
    //ctor
}

ComposerTimothy2::~ComposerTimothy2()
{
    //dtor
}


string ComposerTimothy2::compose()
{
	// We read the figures from the XML
	FiguresMusic* fgs = new FiguresMusic();
	fgs->cargar(pic);

	// We calculate figure visibility

	fgs->calculateVisibility();

	DURACION = fgs->getTotalVertices()*EIGHTHNOTE;

	// We create the pattern with whom we will compose in this composer
	//PatternGen<Figura*>* pg = new PatternGen<Figura*>();
	PriorityPattern* p = new PriorityPattern();

	// Auxiliary list to get the main figures
	std::list<FigureMusic*> padres;

	for(int i = 0; i < fgs->sizePadre(); i++)
		padres.push_back((FigureMusic*)fgs->getPadreAt(i));

	// Pattern made from the list we retrieved
	std::list<FigureMusic*> fPatronizada = p->createPatternFig(padres);

	// We calculate the duration we must assign to each figure
	std::list< std::pair<FigureMusic*, int> > aux = calcularDuracion(fPatronizada);

	// We create the scale by which we pretend to work, set by default to DOM
	MajorScale scale;
	Scriabin sc;
	TableScale* tbScaleBase = new TableScale(scale.getScaleSteps(), DO);
	TableScale* tbScale = new TableScale(scale.getScaleSteps(), sc.getNota(padres.front()->getRGB(), tbScaleBase));

	// We create the composers we will use to make the melody and rithm
	ComposerFigMelody2* fm = new ComposerFigMelody2(tbScale);
	ComposerFigRitmo2* fr = new ComposerFigRitmo2();

	// We create the segments where we will put the different notes from the melody
	Segmentos* segs1 = new Segmentos();
	Segmentos* segs2 = new Segmentos();
	Segmento* seg1, * seg2;
	FigureMusic* child;

	for(std::list< FigureMusic* >::iterator it = padres.begin(); it != padres.end(); it++)
	{
		seg1 = new Segmento();
		
		fm->compMelodyFig((*it), seg1); 
		for(int i = 0; i < (*it)->sizeHijos(); i++)
		{
			child = (FigureMusic*)(*it)->getHijoAt(i);
			if( isLittleFig(child, (*it)) )
				seg2 = fm->decMelodyFig(child, seg1);
			/*else //isMediumFig
				seg2 = fm->interMelodyFig(child, seg);*/
			segs1->pushBack(seg1);
			segs2->pushBack(seg2);
		}

		if((*it)->sizeHijos() == 0)
		{
			seg2 = fm->emptyMelody(seg1);
			segs2->pushBack(seg2);
			segs1->pushBack(seg1);
		}
	}

	delete tbScaleBase;
	delete tbScale;

	// We make the calls to the different composers with different figures sorted by vistosidad and with their timing assigned
	/*for(std::list< std::pair<FigureMusic*, int> >::iterator it = aux.begin(); it != aux.end(); it++)
	{
		seg1 = new Segmento();
		fm->compMelodyFig((*it).first, seg1, (*it).second);
		segs1->pushBack(seg1);

		seg1 = new Segmento();
		fr->compRythmFig((*it).first, seg1, (*it).second);
		segs2->pushBack(seg1);
	}*/

	// We create the voices we will use in this song and we assign them the segments we created
	Voz* v1 = new Voz();
	v1->setSegmentos(segs1);
	// TO DO BY EGGTOR
	v1->setTonalidad(DOM);

	Voz* v2 = new Voz();
	v2->setSegmentos(segs2);
	v2->setTonalidad(DOM);
	//v2->setInstrumento(WOODBLOCK);

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
	m->setMidizator(new MidizatorWAV());

	m->toMidi();

	m->setMidizator(new MidizatorABC());

	// We make the music using the midizator previously selected
	return m->toMidi();
}

string ComposerTimothy2::compose(string picPath, string usrConfPath)
{
	setPic(picPath);
	setUsrConfFile(usrConfPath);

	return compose();
}

/*------Otras Funciones------*/
std::list< std::pair<FigureMusic*, int> > ComposerTimothy2::calcularDuracion(std::list<FigureMusic*> f)
{
	std::list< std::pair<FigureMusic*, int> > sol;

	//Normalizamos las duraciones:

	int durBase = EIGHTHNOTE; //Duración base (mínimo indivisible)
	int dur = DURACION / durBase; // Normalizamos la duración
	int durAsigned = 0; //Duración que asignamos a cada figura
	int durTotal = 0;
	//std::list< std::pair<FigureMusic*, int> > sol;

	for(std::list<FigureMusic*>::iterator it = f.begin(); it != f.end(); it++)
	{
		durAsigned = floor(dur*(*it)->getVistosidad());
		sol.push_back(std::make_pair((*it),durAsigned*durBase));
		durTotal += durAsigned*durBase;
	}

	if(durTotal < DURACION)
		sol.back().second += DURACION-durTotal;

	return sol;
}

bool ComposerTimothy2::isLittleFig(FigureMusic* child, FigureMusic* parent)
{
	return true;
}

/*------Getters------*/
Conf* ComposerTimothy2::getConfig()
{
	return config;
}

string ComposerTimothy2::getUsrConfFile()
{
	return usrConfFile;
}

string ComposerTimothy2::getPic()
{
	return pic;
}

string ComposerTimothy2::getTmpMIDIPath()
{
	return tmpMIDIPath;
}

/*------Setters------*/
void ComposerTimothy2::setConfig(string c)
{
	config->read(c);
}

void ComposerTimothy2::setUsrConfFile(string f)
{
	usrConfFile = f;
}

void ComposerTimothy2::setPic(string p)
{
	pic = p;
}

void ComposerTimothy2::setTmpMIDIPath(string m)
{
	tmpMIDIPath = m;
}

