#pragma once

#ifndef COMPOSERMELODIA_H
#define COMPOSERMELODIA_H

#include <string>
#include <iostream>
#include <list>
//#include "math_functions.h"
#include "limits.h"
#include "Compositors/Composer.h"
#include "Music/Music.h"
#include "Music/FiguresMusic.h"
#include "Compositors/PatternGen.h"

#include "Compositors/ComposerFigMelody.h"

class FiguresMusic;

using namespace std;

class ComposerMelodia : public Composer
{
    public:
        ComposerMelodia();
		ComposerMelodia(Music* m, int numSegmentos = 20);
        virtual ~ComposerMelodia();

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
		Music* melodia;
		int NUMSEGMENTOS;

	private:
		void calcularMelodiaFig(FigureMusic* f, Segmento* seg, Nota* n);
		int calcTono(float angulo, Nota* nPpal);
		int calcDur(double longMedia, double longitud);
		int notaFigura(FigureMusic* f);
		void sumarArea(list< pair<Color,int> >* cs, FigureMusic* f);
		void calcularPadres(FigureMusic* f, list< pair<Segmento*,int> > segs, int nsegmentos, list< pair<Segmento*,int> >* segmentos);


		// tmp shit
		int calcularNota(double angulo, int* escala);
};

#endif // COMPOSERMELODIA_H