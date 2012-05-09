#include "Compositors/ComposerMultiple.h"
#include "Compositors/ComposerMelodia.h"

ComposerMultiple::ComposerMultiple(): Composer()
{
    //ctor
}

ComposerMultiple::ComposerMultiple(Music* m): Composer()
{
	musica = m;
}

ComposerMultiple::~ComposerMultiple()
{
    //dtor
}

string ComposerMultiple::compose()
{
	ComposerRitmo* cr = new ComposerRitmo(musica,NUMSEGMENTOS);
	cr->setPic(pic);
	cr->setUsrConfFile(usrConfFile);
	musica = cr->composeMusic();

	ComposerMelodia* cr1 = new ComposerMelodia(musica,NUMSEGMENTOS);
	cr1->setPic(pic);
	cr1->setUsrConfFile(usrConfFile);
	musica = cr1->composeMusic();

	return musica->toMidi();
}

string ComposerMultiple::compose(string picPath, string usrConfPath)
{
	setPic(picPath);
	setUsrConfFile(usrConfPath);

	return compose();
}

/*------Getters------*/
Conf* ComposerMultiple::getConfig()
{
	return config;
}

string ComposerMultiple::getUsrConfFile()
{
	return usrConfFile;
}

string ComposerMultiple::getPic()
{
	return pic;
}

string ComposerMultiple::getTmpMIDIPath()
{
	return tmpMIDIPath;
}

/*------Setters------*/
void ComposerMultiple::setConfig(string c)
{
	config->read(c);
}

void ComposerMultiple::setUsrConfFile(string f)
{
	usrConfFile = f;
}

void ComposerMultiple::setPic(string p)
{
	pic = p;
}

void ComposerMultiple::setTmpMIDIPath(string m)
{
	tmpMIDIPath = m;
}
