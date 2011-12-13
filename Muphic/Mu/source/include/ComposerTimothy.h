#pragma once

#ifndef COMPOSERTIMOTHY_H
#define COMPOSERTIMOTHY_H

#include "Composer.h"
#include "Music.h"
#include "Figuras.h"
#include "PatternGen.h"
#include "Patterns.h"
#include "ComposerFigMelody.h"
#include "ComposerFigRitmo.h"
#include "MidizatorABC.h"

class Patterns;

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

		static const int DURACION = WHOLE*4;

        Conf* config;

    private:
		std::list< std::pair<Figura*, int> > calcularDuracion(std::list<Figura*> f);
};

#endif // COMPOSERTIMOTHY_H
