#include "Compositors/ComposerFigBass2.h"

/*------Constructoras------*/
ComposerFigBass2::ComposerFigBass2(ColorSystem* sc) : ComposerVoice(sc)
{
	// ctor
	typeScale = 7;
}

ComposerFigBass2::ComposerFigBass2(ColorSystem* sc, TableScale* tbScale) : ComposerVoice(sc, tbScale)
{
	// ctor
	typeScale = 7;
}

/*------Destructora------*/
ComposerFigBass2::~ComposerFigBass2()
{
	//// dtor
}

//Hacemos un bajo que respete las normas del contrapunto en cierta medida.
//Sin terminar
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
		tb->getToneDegree(1);
	}

	return true;
}

//Hacemos un bajo simple que se basa en coger el color de la figura (y por tanto su función armónica)
bool ComposerFigBass2::compBassFig(FigureMusic* f, Segmento* seg3, int dur, int maxDur, int minDur)
{
	int duracionTotal = 0;

	Simbolos* simbtmp = new Simbolos();

	int tonebass = (cs->getNota(f->getRGB(), tb) % ESCALA) + ESCALA;

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

bool ComposerFigBass2::composeVoice(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur, Segmento* seg1)
{
	return compBassFig(f,seg,dur,maxDur,minDur);
}