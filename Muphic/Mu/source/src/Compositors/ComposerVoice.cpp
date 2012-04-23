#include "Compositors/ComposerVoice.h"

ComposerVoice::ComposerVoice(ColorSystem* cs)
{
	this->cs = cs;
}

ComposerVoice::~ComposerVoice()
{
    //dtor
}


string ComposerVoice::composeVoice() { return NULL; }
