#include "ComposerFigMelody.h"

/*------Constructoras------*/
ComposerFigMelody::ComposerFigMelody()
{
	// ctor
}

ComposerFigMelody::ComposerFigMelody(TableScale* tbScale)
{
	tableScale = tbScale;
}

/*------Destructora------*/
ComposerFigMelody::~ComposerFigMelody()
{
	//// dtor
	//delete tableScale;
	//tableScale = NULL;
}

//Hacemos una melodia de duracion limitada y que sea a partir de la figura dada.
bool ComposerFigMelody::compMelodyFig(Figura* f, Segmento* seg, int dur)
{
	//Vemos el color y en que nos movemos.
	string color = f->getColor();
	Scriabin* scriabin = new Scriabin();

	int nota = scriabin->getNota(color);

	//Ordenamos los vertices de la figura teniendo en cuenta el focus... (nada por ahora) CAMBIAR!
	vector< Vertice* > vertices;
	int numVertices = f->getNumVertices();
	for(int i = 0; i < numVertices; i++)
		vertices.push_back(f->getVerticeAt(i));

	//Componemos:

		// Duracion ***************

	//Tratamos primero el problema de la duración: Vamos a asociar longitudes entre vertices con la duración total que disponemos
	int durActual = 0; //Duración que llevamos usado

	//Calculamos la longitud total de la figura
	float distTotal = 0;
	vector< float > distWithNext;  //Distancias con el siguiente vertice.
	for(int i = 0; i < numVertices; i++)
	{
		distWithNext.push_back( dist2DPoints(vertices.at(i)->getPair(), vertices.at((i+1)%numVertices)->getPair()) );
		distTotal += distWithNext.back();
	}
	//Ahora vemos la proporción duración-Distancia 1 Dur = X Dist
	float proporDurDist = distTotal / dur;
	vector< int > durVertice; //Las duraciones que dispone cada vértice
	//Primero asignación de duraciones iniciales, luego lo recalibramos para usar toda la duración disponible
	double fractPart;
	double intPart;
	for(int i = 0; i < numVertices; i++)
	{
		fractPart = modf(distWithNext.at(i) / proporDurDist, &intPart);
		durVertice.push_back((int)intPart);
		durActual += (int)intPart;
		distWithNext.at(i) = (float)fractPart; //Dejamos la fraccion que nos ha quedado para los reajustes
	}
	//Reajustes de la duracion. Simplemente se reasigna toda la duración que falta. Se puede mejorar con un filtro de poner cosas inteligentes (no negra+semifusa)
	int candidato = 0;
	float propor = 0.0;
	while(durActual < dur)
	{
		for(int i = 0; i < numVertices; i++)
			if(propor < distWithNext.at(i))		//Cogemos al que mayor fracción de decimales le salió
			{
				candidato = i;
				propor = distWithNext.at(i);
			}
		distWithNext.at(candidato) = 0;
		durVertice.at(candidato) += 1;
		durActual++;
	}

		//Tono **************

	//Ahora segun la duracion que nos han dado y los angulos que se forman con las aristas de la figura añadimos notas
	float angle;
	int step;	// El cambio de tono que vamos a hacer.
	Nota* lastNote,* note;
	//La primera nota es el color de la figura (no disponemos de más info)
	lastNote = new Nota(durVertice.at(0), scriabin->getNota(color));
	seg->getSimbolos()->pushBack(lastNote);
	//Ahora el resto de vértices desde 1 a numVertices
	for(int i = 1; i < numVertices; i++)
	{
		angle = angleOf2Lines(vertices.at((i-1)%numVertices)->getPair(), vertices.at(i)->getPair(), vertices.at((i+1)%numVertices)->getPair());
		step = floor(sin(angle)*2); //Como mucho dejamos que de un salto de 3 tonos-Escala (que no semitonos)

		if((step == 3 || step == -3) && durVertice.at(i) > QUARTERNOTE) //Usamos una nota intermedia (lo pide a gritos XD)
		{
			if(durVertice.at(i) > HALFNOTE)
			{
				if(step > 0)
					note = new Nota(QUARTERNOTE, tableScale->nextTone(lastNote->getTono()));
				else
					note = new Nota(QUARTERNOTE, tableScale->prevTone(lastNote->getTono()));
				seg->getSimbolos()->pushBack(note); //añadimos la nota intermedia

				if(step > 0)
					note = new Nota(durVertice.at(i)-QUARTERNOTE, tableScale->nextNTone(lastNote->getTono(),3));
				else
					note = new Nota(durVertice.at(i)-QUARTERNOTE, tableScale->prevNTone(lastNote->getTono(),3));
			}
			else
			{
				if(step > 0)
					note = new Nota(durVertice.at(i)-QUARTERNOTE, tableScale->nextTone(lastNote->getTono()));
				else
					note = new Nota(durVertice.at(i)-QUARTERNOTE, tableScale->prevTone(lastNote->getTono()));
				seg->getSimbolos()->pushBack(note); //añadimos la nota intermedia

				if(step > 0)
					note = new Nota(QUARTERNOTE, tableScale->nextNTone(lastNote->getTono(),3));
				else
					note = new Nota(QUARTERNOTE, tableScale->prevNTone(lastNote->getTono(),3));
			}
		}
		else
		{
			if(step > 0)
				note = new Nota(durVertice.at(i), tableScale->nextNTone(lastNote->getTono(), step));
			else
				note = new Nota(durVertice.at(i), tableScale->prevNTone(lastNote->getTono(), step));
		}

		seg->getSimbolos()->pushBack(note);  //La nota respecto al vertice.
		lastNote = note;
	}
	lastNote = NULL;
	note = NULL;
	delete scriabin;
	scriabin = NULL;

	return true;
}

