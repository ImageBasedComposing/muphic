#include "Compositors/ComposerFigMelody2.h"

/*------Constructoras------*/
ComposerFigMelody2::ComposerFigMelody2(ColorSystem* cs) : ComposerVoice(cs)
{
	// ctor
}

ComposerFigMelody2::ComposerFigMelody2(ColorSystem* cs, TableScale* tbScale) : ComposerVoice(cs, tbScale)
{
	// ctor
}

/*------Destructora------*/
ComposerFigMelody2::~ComposerFigMelody2()
{
	//// dtor
	//delete tb;
	//tb = NULL;
}

//Hacemos una melodia de duracion limitada y que sea a partir de la figura dada.
bool ComposerFigMelody2::compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur)
{
	//Ordenamos los vertices de la figura teniendo en cuenta el focus... (nada por ahora) CAMBIAR!
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	//Componemos:

		// Duracion ***************

	vector< int > durations = calcDurDirect(f, vertices, maxDur, minDur);

	//No hacemos adaptación de las duraciones:
	// adaptDurations(&durations, dur);

		//Tono **************

	vector< int > tones = calcTonesDiff(f, vertices, durations);

	//Añadimos las notas
	for(int i = 0; i < vertices.size(); i++)
		seg->pushBack(new Nota(durations.at(i), tones.at(i)));

	return true;
}

//Dada unos vértices ordenados, devolvemos vector de duraciones.
vector< int > ComposerFigMelody2::calcDurDirect(FigureMusic * f, vector< Vertice* > vertices, int maxDur, int minDur)
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
	if(distMin > (distMax /2) )
		minLong = minLong / 2;

	//Algoritmo NO diferencial
	//Vamos a separar las longitudes en 3 tipos de duraciones:
	double dur0 = minLong;
	double dur1 = minLong + ((mediumLong - minLong)/2);
	double dur2 = mediumLong + ((maxLong - mediumLong)/2);
	double dur3 = maxLong;
	vector< int > durVertice; //Las duraciones que dispone cada vértice

	int interDur;
	if (abs(maxDur-QUARTERNOTE) >= abs(minDur-QUARTERNOTE))
		interDur = minDur*2;
	else
		interDur = maxDur/2;
	for(int i = 0; i < numVertices; i++)
	{
		if(distWithNext.at(i) >= dur0)
			if(distWithNext.at(i) > dur1)
				if(distWithNext.at(i) > dur2)
					durVertice.push_back(maxDur); //dur = 32
				else
					durVertice.push_back(interDur); //dur = 16
			else
				durVertice.push_back(minDur); //dur = 8
		else
			//error
			;
	}

	return durVertice;
}

//Dada unos vértices ordenados, devolvemos vector de tonos.
vector< int > ComposerFigMelody2::calcTonesDiff(FigureMusic * f, vector< Vertice* > vertices, vector<int> duraciones)
{

	vector<int> out;
	//Vemos el color y en que nos movemos.
	Color color = f->getRGB();

	//Ahora segun la duracion que nos han dado y los angulos que se forman con las aristas de la figura añadimos notas
	double lastAngle, actualAngle;
	int step;	// El cambio de tono que vamos a hacer. En pasos sobre la escala dada anteriormente
	int lastTone, tone;
	//La primera nota es el color de la figura (no disponemos de más info)
	lastTone = cs->getNota(color, tb);
	out.push_back(lastTone);
	/*MajorScale scale;	Salen cosas un poco bastante caca
	delete tb;
	//Cambiamos la escala a la nueva tonalidad.
	tb = new tb(scale.getScaleSteps(), lastTone);*/
	int degree = tb->getDegreeTone(lastTone);
	lastAngle = angleOf2Lines2(vertices.at(vertices.size()-1)->getPair(), vertices.at(0)->getPair(), vertices.at(0)->getPair(), vertices.at(1)->getPair());
	//Ahora el resto de vértices desde 1 a numVertices
	for(int i = 1; i < vertices.size(); i++)
	{
		actualAngle = angleOf2Lines2(vertices.at(mod((i-1),vertices.size()))->getPair(), vertices.at(i)->getPair(), vertices.at(i)->getPair(), vertices.at((i+1)%vertices.size())->getPair());

		tone = getNextTone(degree, actualAngle, lastAngle, lastTone, duraciones.at(i), duraciones.at(i-1));

		out.push_back(tone);  //La nota respecto al vertice.
		lastTone = tone;
		lastAngle = actualAngle;
	}

	return out;
}

//Dados unos vértices, duraciones y el segmento que vamos a acompañar, devolvemos los tonos siguiendo parte de la teoria contrapuntística (CounterPoint)
vector< int > ComposerFigMelody2::calcTonesCounterPoint(FigureMusic * f, vector< Vertice* > vertices, Segmento* seg1, int pos, vector<int> duraciones)
{

	vector<int> out;
	//Vemos el color y en que nos movemos.
	Color color = f->getRGB();

	//Ahora segun la duracion que nos han dado y los angulos que se forman con las aristas de la figura añadimos notas
	double lastAngle, actualAngle;
	//int step;	// El cambio de tono que vamos a hacer. En pasos sobre la escala dada anteriormente
	int lastTone, tone;
	//La primera nota es el color de la figura (no disponemos de más info)
	lastTone = cs->getNota(color, tb);
	out.push_back(lastTone);
	int degree = tb->getDegreeTone(lastTone);
	lastAngle = angleOf2Lines2(vertices.at(vertices.size()-1)->getPair(), vertices.at(0)->getPair(), vertices.at(0)->getPair(), vertices.at(1)->getPair());

	int movement1 = 0, movement2 = 0; //Movimiento de la voz igual=0, arriba=1, abajo=2
	int lastMovement = 0, numSameMovement = 0;//MovDirecto = 0, MovContrario = 1, MovOblicuo = 2;
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
	while(i < vertices.size() ) //&& (pos1 < seg1->size() || (pos1 = seg1->size() && (temp2+duraciones.at(i) <= temp1)))
	{
		temp2 += duraciones.at(i);
		while(temp2 > temp1)
		{
			n1 = n2;
			if( pos1 < seg1->size() )
				n2 = (Nota*)seg1->getAt(pos1);
			else
				n2 = (Nota*)seg1->getAt(seg1->size()-1);
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

		tone = getNextTone(degree, actualAngle, lastAngle, lastTone, duraciones.at(i), duraciones.at(i-1));

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
						tone = getNextTone(degree, actualAngle+36, lastAngle, lastTone, duraciones.at(i), duraciones.at(i-1));
						lastMovement = 2;
						numSameMovement = 1;
					}
					else
					{
						tone = getNextTone(degree, lastAngle, actualAngle, lastTone, duraciones.at(i), duraciones.at(i-1));
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
						tone = getNextTone(degree, actualAngle+36, lastAngle, lastTone, duraciones.at(i), duraciones.at(i-1));
						if(movement1 == 1)
							lastMovement = 0;
						else
							lastMovement = 1;
						numSameMovement = 1;
					}
					else
					{
						tone = getNextTone(degree, lastAngle, actualAngle, lastTone, duraciones.at(i), duraciones.at(i-1));
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
					tone = getNextTone(degree, lastAngle, actualAngle, lastTone, duraciones.at(i), duraciones.at(i-1));
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

		//Comprobamos tmb que no haga muchas disonancias y feas
		if(isDissonantInterval(tone, n2->getTono()) && duraciones.at(i) > EIGHTHNOTE)
		{
			tone = makeConsonant(n2->getTono(), tone);
		}

		out.push_back(tone);  //La nota respecto al vertice.
		lastTone = tone;
		lastAngle = actualAngle;

		i++;
	}

	return out;
}

//Decora la melodía dada en seg con la figura de entrada. Devuelve la 2º voz
bool ComposerFigMelody2::decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur, int minDur)
{
	//Ahora compongamos la melodía y la unimos haciendo cambios para cumplir con las leyes de contrapunto:
	//Creamos la melodía
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	vector< int > durations = calcDurDirect(f, vertices);

	//En caso de tener dos o mas notas:
	//Primero vemos donde vamos a decorar la melodia:
	//// Idea para realizar: Teniendo los baricentros o centros podemos calcular a que distancia están los baricentros de la padre y de la hija.
	int pos = 0;
	int durationTotal = 0, auxDur = 0;
	bool findPos = false;
	for(int i = 0; i < durations.size(); i++)
		durationTotal += durations.at(i);
	if( seg1->getDuration() <= durationTotal)
	{
		adaptDurations(&durations, seg1->getDuration());
		pos = 0; //Desde el principio
	}
	else{
		while(!findPos && pos < seg1->size())
		{
			auxDur += seg1->getAt(pos)->getDuracion() * 1.5; //Lo multiplicamos por 1.5 para estar seguros de no salirnos
			findPos = (durationTotal + auxDur) > seg1->getDuration();
			pos++;
		}
		pos--;
	}
	
	vector< int > tones = calcTonesCounterPoint(f,vertices,seg1,pos,durations);

	//Silencios
	for(int i = 0; i < pos; i++)
		seg->pushBack(new Nota(seg1->getAt(i)->getDuracion(), 0));

	//Añadimos las notas
	for(int i = 0; i < vertices.size(); i++)
		seg->pushBack(new Nota(durations.at(i), tones.at(i)));

	//Añadimos los silencios finales
	while(seg->getDuration() < seg1->getDuration())
	{
		if((seg1->getDuration() - seg->getDuration()) > WHOLE)
			seg->pushBack(new Nota(WHOLE, 0));
		else
			seg->pushBack(new Nota(seg1->getDuration() - seg->getDuration(), 0));
	}

	return true;

}

//Debe crear una melodía intermedia dentro del segmento dado.
bool ComposerFigMelody2::interMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur, int minDur)
{

	//Ordenamos los vertices de la figura teniendo en cuenta el ...
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	//Componemos:

		// Duracion ***************

	vector< int > durations = calcDurDirect(f, vertices);
	// adaptDurations(&durations, dur);

		//Tono **************

	vector< int > tones = calcTonesDiff(f, vertices, durations);

	//Añadimos las notas
	for(int i = 0; i < vertices.size(); i++)
		seg->pushBack(new Nota(durations.at(i), tones.at(i)));

	return true;
}

bool ComposerFigMelody2::composeVoice(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur, Segmento* seg1)
{
	if(seg1 != NULL)
		return decMelodyFig(f,seg1,seg,dur,maxDur,minDur);
	else
		return compMelodyFig(f,seg,dur,maxDur,minDur);
}

//Devuelve la siguiente nota dentro de un grado, pero si el ángulo es pequeño devuelve la nota más cercana.
// En caso de que el ángulo es ínfimo, se devuelve la misma nota.
int ComposerFigMelody2::getNextDegreeTone(int degree, double actualAngle, double lastAngle, int lastTone)
{
	int note;
	int alfa0 = 10;  //barrera para misma nota
	int alfa1 = 30;  //barrera para nota más cercana dentro de toda la escala
	int alfa2 = 120; //barrera para 1º nota dentro del acorde de grado más cercana
	int alfa3 = 240; //barrera para 2º nota dentro del acorde de grado más cercana
	int alfa4 = 360; //barrera para 3º nota dentro del acorde de grado más cercana

	double diff = abs(actualAngle - lastAngle);

	// Aqui nos movemos dentro del acorde del grado al que pertenece dentro de la escala diatónica

	if(diff > alfa0)
		if(diff > alfa1)
			if(diff > alfa2)
				if(diff > alfa3)
					if(diff > alfa4)
						if(actualAngle > lastAngle)
							note = tb->nextNDegreeTone(degree, lastTone,4);
						else
							note = tb->prevNDegreeTone(degree, lastTone,4);
					else // < alfa4
						if(actualAngle > lastAngle)
							note = tb->nextNDegreeTone(degree, lastTone,3);
						else
							note = tb->prevNDegreeTone(degree, lastTone,3);
				else // < alfa3
					if(actualAngle > lastAngle)
						note = tb->nextNDegreeTone(degree, lastTone,2);
					else
						note = tb->prevNDegreeTone(degree, lastTone,2);
			else // < alfa2
				if(actualAngle > lastAngle)
					note = tb->nextNDegreeTone(degree, lastTone,1);
				else
					note = tb->prevNDegreeTone(degree, lastTone,1);
		else // < alfa1
			if(actualAngle > lastAngle)
				note = tb->nextTone(lastTone);
			else
				note = tb->prevTone(lastTone);
	else // < alfa0
		note = lastTone;


	return note;
}

//Devuelve la siguiente nota que sea consonante si tiene una duración mayor que la anterior, sino la que nos den.
int ComposerFigMelody2::getNextTone(int degree, double actualAngle, double lastAngle, int lastTone, int actualDuration, int lastDuration)
{
	int tone;

	tone = getNextDegreeTone(degree, actualAngle, lastAngle, lastTone);

	if((abs(lastTone - tone) > 2) && isDissonantInterval(lastTone, tone) && actualDuration >= lastDuration)
	{
		if(actualAngle > lastAngle)
		{
			actualAngle = actualAngle / 2;
		}
		else
			lastAngle = lastAngle / 2;
		tone = getNextDegreeTone(degree, actualAngle, lastAngle, lastTone);
	}

	return tone;
}

//Hacemos que una nota (toneToModif) se vuelva en intervalo consonante con la nota dada.
int ComposerFigMelody2::makeConsonant(int tone, int toneToModif)
{
	int out = toneToModif;

	if(isConsonantInterval(tone, toneToModif))
		return out; //Devolvemos ya el que tenemos
	
	while(isDissonantInterval(tone, out))
	{
		if(tone > toneToModif)
			out = tb->prevTone(out);
		else
			out = tb->nextTone(out);
	}

	return out;

}

//Vamos a adaptar el vector de duraciones que nos han pasado a la duración dada intentando 
// hacer que en general todas las notas vayan decreciendo.
//minDur: intenta no bajar la duración de esa marca.
void ComposerFigMelody2::adaptDurations(vector<int>* durations, int duration, int minDur)
{
	int durationTotal = 0;
	for(int i = 0; i < durations->size(); i++)
		durationTotal += durations->at(i);

	if(duration == 0) //Error
		durationTotal = 0;

	int pos, posAux;
	bool divided = false;
	//Mientras no conseguimos el objetivo...
	while(durationTotal > duration)
	{
		pos = rand() % durations->size();
		if(durations->at(pos) < minDur)
		{
			posAux = (pos + 1) % durations->size();
			while(!divided && posAux != pos)
				if(durations->at(posAux) < minDur)
					posAux = (posAux + 1) % durations->size();
				else
				{
					durations->at(posAux) = durations->at(posAux) / 2;
					durationTotal -= durations->at(posAux);
					divided = true;
				}
			if(posAux == pos) //Ya se ha dado la vuelta y no hemos podido hacer split de ninguna nota
			{ //Rompemos la barrera de minDur. No hay otra solución
				durations->at(posAux) = durations->at(posAux) / 2;
				durationTotal -= durations->at(posAux);
			}
		}
		else
		{
			durations->at(pos) = durations->at(pos) / 2;
			durationTotal -= durations->at(pos);
		}
	} //Fin bucle while

}
