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
	//Vemos el color y en que nos movemos.
	Color color = f->getRGB();
	Scriabin* scriabin = new Scriabin();

	//int nota = scriabin->getNota(color);

	//Ordenamos los vertices de la figura teniendo en cuenta el focus... (nada por ahora) CAMBIAR!
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	//Componemos:

		// Duracion ***************

	//Vemos long lado medio, lado mayor y lado menor.
	
	//Calculamos la longitud total de la figura
	double distTotal = 0, distMin = 9000000, distMax = 0;
	vector< double > distWithNext;  //Distancias con el siguiente vertice.
	for(int i = 0; i < numVertices; i++)
	{
		distWithNext.push_back( dist2DPoints(vertices.at(i)->getPair(), vertices.at((i+1)%numVertices)->getPair()) );
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


		//Tono **************

	//Ahora segun la duracion que nos han dado y los angulos que se forman con las aristas de la figura añadimos notas
	double lastAngle, actualAngle;
	int step;	// El cambio de tono que vamos a hacer. En pasos sobre la escala dada anteriormente
	Nota* lastNote,* note;
	//La primera nota es el color de la figura (no disponemos de más info)
	lastNote = new Nota(durVertice.at(0), scriabin->getNota(color, tableScale));
	MajorScale scale;
	delete tableScale;
	tableScale = new TableScale(scale.getScaleSteps(), lastNote->getTono());
	int degree = tableScale->getDegreeTone(lastNote->getTono());
	seg->getSimbolos()->pushBack(lastNote);
	lastAngle = angleOf2Lines2(vertices.at(numVertices-1)->getPair(), vertices.at(0)->getPair(), vertices.at(0)->getPair(), vertices.at(1)->getPair());
	//Ahora el resto de vértices desde 1 a numVertices
	for(int i = 1; i < numVertices; i++)
	{
		actualAngle = angleOf2Lines2(vertices.at(mod((i-1),numVertices))->getPair(), vertices.at(i)->getPair(), vertices.at(i)->getPair(), vertices.at((i+1)%numVertices)->getPair());
		//step = (int) floor(sin(angle)*2); //Como mucho dejamos que de un salto de 3 tonos-Escala (que no semitonos)

		note = getNextDegreeNote(degree, actualAngle, lastAngle, lastNote, durVertice.at(i));

		seg->getSimbolos()->pushBack(note);  //La nota respecto al vertice.
		lastNote = note;
		lastAngle = actualAngle;
	}
	lastNote = NULL;
	note = NULL;
	delete scriabin;
	scriabin = NULL;

	return true;
}

Segmento* ComposerFigMelody2::decMelodyFig(FigureMusic* f, Segmento* seg)
{
	Segmento* out = new Segmento();
	Scriabin* scriabin = new Scriabin();

	//Vamos a ir analizando el otro segmento de dos en dos notas.

	if(seg->getSimbolos()->size() < 2)
		return decSimbolo((Nota*)seg->getAt(0), f->sizeVertices(), tableScale->getDegreeTone(scriabin->getNota(f->getRGB(), tableScale)));
	
	int pos;
	if((f->sizeVertices()*4) < seg->getSimbolos()->size()) 
		pos = seg->getSimbolos()->size()/2;
	else if((f->sizeVertices()*2) < seg->getSimbolos()->size())
		pos = seg->getSimbolos()->size() - f->sizeVertices()*2;
	else
		pos = seg->getSimbolos()->size() - f->sizeVertices();

	Nota* n1, * n2;
	Segmento* aux;
	Simbolos* s = new Simbolos();
	int degree = tableScale->getDegreeTone(scriabin->getNota(f->getRGB(), tableScale));

	//Silencios
	for(int i = 0; i < pos-1; i++)
		s->pushBack(new Nota(seg->getAt(i)->getDuracion(), 0));
	out->setSimbolos(s);

	//La decoracion
	while( pos < seg->getSimbolos()->size() )
	{
		n1 = (Nota*)seg->getAt(pos-1);
		n2 = (Nota*)seg->getAt(pos);

		aux = dec2Simbolos(n1, n2, degree);
		out->addSimbolos(aux->getSimbolos());

		pos += 2;
	}
	
	delete scriabin;
	scriabin = NULL;
	return out;

}

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
	return NULL;
}

Nota* ComposerFigMelody2::getNextDegreeNote(int degree, double actualAngle, double lastAngle, Nota* lastNote, int durNote)
{
	Nota* note;
	/*int alfa1 = PI/5; // 36º
	int alfa2 = PI/3; // 60º
	int alfa3 = PI/2; // 90º
	int alfa4 = PI; // 180º*/
	int alfa1 = 36; 
	int alfa2 = 90; 
	int alfa3 = 180; 
	int alfa4 = 360; 

	double diff = abs(actualAngle - lastAngle);

	/*
	// Nos movemos en la escala y no en el acorde
	if(diff > alfa1)
		if(diff > alfa2)
			if(diff > alfa3)
				if(diff > alfa4)
					note = new Nota(durNote, tableScale->nextNTone(lastNote->getTono(),4));
				else
					note = new Nota(durNote, tableScale->nextNTone(lastNote->getTono(),3));
			else
				note = new Nota(durNote, tableScale->nextNTone(lastNote->getTono(),2));
		else
			note = new Nota(durNote, tableScale->nextNTone(lastNote->getTono(),1));
	else
		note = new Nota(durNote, lastNote->getTono());

	*/

	// Aqui nos movemos dentro del acorde del grado al que pertenece dentro de la escala diatónica

	if(diff > alfa1)
		if(diff > alfa2)
			if(diff > alfa3)
				if(diff > alfa4)
					if(actualAngle > lastAngle)
						note = new Nota(durNote, tableScale->nextNDegreeTone(degree, lastNote->getTono(),4));
					else
						note = new Nota(durNote, tableScale->prevNDegreeTone(degree, lastNote->getTono(),4));
				else
					if(actualAngle > lastAngle)
						note = new Nota(durNote, tableScale->nextNDegreeTone(degree, lastNote->getTono(),3));
					else
						note = new Nota(durNote, tableScale->prevNDegreeTone(degree, lastNote->getTono(),3));
			else
				if(actualAngle > lastAngle)
					note = new Nota(durNote, tableScale->nextNDegreeTone(degree, lastNote->getTono(),2));
				else
					note = new Nota(durNote, tableScale->prevNDegreeTone(degree, lastNote->getTono(),2));
		else
			if(actualAngle > lastAngle)
				note = new Nota(durNote, tableScale->nextNDegreeTone(degree, lastNote->getTono(),1));
			else
				note = new Nota(durNote, tableScale->prevNDegreeTone(degree, lastNote->getTono(),1));
	else
		note = new Nota(durNote, lastNote->getTono());

	return note;
}

