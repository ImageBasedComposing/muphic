#include "Composer.h"

Composer::Composer()
{
    //ctor
}

Composer::~Composer()
{
    //dtor
}


string Composer::compose() { return NULL; }
string Composer::compose(string picPath, string usrConfPath) { return NULL; }

/*------Getters------*/
Conf* Composer::getConfig() { return NULL; }
string Composer::getUsrConfFile() { return NULL; }
string Composer::getPic() { return NULL; }
string Composer::getTmpMIDIPath() { return NULL; }

/*------Setters------*/
void Composer::setConfig(string usrConfFile) {}
void Composer::setUsrConfFile(string f) {}
void Composer::setPic(string p) {}
void Composer::setTmpMIDIPath(string m) {}
