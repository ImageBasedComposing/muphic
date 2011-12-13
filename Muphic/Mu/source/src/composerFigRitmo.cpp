#include "composerFigRitmo.h"


bool ComposerFigRitmo::compRythmFig(Figura* f, Segmento* seg, int dur)
{
	int t = f->sizeVertices();
	pair<int,int> center;
	center.first = 0;
	center.second = 0;
	int duracionTotal = 0;
	int duracion;

	//Simbolos* ss = seg->getSimbolos();
	Simbolos* simbtmp = new Simbolos();
	Nota* s;

	if(t > 2)
	{
		center = f->getBarycenter();

		// Creación de notas

		Vertice* v;
		int nDiv = 8;
		int * notas = f->radialDivision(nDiv, 90);

		double pownum = 2;
		
		for(int k = 0; k < nDiv; k++)
		{
			if (notas[k] == 0)
			{
				duracion = QUARTERNOTE;
				duracionTotal += duracion;

				s = new Nota(duracion, 0); //silencio si no hay nota en el octante (?)
				simbtmp->pushBack(s);
				continue;
			}

			// Inserto blancas si no hay vertices y por debajo si hay
			duracion = 0;
			
			for(int k1 = 0; k1 < notas[k]; k1++)
			{
				duracion = ((QUARTERNOTE*2)/(int)pow(pownum,notas[k])); 
				duracionTotal += duracion;
				s = new Nota(duracion,getDrumTone(duracion));
				simbtmp->pushBack(s);
			}
		}
	}
	// Para circulos
	else
	{
		center.first = f->getVerticeAt(1)->x;
		center.second = f->getVerticeAt(1)->y;

		int duracion = dur / 4;
		for(int f=0; f < 4; f++)
		{
			duracionTotal += duracion;
			simbtmp->pushBack(new Nota(duracion,getDrumTone(duracion)));
		}
	}


	float factor = 0;
	int rep = 0;
	if (duracionTotal > dur)
	{
		rep = 1;
		factor = dur/ (float) duracionTotal;
	}
	else
	{
		// cuantas repeticiones caben
		rep = dur / duracionTotal;

		// calculamos cuánto hay que modificar el motivo para que las repeticiones sean exactas
		float newDur = ((float) dur / (float) rep);
		factor = newDur / (float) duracionTotal;
	}

	if (factor != 1)
		for (int i = 0; i < simbtmp->size(); i++)
		{
			simbtmp->getAt(i)->setDuracion(simbtmp->getAt(i)->getDuracion()*factor);
		}

	// ahora repetimos el motivo rep veces y ya tira.
	duracionTotal = 0;
	for (int r = 0; r < rep; r++)
	{
		for (int i = 0; i < simbtmp->size(); i++)
		{
			seg->getSimbolos()->pushBack(simbtmp->getAt(i));
			duracionTotal += simbtmp->getAt(i)->getDuracion();
		}
	}

	// como utilizamos factor (float) como entero, quedará un resto por ahí que rezo que no moleste, lo pongo como negra
	if (duracionTotal < dur)
	{
		seg->getSimbolos()->pushBack(new Nota(dur-duracionTotal, getDrumTone(dur-duracionTotal)));
		duracionTotal += dur - duracionTotal;
	}

	return true;
}


int ComposerFigRitmo::getDrumTone(int duracion)
{
	return LA_C; // por ejemplo
}