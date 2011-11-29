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
	figuras = new Figuras();
	figuras->cargar(pic);

	Voz* v1 = new Voz();
	Voces* vs = new Voces(melodia->getVoces());

	//Cosas de la voz
	v1->setInstrumento(TAIKO_DRUM);

	//Calculamos la tonalidad
	v1->setTonalidad(REM);

	//Cosas del segmento
	Segmento* seg1;// = new Segmento();
	Metrica m;//4/4

	// Cosas del compositor
	Figura* f;
	Segmento* seg = new Segmento();
	list< pair<Segmento*,int> > segs;
	pair<Segmento*,int> par;
	Nota* nPpal;

	// Recorro las figuras y calculo su melodía
	for(int i = 0; i < figuras->sizeFig(); i++)
	{
		seg1 = new Segmento();
		f = figuras->getFigAt(i);
		seg1->setMetrica(m);
		seg1->setTempo(180);

		// Para cada figura saco la nota de su pentatonica y calculo su segmento de melodía
		nPpal = new Nota(notaFigura(f));
		calcularMelodiaFig(f,seg1,nPpal);
		par.second = f->getId();
		par.first = seg1;
		segs.push_back(par);
	}
	
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
		f = figuras->getPadreAt(i);
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
void ComposerMelodia::calcularMelodiaFig(Figura* f, Segmento* seg, Nota* n)
{
	list< pair<float,float> > calc = f->polarize();
	Nota* nPpal = new Nota(n->getDuracion(),n->getTono());
	Nota* nAux;
	float longMedia = 0;
	Simbolos* ss = new Simbolos();

	// Calculo la media de las longitudes
	for(list< pair<float,float> >::iterator it; it != calc.end(); it++)
	{
		longMedia += it->second;
	}

	longMedia = longMedia / calc.size();

	for(list< pair<float,float> >::iterator it; it != calc.end(); it++)
	{
		// Crea la nota con la duracion y el tono que le corresponden
		nAux = new Nota(calcDur(longMedia,it->second),calcTono(it->first,nPpal));

		// La añade al segmento
		ss->pushBack(nAux);
	}
	
	seg->setSimbolos(ss);
}

int ComposerMelodia::calcTono(float angulo, Nota* nPpal)
{
	return DO_C;
}

int ComposerMelodia::calcDur(float longMedia, float longitud)
{
	float durAprox = ( QUARTERNOTE * longitud ) / longMedia;
	float aux = INT_MAX;
	int sol;

	float notas[7] = {1,2,4,8,16,32,64};

	for(int i = 0; i < 7; i++)
	{
		if(std::abs(notas[i] - durAprox) < aux)
		{
			aux = std::abs(notas[i] - durAprox);
			sol = i;
		}
	}

	return (int) notas[sol];
}

int ComposerMelodia::notaFigura(Figura* f)
{
	int t = f->sizeHijos();
	list< pair<string,int> >* colores = new list< pair<string,int> >();
	pair<string,int>* par;

	for(int i = 0; i < t; i++)
	{
		par = new pair<string,int>();
		par->first = "";
		par->second = 0;
		colores->push_back(*par);
	}

	sumarArea(colores, f);

	for(int j = 0; j < t; j++)
	{
		sumarArea(colores, f->getHijoAt(j));
	}

	Scriabin* s = new Scriabin();

	int aux = 0;
	string sol = "";

	list< pair<string,int> >::iterator it = colores->begin();

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

void ComposerMelodia::sumarArea(list< pair<string,int> >* cs, Figura* f)
{
	bool encontrado = false;

	list< pair<string,int> >::iterator it = cs->begin();

	while(it != cs->end() && !encontrado)
	{
		if(strcmp(it->first.c_str(),f->getColor().c_str()) == 0)
		{
			it->second += f->getArea();

			// Resto las areas de los hijos incrustados dentro de la figura f
			for(int i = 0; i < f->sizeHijos(); i++)
			{
				it->second -= f->getHijoAt(i)->getArea();
			}

			encontrado = true;
		}
		else if(strcmp(it->first.c_str(),"") == 0)
		{
			it->first = f->getColor();
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

void ComposerMelodia::calcularPadres(Figura* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos)
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
			calcularPadres(f->getHijoAt(i), segs, nSegDar, segmentos);
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
