#pragma once

#ifndef COMPOSERTIMOTHY_H
#define COMPOSERTIMOTHY_H

#include "Compositors/Composer.h"
#include "Music/Music.h"
#include "Music/FiguresMusic.h"
#include "Compositors/PatternGen.h"
#include "Compositors/Patterns.h"
#include "Compositors/ComposerVoice.h"
#include "Outputs/MidizatorABC.h"
#include "Outputs/MidizatorWAV.h"

class Patterns;
class figuresMusic;

using namespace std;

class ComposerTimothy : public Composer
{
    public:
        ComposerTimothy(ComposerVoice* fm = NULL, ComposerVoice* fm2 = NULL, ComposerVoice* fb = NULL, ComposerVoice* fr = NULL);
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
		//Duración de la obra musical:
		int DURACION;

    private:
		std::list< std::pair<FigureMusic*, int> > calcularDuracion(std::list<FigureMusic*> f);
};

#endif // COMPOSERTIMOTHY_H
