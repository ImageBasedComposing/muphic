#pragma once

#ifndef ANALIZER__H
#define ANALIZER__H

#include "cv.h"
#include "highgui.h"

#include "Figuras.h"
#include "FigureImg.h"

class Analizer
{
	protected:
		void setColorFromImage(Figura* f, IplImage* g_image, CvSeq* c, IplImage* maskAcum, bool inv, bool all);

	public:

		bool debug;
		int lastID;

		Analizer();
		~Analizer();


		IplImage* analizeByFilter(IplImage* imagesrc, int filter, int threshold = -1);
		void analizePerRegions(IplImage* imagesrc, int levels, IplImage** &images, int& nimages);

		void addFiguresfromPics(IplImage* img, IplImage* *mask, int nmasks, Figuras* figuras, int polSimp, int noise);
		void addFiguresfromPic(IplImage* img, IplImage* mask, Figuras* figuras, int polSimp, int noise);
};


#endif // ANALIZER__H

