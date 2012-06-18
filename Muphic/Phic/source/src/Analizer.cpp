#include "Analizer.h"

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"

Analizer::Analizer()
{
    debug = true;
	lastID = 0;
}

Analizer::~Analizer()
{
    //dtor
}

void Analizer::analizeHSV(IplImage* imagesrc, IplImage** &images, int & nimages, int thresholdH, int thresholdS, int thresholdV)
{
	// Create image Data
	CvMemStorage* g_storage = cvCreateMemStorage(0);
	IplImage* hsvImage = cvCreateImage( cvGetSize( imagesrc ), 8, 3 );
	IplImage* hImage = cvCreateImage( cvGetSize( imagesrc ), 8, 1 );
	IplImage* sImage = cvCreateImage( cvGetSize( imagesrc ), 8, 1 );
	IplImage* vImage = cvCreateImage( cvGetSize( imagesrc ), 8, 1 );

	cvCvtColor( imagesrc, hsvImage , CV_BGR2HSV);  

	cvSplit(hsvImage, hImage, sImage, vImage, NULL);

	cvThreshold( hImage, hImage, thresholdH, 255, CV_THRESH_BINARY );
	cvThreshold( sImage, sImage, thresholdS, 255, CV_THRESH_BINARY );
	cvThreshold( vImage, vImage, thresholdV, 255, CV_THRESH_BINARY );


	if (debug)
	{
		// We show the resulting image from apliying the filter
		cvShowImage( "Contours", hImage );
		cvWaitKey();
		cvShowImage( "Contours", sImage );
		cvWaitKey();
		cvShowImage( "Contours", vImage );
		cvWaitKey();
	}

	images = new IplImage*[3];
	images[0] = hImage;
	images[1] = sImage;
	images[2] = vImage;
	nimages = 3;
}

void Analizer::analizePerRegions(IplImage* imagesrc, int levels, IplImage** &images, int & nimages)
{
	// create all binary images
	IplImage* ***regionCube = new IplImage***[levels];
	for (int i = 0; i < levels; i++)
	{
		regionCube[i] = new IplImage**[levels];
		for (int j = 0; j < levels; j++)
		{
			regionCube[i][j] = new IplImage*[levels];
			for (int k = 0; k < levels; k++)
			{
				regionCube[i][j][k] = cvCreateImage(cvGetSize(imagesrc),IPL_DEPTH_8U,1);
				cvZero( regionCube[i][j][k] );
			}

		}
	}
	
	// fill image-cube with regions
	CvScalar p;
	int r, g, b;
	double delta = 256 / (double) levels;
	for (int i = 0; i < imagesrc->height; i++)
		for (int j = 0; j < imagesrc->width; j++)
		{
			p = cvGet2D(imagesrc, i, j);

			r = (int) p.val[2] / delta;
			g = (int) p.val[1] / delta;
			b = (int) p.val[0] / delta;


			p.val[0] = 255;
			cvSet2D(regionCube[r][g][b], i, j, p);
		}


	// show & save 'em
	images = new IplImage*[levels*levels*levels];
	nimages = 0;

	CvFont font;
	cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, 0.325,0.325,0,1);
	char titler[50], titleg[50], titleb[50];
	for (int i = 0; i < levels; i++)
		for (int j = 0; j < levels; j++)
			for (int k = 0; k < levels; k++)
			{	
 
				cvShowImage("regions", regionCube[i][j][k]);

				if (debug)
					cvWaitKey();

				images[nimages++] = regionCube[i][j][k];
			}
}

IplImage* Analizer::analizeByFilter(IplImage* imagesrc, int filter, int threshold)
{
	// Create image Data
	IplImage* mask = cvCreateImage( cvGetSize( imagesrc ), 8, 1 );
	CvMemStorage* g_storage = cvCreateMemStorage(0);
	cvCvtColor( imagesrc, mask, CV_BGR2GRAY );

	// We choose the filter we will be using
	switch(filter)
	{
		case 1:
			cvAdaptiveThreshold( mask, mask, double(255), CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 3, 3 );
			break;
		case 0:
			cvThreshold( mask, mask, threshold, 255, CV_THRESH_BINARY );
			break;
		case 2:
			cvCanny( mask, mask, 1.0, 1.0, 3);
			break;
		default:
			cvCanny( mask, mask, 1.0, 1.0, 3);
			break;
	}

	if (debug)
	{
		// We show the resulting image from apliying the filter
		cvShowImage( "Contours", mask );
		cvWaitKey();
	}

	return mask;
}

// f is the figure which we want to color
// g_image is the source image
// c is de contour of the figure
// inv determines if we consider the inside or the outside of the figure
// all determines if we consider the current contour (false) or all of the remaining (true)
void Analizer::setColorFromImage(Figura* f, IplImage* g_image, CvSeq* c, IplImage* maskAcum, IplImage* maskHoles, bool inv, bool all)
{
	IplImage* mask = cvCreateImage( cvGetSize( g_image ), 8, 1 );
	cvZero( mask );

	int howMany = 0;
	if (all)
		howMany = 1;

	// if there are no contours, we use the mask given
	if (c == NULL)
		mask = maskAcum;
	else
	{
		cvDrawContours( mask, c, CV_RGB(250,0,250), CV_RGB(0,0,0), 0, -1, 8 );

		if (maskHoles != NULL)
		{
			IplImage* tmp1 = cvCreateImage( cvGetSize( g_image ), 8, 1 );
			IplImage* tmp2 = cvCreateImage( cvGetSize( g_image ), 8, 1 );
			cvSub(mask, maskHoles, mask);	

		}
	}

	// show image (inv if asked)
	if (inv)
	{
		cvNot( mask, mask );
		if (debug)
			cvShowImage( "Contours", mask );

	}
	else
	{
		if (debug)
			cvShowImage( "Contours", mask );
	}

	if (debug)
		cvWaitKey();

	CvScalar s, stmp;
	cv::Vec3b test;
	int r, g, b, num;

	r = g = b = 0;
	num = 0;
	for (int i = 0; i < mask->height; i++)
	{
		for (int j = 0; j < mask->width; j++)
		{
			s = cvGet2D(mask,i, j);

			if ((s.val[0] == 0) != inv)
				continue;
			

			s = cvGet2D(g_image, i, j);

			r += s.val[2];
			
			g += s.val[1];

			b += s.val[0];

			num++;
		}
	}
	f->setRGB(r/num, g/num, b/num);
}


void Analizer::addFiguresfromPics(IplImage* img, IplImage* *mask, int nmasks, Figuras* figuras, int polSimp, int noise)
{
	for (int i = 0; i < nmasks; i++)
	{
		addFiguresfromPicv2(img, mask[i], figuras, polSimp, noise);
	}
}


void Analizer::addFiguresfromPicv2(IplImage* img, IplImage* mask, Figuras* figuras, int polSimp, int noise)
{
	// useful data
	CvSeq* contours = NULL;
	CvMemStorage* g_storage = cvCreateMemStorage(0);
	IplImage* g_contours = cvCreateImage( cvGetSize(img), 8, 3 );
	IplImage* previousshapes = cvCreateImage( cvGetSize( img ), 8, 1 );
	IplImage* curcontour = cvCreateImage( cvGetSize( img ), 8, 1 );
	//cvSet(previousshapes, cvScalar(0));
	cvZero(previousshapes);
	cvZero(curcontour);
	CvScalar red = CV_RGB(250,0,0);
	CvScalar blue = CV_RGB(0,250,250);

	// look for image contours
	cvFindContours( mask, g_storage, &contours, sizeof(CvContour), CV_RETR_TREE);

	if( contours )
	{
		//convert the pixel contours to line segments in a polygon.
		CvSeq* first_polygon = cvApproxPoly(contours, sizeof(CvContour), g_storage, CV_POLY_APPROX_DP, polSimp, 2);

		CvSeq* cAux = contours;
		double area;


		// iterate contours and create a figure for each one
		FigureImg* f;
		int currentmaxsize = MAX_SIZE;

		Vertice* staticfigure = new Vertice[currentmaxsize];//  static aux Figure
		int nstaticfigure;
		int id = 0;

		CvSeq* currentson;

		currentson = first_polygon;
		// down till the end
		while (currentson->v_next) currentson = currentson->v_next;

		while (currentson != NULL)
		{
			// iterate and duh
			nstaticfigure = 0;
			cvZero( g_contours );
			cvDrawContours(
				g_contours,
				currentson,
				red,			// Red
				red,			// Blue
				3,				// Vary max_level and compare results
				0,//CV_FILLED,//1,
				8 );


			if (debug)
			{
				printf( "New Contour with %d elements:\n", currentson->total );
			}

			// Calculamos el area de cada poligono
			area = cvContourArea(currentson);
			if (debug)
				printf("Area: %f\n", area);
				
			//
			double areapropr = area * 100 / (figuras->getWidth() * figuras->getHeight());
				
			if(cAux!=NULL) //Cogemos el siguiente para la siguiente vuelta (es como un do-while)
				cAux = cAux->h_next;
			

			// We set an area filter to skip noise figures
			if (!((currentson->total < 3) || (areapropr < noise)))
			{				
				f = new FigureImg();
				for( int i=0; i< currentson->total; ++i )
				{
					CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, currentson, i );

					if (debug)
						printf(" (%d,%d)\n", p->x, img->height - p->y );

					f->colocarVertice(new Vertice(p->x, img->height - p->y, false));
				}

				f->setArea(area);
				f->setId(lastID++);

				// set color

				setColorFromImage(f, img, currentson, NULL, NULL, false, false);

				if (debug)
				{
					cvShowImage( "Contours", g_contours);
					cvWaitKey();
				}
				
				// add the figure to figure list
				figuras->colocarFig(f);
			}

			
			if (currentson->h_next)
			{
				currentson = currentson->h_next;
				// down till the end
				while (currentson->v_next) currentson = currentson->v_next;
			}
			else
				currentson = currentson->v_prev;
		}
	}

}

void Analizer::addFiguresfromPic(IplImage* img, IplImage* mask, Figuras* figuras, int polSimp, int noise)
{
	// useful data
	CvSeq* contours = 0;
	CvMemStorage* g_storage = cvCreateMemStorage(0);
	IplImage* g_contours = cvCreateImage( cvGetSize(img), 8, 3 );
	CvScalar red = CV_RGB(250,0,0);
	CvScalar blue = CV_RGB(250,250,250);

	// look for image contours
	cvFindContours( mask, g_storage, &contours, sizeof(CvContour), CV_RETR_LIST);


	if( contours )
	{
		//convert the pixel contours to line segments in a polygon.
		CvSeq* first_polygon = cvApproxPoly(contours, sizeof(CvContour), g_storage, CV_POLY_APPROX_DP, polSimp, 1);

		int n = 0;
		CvSeq* cAux = contours;
		double area;

		// iterate contours and create a figure for each one
		FigureImg* f;
		int currentmaxsize = MAX_SIZE;
		Vertice* staticfigure = new Vertice[currentmaxsize];//  static aux Figure
		int nstaticfigure;
		int id = 0;
		for( CvSeq* c = first_polygon; c != NULL; c = c->h_next)
		{
			nstaticfigure = 0;
			
			cvZero( g_contours );
			cvDrawContours(
				g_contours,
				c,
				red,			// Red
				blue,			// Blue
				-1,				// Vary max_level and compare results
				1,//CV_FILLED,//1,
				8 );

			if (debug)
			{
				printf( "Contour #%dn", n );
				
				printf( " %d elements:\n", c->total );
			}
			
			for( int i=0; i< c->total; ++i )
			{
				CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, i );

				if (debug)
					printf(" (%d,%d)\n", p->x, img->height - p->y );

				//if it's too big, resize to double
				if (nstaticfigure >= currentmaxsize)
				{
					currentmaxsize = currentmaxsize*2;
					Vertice* tmpf = new Vertice[currentmaxsize];
					for (int i = 0; i < nstaticfigure; i++)
						tmpf[i] = staticfigure[i];
					delete [] staticfigure;
					staticfigure = tmpf;
				}

				staticfigure[nstaticfigure].x = p->x;
				staticfigure[nstaticfigure].y = img->height - p->y;
				nstaticfigure++;
			}

			// Calculamos el area de cada poligono
			area = cvContourArea(c);
			if (debug)
				printf("Area: %f\n", area);
				
			//
			double areapropr = area * 100 / (figuras->getWidth() * figuras->getHeight());
				
			if(cAux!=NULL) //Cogemos el siguiente para la siguiente vuelta (es como un do-while)
				cAux = cAux->h_next;
			

			// We set an area filter to skip noise figures
			if ((nstaticfigure < 3) || (areapropr < noise))
			{				
				n++;
				continue;
			}

			f = new FigureImg();
			for (int i = 0; i < nstaticfigure; i++)
			{
				f->colocarVertice(new Vertice(staticfigure[i].x, staticfigure[i].y, false));
			}
			f->setArea(area);
			f->setId(lastID++);

			// set color

			setColorFromImage(f, img, c, NULL, NULL, false, false);

			if (debug)
			{
				cvShowImage( "Contours", g_contours);
				cvWaitKey();
			}

			// add the figure to figure list
			figuras->colocarFig(f);

			n++;
		}
	}

}