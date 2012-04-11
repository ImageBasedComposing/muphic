#pragma once

#ifndef COMPOSERTIMOTHY2_H
#define COMPOSERTIMOTHY2_H

#include "Compositors/Composer.h"
#include "Music/Music.h"
#include "Music/FiguresMusic.h"
#include "Compositors/PatternGen.h"
#include "Compositors/Patterns.h"
#include "Compositors/ComposerFigMelody2.h"
#include "Compositors/ComposerFigBass2.h"
#include "Compositors/ComposerFigRitmo2.h"
#include "Outputs/MidizatorABC.h"
#include "Outputs/MidizatorWAV.h"

class Patterns;
class figuresMusic;

using namespace std;

class ComposerTimothy2 : public Composer
{
    public:
        ComposerTimothy2();
        virtual ~ComposerTimothy2();

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
		int DURACION;

        Conf* config;

    private:
		std::list< std::pair<FigureMusic*, int> > calcularDuracion(std::list<FigureMusic*> f);
		bool isLittleFig(FigureMusic* child, FigureMusic* parent);
};

#endif // COMPOSERTIMOTHY2_H
