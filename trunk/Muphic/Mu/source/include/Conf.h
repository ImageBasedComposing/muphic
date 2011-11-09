#pragma once

#ifndef CONF_H
#define CONF_H

#include <string>

using namespace std;

class Conf
{
    public:
        Conf();
        virtual ~Conf();

        virtual void read(std::string path);

    protected:
    private:
};

#endif // CONF_H
