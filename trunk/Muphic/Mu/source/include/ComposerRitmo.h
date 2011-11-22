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
        virtual ~ComposerRitmo();

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
		static const int NUMSEGMENTOS = 20;
  
	private:
		int nota(Figuras* f);
		void sumarArea(list<pair<string,int>>* cs, Figura * f);
		void calcularSegmento(Figura* f, Segmento* segs, Nota* n);
		void calcularPadres(Figura* f, list<pair<int,Segmento*>> segs, int nsegmentos, list<pair<int,Segmento*>>* segmentos);

};

#endif // COMPOSER_H
