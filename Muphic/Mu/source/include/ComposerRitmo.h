#pragma once

#ifndef COMPOSERRITMO_H
#define COMPOSERRITMO_H

#include <string>
#include <iostream>
#include <list>
#include <math.h>
#include "Composer.h"
#include "Music.h"
#include "Figuras.h"
#include "PatternGen.h"

class Figuras;

using namespace std;

class ComposerRitmo : public Composer
{
    public:
        ComposerRitmo();
		ComposerRitmo(Music* m);
		ComposerRitmo(Music* m, int numSegmentos);
        virtual ~ComposerRitmo();

        virtual Music* composeMusic();
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
		Music* ritmo;
		int NUMSEGMENTOS;

	private:
		int nota(Figuras* f);
		int getDrumTone(int duracion);
		void sumarArea(list< pair<string,int> >* cs, Figura * f);
		void calcularSegmento(Figura* f, Segmento* segs, Nota* n);
		void calcularPadres(Figura* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos);

};

#endif // COMPOSER_H
