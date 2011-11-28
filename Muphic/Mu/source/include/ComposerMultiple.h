#pragma once

#ifndef COMPOSERMULTIPLE_H
#define COMPOSERMULTIPLE_H

#include <string>
#include <iostream>
#include <list>
#include <math.h>
#include "Composer.h"
#include "Music.h"
#include "Figuras.h"
#include "PatternGen.h"
#include "ComposerRitmo.h"

class ComposerRitmo;
class Figuras;

using namespace std;

class ComposerMultiple : public Composer
{
    public:
        ComposerMultiple();
		ComposerMultiple(Music* m);
        virtual ~ComposerMultiple();

        virtual string compose();
        virtual string compose(string picPath, string usrConfPath);

/*------Getters------*/
        virtual Conf* getConfig();
        virtual string getUsrConfFile();
        virtual string getPic();
        virtual string getTmpMIDIPath();

/*------Setters------*/
        virtual void setConfig(string c);          //Leemos el fichero de usuario y modificamos config
        virtual void setUsrConfFile(string f);
        virtual void setPic(string p);
        virtual void setTmpMIDIPath(string m);

    protected:
		Figuras* figuras;
		Music* musica;
		ComposerRitmo* cr;

		static const int NUMSEGMENTOS = 20;

	private:
};

#endif // COMPOSERMULTIPLE_H
