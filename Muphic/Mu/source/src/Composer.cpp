#include "Composer.h"

Composer::Composer()
{
    //ctor
}

Composer::~Composer()
{
    //dtor
}


string Composer::compose() {}
string Composer::compose(string picPath, string usrConfPath) {}

/*------Getters------*/
Conf* Composer::getConfig() {}
string Composer::getUsrConfFile() {}
string Composer::getPic() {}
string Composer::getTmpMIDIPath() {}

/*------Setters------*/
void Composer::setConfig(string usrConfFile) {}
void Composer::setUsrConfFile(string f) {}
void Composer::setPic(string p) {}
void Composer::setTmpMIDIPath(string m) {}
