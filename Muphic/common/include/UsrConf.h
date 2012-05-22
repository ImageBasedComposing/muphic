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
            int  getPhicThresholdSelec();
            int  getPhicPolygonSimp();
			int  getPhicAnalysisDetail();
            int  getPhicNoiseSelec();
            int  getPhicColorLevels();
            int  getPhicThresholdH();
            int  getPhicThresholdS();
            int  getPhicThresholdV();
			// MU
			bool getMuActive();
			bool getMuDebug();
			int getMuCompMix();
			int getMuCompVoice1();
			int getMuCompVoice2();
			int getMuCompVoice3();
			int getMuCompVoice4();
			int getMuInstrVoice1();
			int getMuInstrVoice2();
			int getMuInstrVoice3();
			int getMuInstrVoice4();
			int getMuReconColors();
			int getMuTempo();
            std::string getMuOutputFile();

        // write
        void write(std::string path);

        // setters
        // MUPHIC
            // PHIC
            void setPhicActive(bool b);
            void setPhicDebug(bool b);
            void setPhicFilterSelect(int fn);
            void setPhicThresholdSelec(int t);
            void setPhicPolygonSimp(int i);
			void setPhicAnalysisDetail(int i);
            void setPhicNoiseSelec(double n);
            void setPhicColorLevels(int c);
            void setPhicThresholdH(int t);
            void setPhicThresholdS(int t);
            void setPhicThresholdV(int t);
            // MU
            void setMuActive(bool b);
			void setMuDebug(bool b);
			void setMuCompMix(int c);
			void setMuCompVoice1(int c);
			void setMuCompVoice2(int c);
			void setMuCompVoice3(int c);
			void setMuCompVoice4(int c);
			void setMuInstrVoice1(int i);
			void setMuInstrVoice2(int i);
			void setMuInstrVoice3(int i);
			void setMuInstrVoice4(int i);
			void setMuReconColors(int cs);
			void setMuTempo(int t);
            void setMuOutputFile(std::string o);

    protected:
		// MUPHIC
			// PHIC
			bool phicActive;
			bool phicDebug;
            int  phicFilterSelec;
            int  phicThresholdSelec;
            int  phicPolygonSimp;
			int  phicAnalysisDetail;
            double  phicNoiseSelec;
            int  phicColorLevels;
            int  phicThresholdH;
            int  phicThresholdS;
            int  phicThresholdV;
			// MU
			bool muActive;
            bool muDebug;
			int muCompMix;
			int muCompVoice1;
			int muCompVoice2;
			int muCompVoice3;
			int muCompVoice4;
			int muInstrVoice1;
			int muInstrVoice2;
			int muInstrVoice3;
			int muInstrVoice4;
			int muReconColors;
			int muTempo;
            std::string muOutputFile;

    private:
};

#endif // USRCONF_H
