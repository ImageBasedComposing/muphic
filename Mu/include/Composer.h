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

        string compose();
        string compose(string picPath, string usrConfPath);

/*------Getters------*/
        Conf* getConfig();
        string getUsrConfFile();
        string getPic();
        string getTempMIDIPath();

/*------Setters------*/
        void setConfig(string usrConfFile);          //Leemos el fichero de usuario y modificamos config
        void setUsrConfFile(string f);
        void setPic(string p);
        void setTempMIDIPath(string m);

    protected:

    private:
        string usrConfFile;
        string pic;
        string tempMIDIPath;
        Conf* config;
};

#endif // COMPOSER_H
