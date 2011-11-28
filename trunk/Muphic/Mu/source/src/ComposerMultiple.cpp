#include "ComposerMultiple.h"

ComposerMultiple::ComposerMultiple()
{
    //ctor
}

ComposerMultiple::ComposerMultiple(Music* m)
{
	musica = m;
}

ComposerMultiple::~ComposerMultiple()
{
    //dtor
}

string ComposerMultiple::compose()
{
	cr = new ComposerRitmo(musica);
	cr->setPic(pic);
	cr->setUsrConfFile(usrConfFile);
	musica = cr->composeMusic();

	ComposerRitmo* cr2 = new ComposerRitmo(musica);
	cr2->setPic(pic);
	cr2->setUsrConfFile(usrConfFile);
	musica = cr->composeMusic();

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
