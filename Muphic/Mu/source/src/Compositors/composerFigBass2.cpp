#include "Compositors/ComposerFigBass2.h"

/*------Constructoras------*/
ComposerFigBass2::ComposerFigBass2()
{
	// ctor
}

ComposerFigBass2::ComposerFigBass2(TableScale* tbScale)
{
	tableScale = tbScale;
}

/*------Destructora------*/
ComposerFigBass2::~ComposerFigBass2()
{
	//// dtor
	//delete tableScale;
	//tableScale = NULL;
}

//Hacemos un bajo que respete las normas del contrapunto en cierta medida.
bool ComposerFigBass2::compBassFig(Segmento* seg1, Segmento* seg2, Segmento* seg3, int maxDur, int minDur)
{
	int duracionTotal = 0;
	int dur = seg1->getDuration();

	Simbolos* simbtmp = new Simbolos();

	while (duracionTotal < dur)
	{
		if((dur - duracionTotal) < maxDur)
		{
			simbtmp->pushBack(new Nota(dur - duracionTotal, SILENCIO));
			duracionTotal += dur - duracionTotal;
		}
		else
		{
			simbtmp->pushBack(new Nota(maxDur, SILENCIO));
			duracionTotal += maxDur;
		}
		
	}

	int numNotes = simbtmp->size();
	int addedNotes = 0;


	Nota* n1,* n2;
	int pos1 = 0, pos2 = 0;
	int i = 1;
	int temp1 = 0, temp2 = 0;

	n1 = (Nota*)seg1->getAt(pos1);
	pos1++;
	temp1 += n1->getDuracion();
	n2 = (Nota*)seg2->getAt(pos2);
	pos2++;
	temp2 += n2->getDuracion();

	for(int i = 0; i < numNotes; i++)
	{
		tableScale->getToneDegree(1);
	}

	return true;
}

//Hacemos un bajo simple que se basa en coger el color de la figura (y por tanto su función armónica)
bool ComposerFigBass2::compBassFig(FigureMusic* f, int dur, Segmento* seg3, int maxDur, int minDur)
{
	int duracionTotal = 0;

	Simbolos* simbtmp = new Simbolos();

	Scriabin sc;
	int tonebass = (sc.getNota(f->getRGB(), tableScale) % ESCALA) + ESCALA;

	while (duracionTotal < dur)
	{
		if((dur - duracionTotal) < maxDur)
		{
			simbtmp->pushBack(new Nota(dur - duracionTotal, tonebass));
			duracionTotal += dur - duracionTotal;
		}
		else
		{
			simbtmp->pushBack(new Nota(maxDur, tonebass));
			duracionTotal += maxDur;
		}
		
	}

	seg3->setSimbolos(simbtmp);

	return true;
}