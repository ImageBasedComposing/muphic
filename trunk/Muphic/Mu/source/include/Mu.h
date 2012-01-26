#pragma once

#ifndef MU_H
#define MU_H

#include "UsrConf.h"
#include "Compositors/Composer.h"

#include <string>
#include <iostream>

using namespace std;

class Mu
{
    public:
        Mu();
        virtual ~Mu();

    protected:

        UsrConf* usrConf;
        Composer* composer;

    private:

};

#endif // Mu_H
