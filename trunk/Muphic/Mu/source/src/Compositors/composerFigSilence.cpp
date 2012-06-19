#include "Compositors/composerFigSilence.h"

/*------Constructoras------*/
ComposerFigSilence::ComposerFigSilence(ColorSystem* cs) : ComposerVoice(cs)
{
	// ctor
	typeScale = 7;
}

ComposerFigSilence::ComposerFigSilence(ColorSystem* cs, TableScale* tbScale) : ComposerVoice(cs, tbScale)
{
	// ctor
	typeScale = 7;
}

/*------Destructora------*/
ComposerFigSilence::~ComposerFigSilence()
{
	//// dtor
}

//Hacemos una melodia de duracion limitada y que sea a partir de la figura dada.
bool ComposerFigSilence::compSilence(Segmento* seg, int dur)
{
	int durTotal;
	durTotal = dur;
	while(durTotal > WHOLE)
	{
		seg->pushBack(new Nota(WHOLE, 0));
		durTotal = durTotal - WHOLE;
	}
	if(durTotal > 0)
		seg->pushBack(new Nota(durTotal, 0));

	return true;
}

