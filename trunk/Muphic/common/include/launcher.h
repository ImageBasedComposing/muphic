#pragma once

#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <string>
#include <stdlib.h>
#include <stdio.h>

#ifdef __LINUX
    #include <unistd.h>
    #include <sys/wait.h>
#endif

using namespace std;


enum Options {NONE};

class Launcher
{
    public:
        Launcher();
        virtual ~Launcher();

        void launch(int argc, string argv[], Options options = NONE);

    protected:
    private:
};

#endif // LAUNCHER_H