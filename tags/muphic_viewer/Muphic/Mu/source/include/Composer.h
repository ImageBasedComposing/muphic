#pragma once

#ifndef COMPOSER_H
#define COMPOSER_H

#include <string>
#include "Conf.h"

using namespace std;

class Composer
{
    public:
        Composer();
        virtual ~Composer();

        virtual string compose();
        virtual string compose(string picPath, string usrConfPath);

/*------Getters------*/
        virtual Conf* getConfig();
        virtual string getUsrConfFile();
        virtual string getPic();
        virtual string getTmpMIDIPath();

/*------Setters------*/
        virtual void setConfig(string usrConfFile);          //Leemos el fichero de usuario y modificamos config
        virtual void setUsrConfFile(string f);
        virtual void setPic(string p);
        virtual void setTmpMIDIPath(string m);

    protected:
        string usrConfFile;
        string pic;
        string tmpMIDIPath;

        Conf* config;
    private:
};

#endif // COMPOSER_H
