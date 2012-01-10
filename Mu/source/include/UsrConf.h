#pragma once

#ifndef USRCONF_H
#define USRCONF_H

#include "Conf.h"

class UsrConf : public Conf
{
    public:
        UsrConf();
        virtual ~UsrConf();
        void read(std::string path);

    protected:
    private:
};

#endif // USRCONF_H
