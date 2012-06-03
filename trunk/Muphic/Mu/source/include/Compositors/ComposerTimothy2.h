#pragma once

#ifndef COMPOSERTIMOTHY2_H
#define COMPOSERTIMOTHY2_H

#include "Compositors/Composer.h"
#include "Music/Music.h"
#include "Music/FiguresMusic.h"
#include "Compositors/ComposerVoice.h"
#include "Outputs/MidizatorABC.h"
#include "Outputs/MidizatorWAV.h"

class Patterns;
class figuresMusic;

using namespace std;

class ComposerTimothy2 : public Composer
{
    public:
        ComposerTimothy2(ComposerVoice* fm = NULL, ComposerVoice* fm2 = NULL, ComposerVoice* fb = NULL, ComposerVoice* fr = NULL);
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
		//Duración de la obra musical:
		int DURACION;

    private:
		std::list< std::pair<FigureMusic*, int> > calcularDuracion(std::list<FigureMusic*> f);
		bool isLittleFig(FigureMusic* child, FigureMusic* parent);
		Segmento* emptyMelody(Segmento* seg);
		Segmento* emptyMelody(int durTotal);
};

#endif // COMPOSERTIMOTHY2_H
