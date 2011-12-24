#pragma once

#ifndef COMPOSERRITMO_H
#define COMPOSERRITMO_H

#include <string>
#include <iostream>
#include <list>
//#include "math_functions.h"
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
		ComposerRitmo(Music* m, int numSegmentos = 20);
        virtual ~ComposerRitmo();

        Music* composeMusic();
		string compose();
        string compose(string picPath, string usrConfPath);

/*------Getters------*/
        Conf* getConfig();
        string getUsrConfFile();
        string getPic();
        string getTmpMIDIPath();

/*------Setters------*/
        void setConfig(string c);          //Leemos el fichero de usuario y modificamos config
        void setUsrConfFile(string f);
        void setPic(string p);
        void setTmpMIDIPath(string m);

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
