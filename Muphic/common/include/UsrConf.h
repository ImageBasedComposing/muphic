#pragma once

#ifndef USRCONF_H
#define USRCONF_H

#include <string>
#include "tinyxml.h"
#include "aux_functions.h"
//#include "Conf.h"

class UsrConf/* : public Conf*/
{
    public:
        UsrConf();
        virtual ~UsrConf();
        void read(std::string path);
		
		// read
		// MUPHIC
		void readMuphic(std::string path);
			// PHIC
			void readPhic(std::string path);
			// MU
			void readMu(std::string path);

		// getters
		// MUPHIC
			// PHIC
			bool getPhicActive();
			bool getPhicDebug();
            int  getPhicFilterSelect();
			// MU
			bool getMuActive();

        // write
        void write(std::string path);

        // setters
        // MUPHIC
                // PHIC
                void setPhicActive(bool b);
                void setPhicDebug(bool b);
                void setPhicFilterSelect(int fn);
                // MU
                void setMuActive(bool b);

    protected:
		// MUPHIC
			// PHIC
			bool phicActive;
			bool phicDebug;
            int  phicFilterSelec;
			// MU
			bool muActive;
    private:
};

#endif // USRCONF_H
