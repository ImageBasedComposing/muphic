#ifndef MU_H
#define MU_H

#include "UsrConf.h"
#include "Composer.h"

#include <string>

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
