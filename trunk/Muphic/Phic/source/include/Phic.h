#ifndef PHIC_H
#define PHIC_H

#include <iostream>

#include "cv.h"
#include "highgui.h"

#include "Figuras.h"
#include "FigureImg.h"
#include "UsrConf.h"
#include "aux_functions.h"

using namespace cv;
using namespace std;

class Phic
{
    public:
        Phic();
        virtual ~Phic();

		static UsrConf* usrConf;

		void test();
		static void setColorFromImage(Figura* f, IplImage* g_image, CvSeq* c, IplImage* maskAcum, bool inv, bool all);
		static void on_trackbar(int);

		void setUsrConfPath(std::string p);
		void setPicPath(std::string p);

	protected:

		static int g_thresh;
		static IplImage* g_image;
		static int filtro;
		static int noise;
		static int polSimp;

		static std::string picPath;
		std::string usrConfPath;

    private:

};

int Phic::g_thresh = 50;
IplImage* Phic::g_image = NULL;
int Phic::filtro = 2;
int Phic::noise = 50;
int Phic::polSimp = 2;
UsrConf* Phic::usrConf = NULL;
std::string Phic::picPath = "";

#endif // PHIC_H
