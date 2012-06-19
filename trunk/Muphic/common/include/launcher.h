#pragma once

#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <string>
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>


#ifdef __WINDOWS
    #include <windows.h>
    #include <signal.h>
	#include <vector>
#endif

#ifdef __LINUX
    #include <unistd.h>
    #include <sys/wait.h>
    #include <signal.h>
#endif



class Launcher
{
    public:

		enum Program{MUPHIC, MU, PHIC, QMAKE, ABC2MIDI, MPLAYER, TIMIDITY, ABC2PS};
		enum Options {NONE};

        Launcher();
        virtual ~Launcher();

		void launch(int argc, std::string argv[], Options options = NONE);
        void launch(int argc, Program pname, std::string argv[], Options options = NONE);

		int launchAndGo(int argc, std::string argv[], Options options = NONE);
		int launchAndGo(int argc, Program pname, std::string argv[], Options options = NONE);

		bool killProcess(int pid);

    protected:

    private:

		void add_strtoarray(char ***str_array, int *num_elements, const char *my_string);
		std::string parseConfFile(std::string file, Program pname);
};

#endif // LAUNCHER_H
