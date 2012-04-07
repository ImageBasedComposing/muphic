#ifndef PHIC_H
#define PHIC_H

#include <iostream>

#include "cv.h"
#include "highgui.h"

#include "Figuras.h"
#include "FigureImg.h"
#include "UsrConf.h"
#include "aux_functions.h"

#include "Analizer.h"

using namespace cv;
using namespace std;

class Phic
{
    public:
        Phic();
        virtual ~Phic();

		static UsrConf* usrConf;

		void setUsrConfPath(std::string p);
		void setPicPath(std::string p);

	protected:

		static std::string picPath;
		std::string usrConfPath;

    private:

};

UsrConf* Phic::usrConf = NULL;
std::string Phic::picPath = "";

#endif // PHIC_H
