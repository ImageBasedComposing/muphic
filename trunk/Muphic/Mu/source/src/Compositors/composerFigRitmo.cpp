#include "Compositors/ComposerFigRitmo.h"

/*------Constructoras------*/
ComposerFigRitmo::ComposerFigRitmo(ColorSystem* sc) : ComposerVoice(sc)
{
	// ctor
}

ComposerFigRitmo::ComposerFigRitmo(ColorSystem* sc, TableScale* tbScale) : ComposerVoice(sc, tbScale)
{
	// ctor
}

/*------Destructora------*/
ComposerFigRitmo::~ComposerFigRitmo()
{
	//// dtor
}

bool ComposerFigRitmo::compRythmFig(FigureMusic* f, Segmento* seg, int dur, int compas, bool quick)
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

		int * notas = f->radialDivision(compas, 90);

		double pownum = 2;

		for(int k = 0; k < compas; k++)
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
				s = new Nota(duracion,getDrumTone());
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
			simbtmp->pushBack(new Nota(duracion,getDrumTone()));
		}
	}


	float factor = 0;
	int rep = 0;
	if (!quick || (duracionTotal > dur))
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
			if(simbtmp->getAt(i)->getDuracion() > 0){
				seg->pushBack(simbtmp->getAt(i));
				duracionTotal += simbtmp->getAt(i)->getDuracion();
			}
		}
	}

	// como utilizamos factor (float) como entero, quedará un resto por ahí que rezo que no moleste, lo pongo como negra
	if (duracionTotal < dur)
	{
		seg->pushBack(new Nota(dur-duracionTotal, 0));
		duracionTotal += dur - duracionTotal;
	}

	return true;
}


int ComposerFigRitmo::getDrumTone()
{
	return instruments.front();
}
