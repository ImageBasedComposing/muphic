#include "ComposerMelodia.h"

/*------Constructoras------*/
ComposerMelodia::ComposerMelodia()
{
	// ctor
}

ComposerMelodia::ComposerMelodia(Music* m, int numSegmentos)
{
	melodia = m;
	NUMSEGMENTOS = numSegmentos;
}

/*------Destructora------*/
ComposerMelodia::~ComposerMelodia()
{
}

/*------Funciones------*/
Music* ComposerMelodia::composeMusic()
{
	figuras = new FiguresMusic();
	figuras->cargar(pic);

	Voz* v1 = new Voz();
	Voces* vs = new Voces(melodia->getVoces());

	//Cosas de la voz
	v1->setInstrumento(DEFAULT_INSTRUMENT);

	//Calculamos la tonalidad
	v1->setTonalidad(DOM);

	//Cosas del segmento
	Segmento* seg1;// = new Segmento();
	Metrica m;//4/4

	// Cosas del compositor
	FigureMusic* f;
	Segmento* seg = new Segmento();
	list< pair<Segmento*,int> > segs;
	pair<Segmento*,int> par;

	/***********************************************************************/
	PentatonicMajScale scale;
	TableScale* tbScale = new TableScale(scale.getScaleSteps(), DO);
	ComposerFigMelody* compPrueba = new ComposerFigMelody(tbScale);
	/******************************************************************/

	// Recorro las figuras y calculo su melodía
	for(int i = 0; i < figuras->sizeFig(); i++)
	{
		seg1 = new Segmento();
		f = (FigureMusic*)figuras->getFigAt(i);
		seg1->setMetrica(m);
		seg1->setTempo(180);

		/***********************************************************************/
		compPrueba->compMelodyFig(f,seg1,HALFNOTE*2); //Un compas para cada figura, pero parece que no es lo correcto...
		/******************************************************************/
		/*
		// Para cada figura saco la nota de su pentatonica y calculo su segmento de melodía
		nPpal = new Nota(notaFigura(f));
		//calcularMelodiaFig(f,seg1,nPpal);*/
		par.second = f->getId();
		par.first = seg1;
		segs.push_back(par);
	}


	// debug shit
	for (int h = 0; h < 10; h ++)
	for(list< pair<Segmento*,int> >::iterator it = segs.begin(); it != segs.end(); it++)
	{
		v1->getSegmentos()->pushBack(it->first);
	}


	vs->pushBack(v1);
	
	melodia->setVoces(vs);
	melodia->setComposer("MelodyComposer");
	melodia->setName("Melodia");
	melodia->setBaseLenght(make_pair(1,32));

	return melodia;

	// end debug shit




	// Copiado de ritmos, sigue exactamente el mismo patron para mezclar los segmentos
	list< pair<Segmento*,int> >* segmentos;

	int numPadres = figuras->sizePadre();

	int areaTotal = 0;
	for(int n = 0; n < numPadres; n++)
		areaTotal += figuras->getPadreAt(n)->getArea();

	int segmentosPadre;

	PatternGen<Segmento*>* patternGen = new PatternGen<Segmento*>();
	list< pair<list<Segmento*>*,int> >* sol = new list< pair<list<Segmento*>*,int> >();
	list<Segmento*>* aux;

	for(int i = 0; i < numPadres; i++)
	{
		segmentos  = new list< pair<Segmento*,int> >();
		f = (FigureMusic*) figuras->getPadreAt(i);
		segmentosPadre = ((f->getArea()*NUMSEGMENTOS)/areaTotal);
		calcularPadres(f,segs,segmentosPadre, segmentos);

		// Patronizador ordena segmentos devueltos y me da 1 de los segmentos del programa y lo añado a la solución final
		segmentos = patternGen->getPattern(segmentos);

		aux = new list<Segmento*>();

		for (list< pair<Segmento*, int> >::iterator it = segmentos->begin(); it != segmentos->end(); it++)
			aux->push_back(it->first);

		sol->push_back(make_pair(aux,segmentosPadre));
	}

	list< pair<list<Segmento*>*,int> >* sol2 = new list< pair<list<Segmento*>*,int> >();

	//Patronizo el ritmo final
	PatternGen<list<Segmento*>*>* patternGen2 = new PatternGen<list<Segmento*>*>();
	sol2 = patternGen2->getPattern(sol);

	delete sol;

	Segmentos* s = new Segmentos();
	aux = new list<Segmento*>();

	for (list< pair<list<Segmento*>*, int> >::iterator it = sol2->begin(); it != sol2->end(); it++)
	{
		aux = it->first;
		for (list<Segmento*>::iterator it2 = aux->begin(); it2 != aux->end(); it2++)
			s->pushBack(*it2);
	}

	//Lo añado a la voz
	v1->setSegmentos(s);

	vs->pushBack(v1);

	melodia->setVoces(vs);
	melodia->setComposer("MelodyComposer");
	melodia->setName("Melodia");
	melodia->setBaseLenght(make_pair(1,16));

	return melodia;
}

string ComposerMelodia::compose()
{
	return composeMusic()->toMidi();
}

string ComposerMelodia::compose(string picPath, string usrConfPath)
{
	setPic(picPath);
	setUsrConfFile(usrConfPath);

	return compose();
}

/*------Funciones Privadas------*/
void ComposerMelodia::calcularMelodiaFig(FigureMusic* f, Segmento* seg, Nota* n)
{
	list< pair<double,double> > calc = f->polarize();
	Nota* nPpal = new Nota(n->getDuracion(),n->getTono());
	Nota* nAux;
	float longMedia = 0;
	Simbolos* ss = new Simbolos();

	// Calculo la media de las longitudes
	for(list< pair<double,double> >::iterator it = calc.begin(); it != calc.end(); it++)
	{
		longMedia += (float)it->second;
	}

	longMedia = longMedia / calc.size();


	// debug shit
	int* esc = new int[5];
	esc[0] = 2;
	esc[1] = 3;
	esc[2] = 2;
	esc[3] = 2;
	esc[4] = 3;
	for(list< pair<double,double> >::iterator it = calc.begin(); it != calc.end(); it++)
	{
		// Crea la nota con la duracion y el tono que le corresponden
		//nAux = new Nota(calcDur(longMedia,it->second),calcTono(it->first,nPpal));

		nPpal->setTono(nPpal->getTono() + calcularNota(it->first, esc));

		nAux = new Nota(calcDur(longMedia,it->second),nPpal->getTono());


		// La añade al segmento
		ss->pushBack(nAux);
	}

	seg->setSimbolos(ss);
}

int ComposerMelodia::calcTono(float angulo, Nota* nPpal)
{
	return DO_C;
}


// inicialmente escala es [+2,+3,+2,+2,+3]
int ComposerMelodia::calcularNota(double angulo, int* esc)
{
	int desp = 3 * (int)angulo / 180;

	// calcular el desplazamiento a realizar
	int i = 0;
	int suma = 0;
	while (i != desp)
	{
		if (desp > 0)
			suma += esc[i];
		else
			suma -= esc[5 - i];

		if (i < desp)	i++;
		else			i--;
	}

	// modificar la escala

	if (desp > 0)
		i = desp;
	else
		i += 5;

	int j = 0;
	int tmp1, tmp2;
	tmp1 = esc[4];
	while (i != 0)
	{
		while (j + 1 != 5)
		{			
			tmp2 = esc[j + 1];
			esc[j + 1] = esc[j];
			esc[j] = tmp1;
			tmp1 = tmp2;

			j++;
		}

		i--;
	}

	return suma;
}


int ComposerMelodia::calcDur(double longMedia, double longitud)
{
	double durAprox = ( QUARTERNOTE * longitud ) / longMedia;
	double aux = FLT_MAX;
	int sol;

	float notas[7] = {1,2,4,8,16,32,64};

	for(int i = 0; i < 7; i++)
	{
		if(abs(notas[i] - durAprox) < aux)
		{
			aux = abs(notas[i] - durAprox);
			sol = i;
		}
	}

	return (int) notas[sol];
}

int ComposerMelodia::notaFigura(FigureMusic* f)
{
	int t = f->sizeHijos();
	list< pair<Color,int> >* colores = new list< pair<Color,int> >();
	pair<Color,int>* par;

	for(int i = 0; i < t; i++)
	{
		par = new pair<Color,int>();
		par->first = Color(-1,-1,-1);
		par->second = 0;
		colores->push_back(*par);
	}

	sumarArea(colores, f);

	for(int j = 0; j < t; j++)
	{
		sumarArea(colores, (FigureMusic*) f->getHijoAt(j));
	}

	Scriabin* s = new Scriabin();

	int aux = 0;
	Color sol;

	list< pair<Color,int> >::iterator it = colores->begin();

	while(it != colores->end())
	{
		if(it->second > aux)
		{
			aux = it->second;
			sol = it->first;
		}
		it++;
	}

	return s->getNota(sol);
}

void ComposerMelodia::sumarArea(list< pair<Color,int> >* cs, FigureMusic* f)
{
	bool encontrado = false;

	list< pair<Color,int> >::iterator it = cs->begin();

	while(it != cs->end() && !encontrado)
	{
		if(it->first.r == f->getRGB().r && it->first.g == f->getRGB().g && it->first.b == f->getRGB().b)
		{
			it->second += f->getArea();

			// Resto las areas de los hijos incrustados dentro de la figura f
			for(int i = 0; i < f->sizeHijos(); i++)
			{
				it->second -= f->getHijoAt(i)->getArea();
			}

			encontrado = true;
		}
		else if(it->first.r < 0 || it->first.g < 0 || it->first.b < 0)
		{
			it->first = f->getRGB();
			it->second = f->getArea();

			// Resto las areas de los hijos incrustados dentro de la figura f
			for(int i = 0; i < f->sizeHijos(); i++)
			{
				it->second -= f->getHijoAt(i)->getArea();
			}

			encontrado = true;
		}

		it++;
	}
}

void ComposerMelodia::calcularPadres(FigureMusic* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos)
{
	int areaPadre = f->getArea();
	int id = f->getId();
	Segmento* segmento;
	bool encontrado= false;
	int nSegRepartidos = 0;
	int nSegDar;

	// Busco el segmento que corresponde a este padre
	list< pair<Segmento*,int> >::iterator it = segs.begin();
	while(it != segs.end() && !encontrado)
	{
		if(id == it->second)
		{
			segmento = it->first;
			encontrado = true;
		}
		it++;
	}

	// Es hoja (segun vlad)
	if(f->sizeHijos() == 0)
	{
		segmentos->push_back(make_pair(segmento,nsegmentos));
	}
	// Tiene hijos
	else
	{
		for(int i = 0; i < f->sizeHijos(); i++)
		{
			nSegDar = (nsegmentos * f->getHijoAt(i)->getArea()) / areaPadre;
			nSegRepartidos += nSegDar;
			calcularPadres((FigureMusic*) f->getHijoAt(i), segs, nSegDar, segmentos);
		}
		segmentos->push_back(make_pair(segmento,nsegmentos - nSegRepartidos));
	}
}

/*------Getters------*/
Conf* ComposerMelodia::getConfig()
{
	return config;
}

string ComposerMelodia::getUsrConfFile()
{
	return usrConfFile;
}

string ComposerMelodia::getPic()
{
	return pic;
}

string ComposerMelodia::getTmpMIDIPath()
{
	return tmpMIDIPath;
}

/*------Setters------*/
void ComposerMelodia::setConfig(string c)
{
	config->read(c);
}

void ComposerMelodia::setUsrConfFile(string f)
{
	usrConfFile = f;
}

void ComposerMelodia::setPic(string p)
{
	pic = p;
}

void ComposerMelodia::setTmpMIDIPath(string m)
{
	tmpMIDIPath = m;
}
