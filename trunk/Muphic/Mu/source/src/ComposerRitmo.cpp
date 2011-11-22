#include "ComposerRitmo.h"

ComposerRitmo::ComposerRitmo()
{
    //ctor
}

ComposerRitmo::ComposerRitmo(Music* m)
{
	ritmo = m;
}

ComposerRitmo::~ComposerRitmo()
{
    //dtor
}

string ComposerRitmo::compose() 
{ 

	figuras = new Figuras();
	figuras->cargar(pic);

	Voz* v1 = new Voz();
	Voces* vs = new Voces();

	//Cosas de la voz
	v1->setInstrumento(1);

	//Calculamos la tonalidad
	v1->setTonalidad(REM);
	vs->pushBack(v1);

	//Cosas del segmento
	Segmento* seg1;// = new Segmento();
	Metrica m;//4/4

	// Calculamos la nota
	Nota* n = new Nota(nota(figuras));

	int p = figuras->sizeFig();
	Figura* f;
	Segmento* seg = new Segmento();
	list<pair<int,Segmento*>> segs;
	pair<int,Segmento*> par;

	for(int i = 0; i < p; i++)
	{
		seg1 = new Segmento();
		f = figuras->getFigAt(i);
		seg1->setMetrica(m);
		seg1->setTempo(180);
		calcularSegmento(f,seg1,n);
		par.first = f->getId();
		par.second = seg1;
		segs.push_back(par);
	}

	list<pair<int,Segmento*>>* segmentos = new list<pair<int,Segmento*>>();
	
	int numPadres = figuras->sizePadre();

	int areaTotal = 0;
	for(int n = 0; n < numPadres; n++)
		areaTotal += figuras->getPadreAt(n)->getArea();

	int segmentosPadre;

	for(int i = 0; i < numPadres; i++)
	{
		f = figuras->getPadreAt(i);
		segmentosPadre = ((f->getArea()*NUMSEGMENTOS)/areaTotal);
		calcularPadres(f,segs,segmentosPadre, segmentos);
		// Patronizador ordena segmentos devueltos y me da 1 de los segmentos del programa
		// A�ado eso al ritmo final a patronizar
	}

	//Patronizo el ritmo final
	Segmentos* s = new Segmentos();

	//Lo a�ado a la voz
	v1->setSegmentos(s);

	Voces* vz = new Voces();
	vz->pushBack(v1);

	ritmo->setVoces(vz);
	ritmo->setComposer("Blah!");
	ritmo->setName("Rithm");
	ritmo->setBaseLenght(make_pair(1,16));

	return ritmo->toMidi(); 
}

string ComposerRitmo::compose(string picPath, string usrConfPath)
{ 
	setPic(picPath);
	setUsrConfFile(usrConfPath);

	return compose();
}

/*------Funciones Privadas------*/
int ComposerRitmo::nota(Figuras* f)
{
	int t = f->sizeFig();
	int i = 0;
	list<pair<string,int>>* colores = new list<pair<string,int>>();
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
		sumarArea(colores, f->getFigAt(j));
	}

	Scriabin* s = new Scriabin();

	int aux = 0;
	string sol = "";

	list<pair<string,int>>::iterator it = colores->begin();

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

void ComposerRitmo::sumarArea(list<pair<string,int>>* cs, Figura* f)
{
	bool encontrado = false;

	list<pair<string,int>>::iterator it = cs->begin();

	while(it != cs->end() && !encontrado)
	{
		if(strcmp(it->first.c_str(),f->getColor().c_str()) == 0)
		{
			it->second += f->getArea();
			encontrado = true;
		}
		else if(strcmp(it->first.c_str(),"") == 0)
		{
			it->first = f->getColor();
			it->second = f->getArea();
			encontrado = true;
		}

		it++;
	}
}

void ComposerRitmo::calcularSegmento(Figura* f, Segmento* seg, Nota* n)
{
	int t = f->sizeVertices();
	pair<int,int> center;
	center.first = 0;
	center.second = 0;

	Simbolos* ss = new Simbolos();
	Nota* s;

	if(t > 2)
	{
		center = f->getCentro();

		// Creaci�n de notas

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
			for(int k1 = 0; k1 < notas[k]; k1++)
			{
				s = new Nota((QUARTERNOTE*2)/(int)pow(pownum,notas[k]),(n->getTono()));
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
		for(int f=0; f < 4; f++)
			ss->pushBack(new Simbolo());
		seg->setSimbolos(ss);
	}
}

void ComposerRitmo::calcularPadres(Figura* f, list<pair<int,Segmento*>> segs, int nsegmentos, list<pair<int,Segmento*>>* segmentos)
{
	int areaPadre = f->getArea();
	int id = f->getId();
	Segmento* segmento;
	bool encontrado= false;
	int nSegRepartidos = 0;
	int nSegDar;

	// Busco el segmento que corresponde a este padre
	list<pair<int,Segmento*>>::iterator it = segs.begin();
	while(it != segs.end() && !encontrado)
	{
		if(id == it->first)
		{
			segmento = it->second;
			encontrado = true;
		}
		it++;
	}

	// Es hoja (segun vlad)
	if(f->sizeHijos() == 0)
	{
		segmentos->push_back(make_pair(nsegmentos,segmento));
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
		segmentos->push_back(make_pair(nsegmentos - nSegRepartidos,segmento));
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