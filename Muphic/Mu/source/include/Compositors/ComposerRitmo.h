#pragma once

#ifndef COMPOSERRITMO_H
#define COMPOSERRITMO_H

#include <string>
#include <iostream>
#include <list>
//#include "math_functions.h"
#include "Compositors/Composer.h"
#include "Music/Music.h"
#include "Music/FiguresMusic.h"
#include "Compositors/PatternGen.h"

class FiguresMusic;

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
		FiguresMusic* figuras;
		Music* ritmo;
		int NUMSEGMENTOS;

	private:
		int nota(FiguresMusic* f);
		int getDrumTone(int duracion);
		void sumarArea(list< pair<Color,int> >* cs, FigureMusic * f);
		void calcularSegmento(FigureMusic* f, Segmento* segs, Nota* n);
		void calcularPadres(FigureMusic* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos);

};

#endif // COMPOSER_H
