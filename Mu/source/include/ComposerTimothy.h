#pragma once

#ifndef COMPOSERTIMOTHY_H
#define COMPOSERTIMOTHY_H

#include "Composer.h"
#include "Music.h"
#include "FiguresMusic.h"
#include "PatternGen.h"
#include "Patterns.h"
#include "ComposerFigMelody.h"
#include "ComposerFigRitmo.h"
#include "MidizatorABC.h"
#include "MidizatorWAV.h"

class Patterns;
class figuresMusic;

using namespace std;

class ComposerTimothy : public Composer
{
    public:
        ComposerTimothy();
        virtual ~ComposerTimothy();

        string compose();
        string compose(string picPath, string usrConfPath);

/*------Getters------*/
        Conf* getConfig();
        string getUsrConfFile();
        string getPic();
        string getTmpMIDIPath();

/*------Setters------*/
        void setConfig(string usrConfFile);          //Leemos el fichero de usuario y modificamos config
        void setUsrConfFile(string f);
        void setPic(string p);
        void setTmpMIDIPath(string m);

    protected:
        string usrConfFile;
        string pic;
        string tmpMIDIPath;

		//Duración de la obra musical:
		static const int DURACION = WHOLE*4;

        Conf* config;

    private:
		std::list< std::pair<FigureMusic*, int> > calcularDuracion(std::list<FigureMusic*> f);
};

#endif // COMPOSERTIMOTHY_H
