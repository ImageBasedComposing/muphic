#include "composerFigRitmo.h"


bool ComposerFigRitmo::compMelodyFig(Figura* f, Segmento* seg, int dur)
{
	int t = f->sizeVertices();
	pair<int,int> center;
	center.first = 0;
	center.second = 0;

	Simbolos* ss = seg->getSimbolos();
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
				s = new Nota((QUARTERNOTE*2)/(int)pow(pownum,notas[k]),getDrumTone(duracion));
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

		int duracion = 0;
		for(int f=0; f < 4; f++)
		{
			ss->pushBack(new Nota(duracion,getDrumTone(duracion)));
		}
		seg->setSimbolos(ss);
	}

	return true;
}


int ComposerFigRitmo::getDrumTone(int duracion)
{
	return LA; // por ejemplo
}