#ifndef COMPOSER_H
#define COMPOSER_H

#include "Conf.h"

class Composer
{
    public:
        Composer();
        virtual ~Composer();

        char* compose();
        char* compose(char* picPath, char* usrConfPath);

/*------Getters------*/
        Conf* getConfig();
        char* getUsrConfFile();
        char* getPic();
        char* getTempMIDIPath();

/*------Setters------*/
        void setConfig(char* usrConfFile);          //Leemos el fichero de usuario y modificamos config
        void setUsrConfFile(char* f);
        void setPic(char* p);
        void setTempMIDIPath(char* m);

    protected:

    private:
        char* usrConfFile;
        char* pic;
        char* tempMIDIPath;
        Conf* config;
};

#endif // COMPOSER_H
