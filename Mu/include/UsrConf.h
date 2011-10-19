#ifndef USRCONF_H
#define USRCONF_H

#include "Conf.h"

class UsrConf: public Conf
{
    public:
        UsrConf();
        virtual ~UsrConf();
        void read();
    protected:
    private:
};

#endif // USRCONF_H
