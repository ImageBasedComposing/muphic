#include "Compositors/ComposerFigMelody2.h"

/*------Constructoras------*/
ComposerFigMelody2::ComposerFigMelody2()
{
	// ctor
}

ComposerFigMelody2::ComposerFigMelody2(TableScale* tbScale)
{
	tableScale = tbScale;
}

/*------Destructora------*/
ComposerFigMelody2::~ComposerFigMelody2()
{
	//// dtor
	//delete tableScale;
	//tableScale = NULL;
}

//Hacemos una melodia de duracion limitada y que sea a partir de la figura dada.
bool ComposerFigMelody2::compMelodyFig(FigureMusic* f, Segmento* seg)
{
	//Ordenamos los vertices de la figura teniendo en cuenta el focus... (nada por ahora) CAMBIAR!
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	//Componemos:

		// Duracion ***************

	vector< int > durations = calcDurDirect(f, vertices);


		//Tono **************

	vector< int > tones = calcTonesDiff(f, vertices);

	//Añadimos las notas
	for(int i = 0; i < vertices.size(); i++)
		seg->getSimbolos()->pushBack(new Nota(durations.at(i), tones.at(i)));

	return true;
}

//Dada unos vértices ordenados, devolvemos vector de duraciones.
vector< int > ComposerFigMelody2::calcDurDirect(FigureMusic * f, vector< Vertice* > vertices)
{

	//Calculamos la longitud total de la figura
	int numVertices = vertices.size();
	double distTotal = 0, distMin = 9000000, distMax = 0;
	vector< double > distWithNext;  //Distancias con el siguiente vertice.
	for(int i = 0; i < numVertices; i++)
	{
		distWithNext.push_back( dist2DPoints(vertices.at(i)->getPair(), vertices.at((i+1)%numVertices)->getPair()) );
		//Vemos long lado medio, lado mayor y lado menor.
		distMin = min(distMin, distWithNext.back());
		distMax = max(distMax, distWithNext.back());
		distTotal += distWithNext.back();
	}
	double mediumLong = distTotal / numVertices;
	double maxLong = distMax;
	double minLong = distMin;

	//Algoritmo NO diferencial
	//Vamos a separar las longitudes en 3 tipos de duraciones:
	double dur0 = minLong;
	double dur1 = minLong + ((mediumLong - minLong)/2);
	double dur2 = mediumLong + ((maxLong - mediumLong)/2);
	double dur3 = maxLong;
	vector< int > durVertice; //Las duraciones que dispone cada vértice

	for(int i = 0; i < numVertices; i++)
	{
		if(distWithNext.at(i) >= dur0)
			if(distWithNext.at(i) > dur1)
				if(distWithNext.at(i) > dur2)
					durVertice.push_back(HALFNOTE); //dur = 32
				else
					durVertice.push_back(QUARTERNOTE); //dur = 16
			else
				durVertice.push_back(EIGHTHNOTE); //dur = 8
		else
			//error
			;
	}

	return durVertice;
}

//Dada unos vértices ordenados, devolvemos vector de tonos.
vector< int > ComposerFigMelody2::calcTonesDiff(FigureMusic * f, vector< Vertice* > vertices)
{

	vector<int> out;
	//Vemos el color y en que nos movemos.
	Color color = f->getRGB();
	Scriabin* scriabin = new Scriabin();

	//Ahora segun la duracion que nos han dado y los angulos que se forman con las aristas de la figura añadimos notas
	double lastAngle, actualAngle;
	int step;	// El cambio de tono que vamos a hacer. En pasos sobre la escala dada anteriormente
	int lastTone, tone;
	//La primera nota es el color de la figura (no disponemos de más info)
	lastTone = scriabin->getNota(color, tableScale);
	out.push_back(lastTone);
	/*MajorScale scale;	Salen cosas un poco bastante caca
	delete tableScale;
	//Cambiamos la escala a la nueva tonalidad.
	tableScale = new TableScale(scale.getScaleSteps(), lastTone);*/
	int degree = tableScale->getDegreeTone(lastTone);
	lastAngle = angleOf2Lines2(vertices.at(vertices.size()-1)->getPair(), vertices.at(0)->getPair(), vertices.at(0)->getPair(), vertices.at(1)->getPair());
	//Ahora el resto de vértices desde 1 a numVertices
	for(int i = 1; i < vertices.size(); i++)
	{
		actualAngle = angleOf2Lines2(vertices.at(mod((i-1),vertices.size()))->getPair(), vertices.at(i)->getPair(), vertices.at(i)->getPair(), vertices.at((i+1)%vertices.size())->getPair());

		tone = getNextDegreeTone(degree, actualAngle, lastAngle, lastTone);

		out.push_back(tone);  //La nota respecto al vertice.
		lastTone = tone;
		lastAngle = actualAngle;
	}

	delete scriabin;
	scriabin = NULL;

	return out;
}

vector< int > ComposerFigMelody2::calcTonesCounterPoint(FigureMusic * f, vector< Vertice* > vertices, Segmento* seg1, int pos, vector<int> duraciones)
{

	vector<int> out;
	//Vemos el color y en que nos movemos.
	Color color = f->getRGB();
	Scriabin* scriabin = new Scriabin();

	//Ahora segun la duracion que nos han dado y los angulos que se forman con las aristas de la figura añadimos notas
	double lastAngle, actualAngle;
	//int step;	// El cambio de tono que vamos a hacer. En pasos sobre la escala dada anteriormente
	int lastTone, tone;
	//La primera nota es el color de la figura (no disponemos de más info)
	lastTone = scriabin->getNota(color, tableScale);
	out.push_back(lastTone);
	int degree = tableScale->getDegreeTone(lastTone);
	lastAngle = angleOf2Lines2(vertices.at(vertices.size()-1)->getPair(), vertices.at(0)->getPair(), vertices.at(0)->getPair(), vertices.at(1)->getPair());
	int movement1 = 0, movement2 = 0; //Movimiento de la voz igual=0, arriba=1, abajo=2
	int lastMovement = 0, numSameMovement = 0;//MovDirecto = 0, MovContrario = 1, MovOblicuo = 2;
	//int interval1;
	//int interval2;
	Nota* n1,* n2;
	int pos1 = pos;
	int i = 1;
	int temp1 = 0, temp2 = 0;

	n1 = (Nota*)seg1->getAt(pos1);
	pos1++;
	temp1 = n1->getDuracion();
	n2 = (Nota*)seg1->getAt(pos1);
	pos1++;
	temp1 += n2->getDuracion();
	temp2 = duraciones.at(0);
	while(pos1 < seg1->size() && i < vertices.size())
	{
		temp2 += duraciones.at(i);
		while(temp2 > temp1)
		{
			(*n1) = (*n2);
			n2 = (Nota*)seg1->getAt(pos1);
			temp1 += n2->getDuracion();
			pos1++;
		}

		if(n1->getTono() < n2->getTono())
			movement1 = 1;
		else if(n1->getTono() > n2->getTono())
			movement1 = 2;
		else
			movement1 = 0;

		
		actualAngle = angleOf2Lines2(vertices.at(mod((i-1),vertices.size()))->getPair(), vertices.at(i)->getPair(), vertices.at(i)->getPair(), vertices.at((i+1)%vertices.size())->getPair());

		tone = getNextDegreeTone(degree, actualAngle, lastAngle, lastTone);

		if(lastTone < tone)
			movement2 = 1;
		else if (lastTone > tone)
			movement2 = 2;
		else
			movement2 = 0;

		if(movement1 == movement2)
		{ //Movimiento es Directo, ambas voces misma direccion
			if(lastMovement == 0)
			{
				if(numSameMovement > 4)
				{
					if(movement1 == 0)
					{
						tone = getNextDegreeTone(degree, actualAngle+36, lastAngle, lastTone);
						lastMovement = 2;
						numSameMovement = 1;
					}
					else
					{
						tone = getNextDegreeTone(degree, lastAngle, actualAngle, lastTone);
						lastMovement = 1;
						numSameMovement = 1;
					}
				}
				else
				{
					numSameMovement++;
				}
			}
			else
			{
				lastMovement = 0;
				numSameMovement = 1;
			}
		}
		else if(movement1 == 0 || movement2 == 0)
		{ //Movimiento es oblicuo, una voz estática la otra se mueve
			if(lastMovement == 2)
			{
				if(numSameMovement > 4)
				{
					if(movement2 == 0)
					{
						tone = getNextDegreeTone(degree, actualAngle+36, lastAngle, lastTone);
						if(movement1 == 1)
							lastMovement = 0;
						else
							lastMovement = 1;
						numSameMovement = 1;
					}
					else
					{
						tone = getNextDegreeTone(degree, lastAngle, actualAngle, lastTone);
						lastMovement = 2;
						numSameMovement = 1;
					}
				}
				else
				{
					numSameMovement++;
				}
			}
			else
			{
				lastMovement = 2;
				numSameMovement++;
			}
		}
		else
		{ //Movimiento contrario, una sube y la otra baja o al revés
			if(lastMovement == 1)
			{
				if(numSameMovement > 4)
				{
					tone = getNextDegreeTone(degree, lastAngle, actualAngle, lastTone);
					lastMovement = 0;
					numSameMovement = 1;
				}
				else
				{
					numSameMovement++;
				}
			}
			else
			{
				lastMovement = 1;
				numSameMovement++;
			}
		}


		out.push_back(tone);  //La nota respecto al vertice.
		lastTone = tone;
		lastAngle = actualAngle;

		i++;
	}

	delete scriabin;
	scriabin = NULL;

	return out;
}

//Decora la melodía dada en seg con la figura de entrada. Devuelve la 2º voz
Segmento* ComposerFigMelody2::decMelodyFig(FigureMusic* f, Segmento* seg)
{
	Segmento* out = new Segmento();
	Scriabin* scriabin = new Scriabin();

	//Si solo tenemos una nota, pues la decoramos como podamos:
	if(seg->getSimbolos()->size() < 2)
		return decSimbolo((Nota*)seg->getAt(0), f->sizeVertices(), tableScale->getDegreeTone(scriabin->getNota(f->getRGB(), tableScale)));
	
	//En caso de tener dos o mas notas:
	//Primero vemos donde vamos a decorar la melodia:
	//// Idea para realizar: Teniendo los baricentros o centros podemos calcular a que distancia están los baricentros de la padre y de la hija.
	int pos;
	if((f->sizeVertices()*4) < seg->getSimbolos()->size()) 
		pos = seg->getSimbolos()->size()/2;
	else if((f->sizeVertices()*2) < seg->getSimbolos()->size())
		pos = seg->getSimbolos()->size() - f->sizeVertices()*2;
	else
		pos = seg->getSimbolos()->size() - f->sizeVertices();

	//Ahora compongamos la melodía y la unimos haciendo cambios para cumplir con las leyes de contrapunto:
	//Creamos la melodía
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	vector< int > durations = calcDurDirect(f, vertices);
	
	vector< int > tones = calcTonesCounterPoint(f,vertices,seg,pos,durations);

	//Silencios
	for(int i = 0; i < pos-1; i++)
		out->pushBack(new Nota(seg->getAt(i)->getDuracion(), 0));

	//Añadimos las notas
	for(int i = 0; i < vertices.size(); i++)
		out->pushBack(new Nota(durations.at(i), tones.at(i)));

	//Añadimos los silencios finales
	while(out->getDuration() < seg->getDuration())
	{
		if((seg->getDuration() - out->getDuration()) > WHOLE)
			out->pushBack(new Nota(WHOLE, 0));
		else
			out->pushBack(new Nota(seg->getDuration() - out->getDuration(), 0));
	}

	delete scriabin;
	scriabin = NULL;

	return out;

}

//Teniendo una nota (preferiblemente de larga duración) la decora con las notas que puede dado el grado.
Segmento* ComposerFigMelody2::decSimbolo(Nota* n, int numVert, int degree)
{
	Segmento* out = new Segmento();
	Simbolos* dec = new Simbolos();
	for(int i = 0; i < numVert; i++)
		dec->pushBack(new Simbolo());
	//Comprobar cuales sonidos valen para hacer la decoracion.
	vector<int> tones = tableScale->getTonesDegree(degree);
	vector<int> consonant;
	vector<int> dissonant;
	for(int i = 0; i < tones.size(); i++)
		if (isConsonantInterval(n->getTono(),tones.at(i)))
			consonant.push_back(tones.at(i)+ESCALA*3);
		else
			dissonant.push_back(tones.at(i)+ESCALA*3);
	//Ahora que tenemos los consonantes y disonantes, vemos la duracion.
	vector<int> durations = patDurations(numVert, n->getDuracion(), 0/*Pattern*/);
	int durMin = 0;
	for(int i = 0; i < durations.size(); i++)
		int durMin = (durations.at(i)<durMin)? durations.at(i) : durMin;
	int dur;
	int perCentDis = 30;
	//Ahora asignamos las notas a cada símbolo
	for(int i = 0; i < durations.size(); i++)
	{
		dur = durations.at(i);
		if(dur == durMin)
			//We can mix consonant and disonant
			if(rand()%100 < perCentDis)
			{
				((Nota*)dec->getAt(i))->setTono(dissonant.at(rand()%dissonant.size()));
				perCentDis = perCentDis-10;
			}
			else
				((Nota*)dec->getAt(i))->setTono(consonant.at(rand()%consonant.size()));
		else
			((Nota*)dec->getAt(i))->setTono(consonant.at(rand()%consonant.size()));
	}

	out->setSimbolos(dec);
	return out;

}

Segmento* ComposerFigMelody2::dec2Simbolos(Nota* n1, Nota* n2, int degree)
{
	Segmento* out = new Segmento();
	Simbolos* dec = new Simbolos();

	//Comprobar cuales sonidos valen para hacer la decoracion.
	vector<int> tones = tableScale->getTonesDegree(degree);
	vector<int> consonant1, consonant2;
	vector<int> dissonant1, dissonant2;
	for(int i = 0; i < tones.size(); i++)
	{
		if (isConsonantInterval(n1->getTono(),tones.at(i)))
			consonant1.push_back(tones.at(i)+ESCALA*3);
		else
			dissonant1.push_back(tones.at(i)+ESCALA*3);

		if (isConsonantInterval(n2->getTono(),tones.at(i)))
			consonant2.push_back(tones.at(i)+ESCALA*3);
		else
			dissonant2.push_back(tones.at(i)+ESCALA*3);

	}
	//Ahora que tenemos los consonantes y disonantes, vemos la duracion.
	int durMin = (n1->getDuracion()<n2->getDuracion())? n1->getDuracion() : n2->getDuracion();
	int durMax = (n1->getDuracion()>n2->getDuracion())? n1->getDuracion() : n2->getDuracion();
	if(durMin == durMax) durMin = durMin/2;
	int durActual = 0;
	int perCentDis1 = 30*dissonant1.size();
	//Ahora asignamos las notas a cada símbolo
	Nota* n;
	if(n1->getDuracion() < n2->getDuracion())
	{
		if(rand()%100 < perCentDis1)
			if(n1->getDuracion() == durMin)
			{
				n = new Nota(durMin, dissonant1.at(rand()%dissonant1.size()));
				dec->pushBack(n);
				durActual += durMin;
			}
			else
			{
				n = new Nota(durMin, consonant1.at(rand()%consonant1.size()));
				dec->pushBack(n);
				n = new Nota(durMin, dissonant1.at(rand()%dissonant1.size()));
				dec->pushBack(n);
				durActual += durMin*2;
			}
		else
			if(n1->getDuracion() == durMin)
			{
				n = new Nota(durMin, consonant1.at(rand()%consonant1.size()));
				dec->pushBack(n);
				durActual += durMin;
			}
			else
			{
				n = new Nota(durMin, consonant1.at(rand()%consonant1.size()));
				dec->pushBack(n);
				n = new Nota(durMin, consonant1.at(rand()%consonant1.size()));
				dec->pushBack(n);
				durActual += durMin*2;
			}
		n = new Nota(n1->getDuracion()+n2->getDuracion() - durActual, consonant2.at(rand()%consonant2.size()));
		dec->pushBack(n);
	}
	else
	{
		n = new Nota(durMin, consonant1.at(rand()%consonant1.size()));
		dec->pushBack(n);
		n = new Nota(durMin, consonant1.at(rand()%consonant1.size()));
		dec->pushBack(n);
		durActual += durMin*2;
		n = new Nota(n1->getDuracion()+n2->getDuracion() - durActual, consonant2.at(rand()%consonant2.size()));
		dec->pushBack(n);
	}

	out->setSimbolos(dec);
	return out;

}

Segmento* ComposerFigMelody2::emptyMelody(Segmento* seg)
{
	int dur = 0;
	Segmento* out = new Segmento();
	Simbolos* s = new Simbolos();
	for(int i = 0; i < seg->getSimbolos()->size(); i++)
		dur = dur + seg->getAt(i)->getDuracion();
	while(dur > WHOLE)
	{
		s->pushBack(new Nota(WHOLE, 0));
		dur = dur - WHOLE;
	}
	s->pushBack(new Nota(dur, 0));

	out->setSimbolos(s);

	return out;

}

vector<int> ComposerFigMelody2::patDurations(int numSimbols, int durTotal, int pattern)
{
	int durMedium = QUARTERNOTE;
	if(durTotal <= (numSimbols+1) * SIXTEENTHNOTE)
		return patDurations(numSimbols/2, durTotal, pattern); //ERROR, demasiados simbolos en poca duracion
	else if(durTotal <= (numSimbols/2) * EIGHTHNOTE) //Si mas de la mitad de los simbolos deben ser semicorchea...
		durMedium = SIXTEENTHNOTE;
	else if(durTotal <= (numSimbols/2) * QUARTERNOTE) //Si mas de la mitad de los simbolos deben ser corchea...
		durMedium = EIGHTHNOTE;

	int durActual = 0;
	vector<int> out;

	for(int i = 0; i < numSimbols-1; i++)
	{
		if((durTotal - durActual - ((numSimbols-i)*durMedium)) < 0)
			out.push_back(durMedium/2);
		else
			out.push_back(durMedium);
	}
	//The last note is a large one (or it must be)
	out.push_back(durTotal-durActual);

	//Now we gonna find which pattern:
	if(pattern == 0)
	{ // short notes and at the end a long ones.
		return out;
	}
	else if(pattern == 1)
	{ // The long note first and next come the short ones.
		vector<int> aux;
		int numElem = out.size();
		for(int i = 0; i < numElem; i++)
		{
			aux.push_back(out.back());
			out.pop_back();
		}
		return aux;
	}

}

Segmento* ComposerFigMelody2::interMelodyFig(FigureMusic* f, Segmento* seg)
{
	Segmento* out = new Segmento();
	Simbolos* s = new Simbolos();
	//Ordenamos los vertices de la figura teniendo en cuenta el ...
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	//Componemos:

		// Duracion ***************

	vector< int > durations = calcDurDirect(f, vertices);


		//Tono **************

	vector< int > tones = calcTonesDiff(f, vertices);

	//Añadimos las notas
	for(int i = 0; i < vertices.size(); i++)
		s->pushBack(new Nota(durations.at(i), tones.at(i)));

	out->setSimbolos(s);
	return out;
}

int ComposerFigMelody2::getNextDegreeTone(int degree, double actualAngle, double lastAngle, int lastTone)
{
	int note;
	/*int alfa1 = PI/5; // 36º
	int alfa2 = PI/3; // 60º
	int alfa3 = PI/2; // 90º
	int alfa4 = PI; // 180º*/
	int alfa0 = 18;
	int alfa1 = 36; 
	int alfa2 = 90; 
	int alfa3 = 180; 
	int alfa4 = 360; 

	double diff = abs(actualAngle - lastAngle);

	// Aqui nos movemos dentro del acorde del grado al que pertenece dentro de la escala diatónica

	if(diff > alfa0)
		if(diff > alfa1)
			if(diff > alfa2)
				if(diff > alfa3)
					if(diff > alfa4)
						if(actualAngle > lastAngle)
							note = tableScale->nextNDegreeTone(degree, lastTone,4);
						else
							note = tableScale->prevNDegreeTone(degree, lastTone,4);
					else
						if(actualAngle > lastAngle)
							note = tableScale->nextNDegreeTone(degree, lastTone,3);
						else
							note = tableScale->prevNDegreeTone(degree, lastTone,3);
				else
					if(actualAngle > lastAngle)
						note = tableScale->nextNDegreeTone(degree, lastTone,2);
					else
						note = tableScale->prevNDegreeTone(degree, lastTone,2);
			else
				if(actualAngle > lastAngle)
					note = tableScale->nextNDegreeTone(degree, lastTone,1);
				else
					note = tableScale->prevNDegreeTone(degree, lastTone,1);
		else
			if(actualAngle > lastAngle)
				note = tableScale->nextTone(lastTone);
			else
				note = tableScale->prevTone(lastTone);
		else
			note = lastTone;

	return note;
}

