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
				if (debug)
				{/*
					sprintf(titler, "r = (%d,%d)", (int) delta*i, (int) delta*(i+1));
					sprintf(titleg, "g = (%d,%d)", (int) delta*j, (int) delta*(j+1));
					sprintf(titleb, "b = (%d,%d)", (int) delta*k, (int) delta*(k+1));
					cvPutText (regionCube[i][j][k],titler,cvPoint(5,10), &font, cvScalar(255,255,0));
					cvPutText (regionCube[i][j][k],titleg,cvPoint(5,10 + 10), &font, cvScalar(255,255,0));
					cvPutText (regionCube[i][j][k],titleb,cvPoint(5,10 + 20), &font, cvScalar(255,255,0));*/
				}

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
void Analizer::setColorFromImage(Figura* f, IplImage* g_image, CvSeq* c, IplImage* maskAcum, bool inv, bool all)
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
		cvDrawContours( mask, c, CV_RGB(250,250,250), CV_RGB(250,250,250), howMany, CV_FILLED, 8 );

	IplImage* mask1 = cvCreateImage( cvGetSize( g_image ), 8, 1 );

	// show image (inv if asked)
	if (inv)
	{
		cvNot( mask, mask1 );
		if (debug)
			cvShowImage( "Contours", mask1 );

	}
	else
	{
		if (debug)
			cvShowImage( "Contours", mask );
	}

	if (debug)
		cvWaitKey();

	CvScalar s;
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
		addFiguresfromPic(img, mask[i], figuras, polSimp, noise);
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
		int id = 0;
		for( CvSeq* c = first_polygon; c != NULL; c = c->h_next)
		{
			cvZero( g_contours );
			cvDrawContours(
				g_contours,
				c,
				red,			// Red
				blue,			// Blue
				1,				// Vary max_level and compare results
				CV_FILLED,//1,
				8 );

			if (debug)
			{
				printf( "Contour #%dn", n );
				
				printf( " %d elements:\n", c->total );
			}

			f = new FigureImg();
			
			for( int i=0; i< c->total; ++i )
			{
				CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, i );

				if (debug)
					printf(" (%d,%d)\n", p->x, img->height - p->y );

				f->colocarVertice(new Vertice(p->x, img->height - p->y, false));
			}

			// Calculamos el area de cada poligono
			area = cvContourArea(c);
			if (debug)
				printf("Area: %f\n", area);
				
			f->setArea(area);
			double areapropr = area * 100 / (figuras->getWidth() * figuras->getHeight());
				
			if(cAux!=NULL) //Cogemos el siguiente para la siguiente vuelta (es como un do-while)
				cAux = cAux->h_next;

			f->setId(lastID++);

			// We set an area filter to skip noise figures
			if ((f->sizeVertices() < 3) || (areapropr < noise))
			{				
				n++;
				continue;
			}
			else
			{
				if (debug)
					cvWaitKey();
			}

			// set color
			setColorFromImage(f, img, c, NULL, false, false);

			if (debug)
				cvShowImage( "Contours", g_contours);
			
			// add the figure to figure list
			figuras->colocarFig(f);

			n++;
		}
	}
	if (debug)
		cvShowImage( "Contours", g_contours );

}