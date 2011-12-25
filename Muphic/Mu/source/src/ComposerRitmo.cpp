#include "ComposerRitmo.h"

ComposerRitmo::ComposerRitmo()
{
    //ctor
}

ComposerRitmo::ComposerRitmo(Music* m, int numSeg)
{
	ritmo = m;
	NUMSEGMENTOS = numSeg;
}

ComposerRitmo::~ComposerRitmo()
{
    //dtor
}

Music* ComposerRitmo::composeMusic()
{
	
	figuras = new FiguresMusic();
	figuras->cargar(pic);

	Voz* v1 = new Voz();
	Voces* vs = new Voces(ritmo->getVoces());

	//Cosas de la voz
	v1->setInstrumento(WOODBLOCK);

	//Calculamos la tonalidad
	v1->setTonalidad(REM);

	//Cosas del segmento
	Segmento* seg1;// = new Segmento();
	Metrica m;//4/4

	// Calculamos la nota
	Nota* n = new Nota(nota(figuras));

	int p = figuras->sizeFig();
	FigureMusic* f;
	Segmento* seg = new Segmento();
	list< pair<Segmento*,int> > segs;
	pair<Segmento*,int> par;

	for(int i = 0; i < p; i++)
	{
		seg1 = new Segmento();
		f = (FigureMusic*)figuras->getFigAt(i);
		seg1->setMetrica(m);
		seg1->setTempo(180);
		calcularSegmento(f,seg1,n);
		par.second = f->getId();
		par.first = seg1;
		segs.push_back(par);
	}

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

	ritmo->setVoces(vs);
	ritmo->setComposer("Blah!");
	ritmo->setName("Rithm");
	ritmo->setBaseLenght(make_pair(1,16));

	return ritmo;
}

string ComposerRitmo::compose()
{
	return composeMusic()->toMidi();
}

string ComposerRitmo::compose(string picPath, string usrConfPath)
{
	setPic(picPath);
	setUsrConfFile(usrConfPath);

	return compose();
}

/*------Funciones Privadas------*/
int ComposerRitmo::nota(FiguresMusic* f)
{
	int t = f->sizeFig();
	//int i = 0;
	list< pair<string,int> >* colores = new list< pair<string,int> >();
	pair<string,int>* par;

	for(int i = 0; i < t; i++)
	{
		par = new pair<string,int>();
		par->first = "";
		par->second = 0;
		colores->push_back(*par);
	}

	for(int j = 0; j < t; j++)
	{
		sumarArea(colores, (FigureMusic*)f->getFigAt(j));
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

void ComposerRitmo::sumarArea(list< pair<string,int> >* cs, FigureMusic* f)
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

void ComposerRitmo::calcularSegmento(FigureMusic* f, Segmento* seg, Nota* n)
{
	int t = f->sizeVertices();
	pair<int,int> center;
	center.first = 0;
	center.second = 0;

	Simbolos* ss = new Simbolos();
	Nota* s;

	if(t > 2)
	{
		center = f->getBarycenter();

		// Creación de notas

		Vertice* v;
		int notas[8] = {0,0,0,0,0,0,0,0};

		for(int j = 0; j < t; j++)
		{
			v = f->getVerticeAt(j);

			if(v->x < center.first && v->y > center.second && v->y <= -v->x + center.first + center.second)
			{
				notas[0] += 1;
			}
			else if(v->x <= center.first && v->y > center.second && v->y > -v->x + center.first + center.second)
			{
				notas[1] += 1;
			}
			else if(v->x > center.first && v->y > center.second && v->y >= v->x + (-center.first + center.second))
			{
				notas[2] += 1;
			}
			else if(v->x > center.first && v->y >= center.second && v->y < v->x + (-center.first + center.second))
			{
				notas[3] += 1;
			}
			else if(v->x > center.first && v->y < center.second && v->y >= -v->x + center.first + center.second)
			{
				notas[4] += 1;
			}
			else if(v->x >= center.first && v->y < center.second && v->y < -v->x + center.first + center.second)
			{
				notas[5] += 1;
			}
			else if(v->x < center.first && v->y < center.second && v->y <= v->x + (-center.first + center.second))
			{
				notas[6] += 1;
			}
			else if(v->x < center.first && v->y <= center.second && v->y > v->x + (-center.first + center.second))
			{
				notas[7] += 1;
			}
		} // for

		double pownum = 2;


		
		for(int k = 0; k < 8; k++)
		{
			if (notas[k] == 0)
			{
				s = new Nota(QUARTERNOTE, 0); //silencio si no hay nota en el octante (?)
				ss->pushBack(s);
				continue;
			}

			// Inserto blancas si no hay vertices y por debajo si hay
			int duracion = 0;
			for(int k1 = 0; k1 < notas[k]; k1++)
			{
				// cambiamos lo de las notas para que haga cosas con la batera
				s = new Nota((QUARTERNOTE*2)/(int)pow(pownum,notas[k]),(n->getTono()));
				/*duracion = (QUARTERNOTE*2)/(int)pow(pownum,notas[k]);
				s = new Nota(duracion,getDrumTone(duracion));*/
				ss->pushBack(s);
			}
		}

		seg->setSimbolos(ss);

		}
	// Para circulos
	else
	{
		center.first = f->getVerticeAt(1)->x;
		center.second = f->getVerticeAt(1)->y;
		// cambiamos lo de las notas para que haga cosas con la batera
		int duracion = 0;
		for(int f=0; f < 4; f++)
		{
			ss->pushBack(new Nota((QUARTERNOTE*2),n->getTono()));
			/*duracion = (QUARTERNOTE*2);
			ss->pushBack(new Nota(duracion,getDrumTone(duracion)));*/
		}
		seg->setSimbolos(ss);
	}
}

int ComposerRitmo::getDrumTone(int duracion)
{
	if (duracion >= QUARTERNOTE)
		// pomm!
		return MI + ESCALA;
	else
		// chss!
		return LA + 2*ESCALA;
}


void ComposerRitmo::calcularPadres(FigureMusic* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos)
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
			calcularPadres((FigureMusic*)f->getHijoAt(i), segs, nSegDar, segmentos);
		}
		segmentos->push_back(make_pair(segmento,nsegmentos - nSegRepartidos));
	}
}

/*------Getters------*/
Conf* ComposerRitmo::getConfig()
{
	return config;
}

string ComposerRitmo::getUsrConfFile()
{
	return usrConfFile;
}

string ComposerRitmo::getPic()
{
	return pic;
}

string ComposerRitmo::getTmpMIDIPath()
{
	return tmpMIDIPath;
}

/*------Setters------*/
void ComposerRitmo::setConfig(string c)
{
	config->read(c);
}

void ComposerRitmo::setUsrConfFile(string f)
{
	usrConfFile = f;
}

void ComposerRitmo::setPic(string p)
{
	pic = p;
}

void ComposerRitmo::setTmpMIDIPath(string m)
{
	tmpMIDIPath = m;
}
