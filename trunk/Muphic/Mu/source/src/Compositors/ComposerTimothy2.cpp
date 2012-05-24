#include "Compositors/ComposerTimothy2.h"

ComposerTimothy2::ComposerTimothy2(ComposerVoice* fm, ComposerVoice* fm2, ComposerVoice* fb, ComposerVoice* fr) :
Composer(fm, fm2, fb, fr)
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
	//PriorityPattern* p = new PriorityPattern();

	// Auxiliary list to get the main figures
	std::list<FigureMusic*> padres;

	for(int i = 0; i < fgs->sizePadre(); i++)
		padres.push_back((FigureMusic*)fgs->getPadreAt(i));

	// Pattern made from the list we retrieved
	//std::list<FigureMusic*> fPatronizada = p->createPatternFig(padres);

	// We calculate the duration we must assign to each figure
	//std::list< std::pair<FigureMusic*, int> > aux = calcularDuracion(fPatronizada);

	// We create the scale by which we pretend to work, set by default to DOM
	MajorScale scale;
	ScriabinColor sc;
	TableScale* tbScaleBase = new TableScale(scale.getScaleSteps(), DO);
	TableScale* tbScale = new TableScale(scale.getScaleSteps(), sc.getNota(padres.front()->getRGB(), tbScaleBase));

	// We create the composers we will use to make the melody and rithm
	fm->setTableScale(tbScale);
	fm2->setTableScale(tbScale);
	fb->setTableScale(tbScale);
	fr->setTableScale(tbScale);

	// We create the segments where we will put the different notes from the melody
	Segmentos* segs1 = new Segmentos();
	Segmentos* segs2 = new Segmentos();
	Segmentos* segs3 = new Segmentos();
	Segmentos* segs4 = new Segmentos();
	Segmento* seg1, * seg2, * seg3, * seg4;
	FigureMusic* child;
	this->pic;

	for(std::list< FigureMusic* >::iterator it = padres.begin(); it != padres.end(); it++)
	{
		seg1 = new Segmento();
		
		fm->compMelodyFig((*it), seg1, /*fake-int*/128); 

		seg3 = new Segmento();
		fb->compBassFig((*it),seg3,seg1->getDuration());

		seg4 = new Segmento();
		fr->compRythmFig((*it),seg4,seg1->getDuration());

		for(int i = 0; i < (*it)->sizeHijos(); i++)
		{
			child = (FigureMusic*)(*it)->getHijoAt(i);
			seg2 = new Segmento();
			if( isLittleFig(child, (*it)) )
				fm2->decMelodyFig(child, seg1, seg2, seg1->getDuration());
			/*else //isMediumFig
				seg2 = fm->interMelodyFig(child, seg);*/
			segs1->pushBack(seg1);
			segs2->pushBack(seg2);
			segs3->pushBack(seg3);
			segs4->pushBack(seg4);
		}

		if((*it)->sizeHijos() == 0)
		{
			seg2 = emptyMelody(seg1);
			segs2->pushBack(seg2);
			segs1->pushBack(seg1);
			segs3->pushBack(seg3);
			segs4->pushBack(seg4);
		}


	}

	delete tbScaleBase;
	delete tbScale;

	// We create the voices we will use in this song and we assign them the segments we created
	Voz* v1 = new Voz();
	v1->setSegmentos(segs1);
	v1->setTonalidad(DOM);
	v1->setInstrumento(fm->getInstrument());

	Voz* v2 = new Voz();
	v2->setSegmentos(segs2);
	v2->setTonalidad(DOM);
	v2->setInstrumento(fm2->getInstrument());

	Voz* v3 = new Voz();
	v3->setSegmentos(segs3);
	v3->setTonalidad(DOM);
	v3->setInstrumento(fb->getInstrument());

	Voz* v4 = new Voz();
	v4->setSegmentos(segs4);
	v4->setTonalidad(DOM);
	v4->setInstrumento(DRUMS);


	Voces* vs = new Voces();

	vs->pushBack(v1);
	vs->pushBack(v2);
	vs->pushBack(v3);
	vs->pushBack(v4);

	// We set the parameters in music, and also we asign the voices previously created to this music
	Music* m = new Music();
	m->setComposer("Timothy2");
	m->setBaseLenght(std::make_pair(1,WHOLE));
	m->setName(getTmpMIDIPath());
	m->setVoces(vs);

	// We assign the element that will create the music from our structures
	//m->setMidizator(new MidizatorWAV());

	//m->toMidi();

	m->setMidizator(new MidizatorABC());
	cout << "Composition done!" << endl;
	cout << endl << "Making midi output..." << endl;
	std::string out = m->toMidi(); 

	// We make the music using the midizator previously selected
	return out;
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

//Crea un segmento que sea de la misma duración que el dado pero en silencio.
Segmento* ComposerTimothy2::emptyMelody(Segmento* seg)
{
	int dur = 0;
	Segmento* out = new Segmento();
	for(int i = 0; i < seg->getSimbolos()->size(); i++)
		dur = dur + seg->getAt(i)->getDuracion();
	while(dur > WHOLE)
	{
		out->pushBack(new Nota(WHOLE, 0));
		dur = dur - WHOLE;
	}
	out->pushBack(new Nota(dur, 0));

	return out;

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
	tmpMIDIPath = m.substr(0,m.find_last_of("."));
	if(tmpMIDIPath.compare("") == 0)
		tmpMIDIPath = m;
}

