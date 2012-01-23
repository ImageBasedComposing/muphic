#include "Phic.h"

/*#include "opencv2/opencv.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"*/

//#include "RegionMaker.h"
//#include "PolygonMaker.h"
//#include "FigureImg.h"
#include "cv.h"
#include "highgui.h"
//class PolygonMaker;

#include "Figuras.h"
#include "FigureImg.h"

using namespace cv;

Phic::Phic()
{
    //ctor
}

Phic::~Phic()
{
    //dtor
}

int g_thresh = 50;
IplImage* g_image = NULL;
int filtro = 2;

void on_trackbar(int)
{

	// We create Image Data
	int id = 0;
	CvMemStorage*   g_storage = NULL;
	CvScalar red = CV_RGB(250,0,0);
	CvScalar blue = CV_RGB(0,0,250);
	IplImage* g_image = cvLoadImage( "1.png" );
	IplImage* g_gray = NULL;

	// We load the image
	if( g_storage == NULL )
	{
		g_gray = cvCreateImage( cvGetSize( g_image ), 8, 1 );
		g_storage = cvCreateMemStorage(0);
	} 
	else 
	{
		cvClearMemStorage( g_storage );
	}

	IplImage* g_copy = cvLoadImage( "1.png", 0 );
	IplImage* g_contours = cvCreateImage( cvGetSize(g_gray), 8, 3 );

	CvSeq* contours = 0;
	cvCvtColor( g_image, g_gray, CV_BGR2GRAY );


	// We choose the filter we will be using
	switch(filtro)
	{
		case 0:
			cvAdaptiveThreshold(g_gray, g_gray,   double(255), CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 3, 3 );
			break;
		case 1:
			cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
			break;
		case 2:
			cvCanny( g_gray, g_gray, 1.0, 1.0, 3);
			break;
		default:
			cvCanny( g_gray, g_gray, 1.0, 1.0, 3);
			break;
	}

	// We show the resulting image from apliying the filter
	cvShowImage( "Contours", g_gray );
	cvWaitKey();

	// We look for image contours
	cvFindContours( g_gray, g_storage, &contours, sizeof(CvContour), CV_RETR_LIST);
	cvZero( g_gray );

	// We create figure data
	Figuras* figuras = new Figuras();
	figuras->setWidth(g_gray->width);
	figuras->setHeight(g_gray->width);
	Figura * f, * padre;
	bool padreDone = false;

	// We copy contour data to our figure type
	CvSeq* first_polygon = NULL;
	
	if( contours )
	{
		//convert the pixel contours to line segments in a polygon.
		first_polygon = cvApproxPoly(contours, sizeof(CvContour), g_storage, CV_POLY_APPROX_DP, 2, 1);

		int n = 0;
		CvSeq* cAux = contours;
		double area;

		for( CvSeq* c=first_polygon; c!=NULL; c=c->h_next)
		{
		//for( CvSeq* c=contours; c!=NULL; c=c->h_next ){
			//cvCvtColor(  g_contours,  g_contours, CV_GRAY2BGR );
			cvZero( g_contours );
			cvDrawContours(
				g_contours,
				c,
				red,			// Red
				blue,           // Blue
				1,              // Vary max_level and compare results
				1,
				8 );
			printf( "Contour #%dn", n );
				
			printf( " %d elements:\n", c->total );

			f = new FigureImg();

			for( int i=0; i< c->total; ++i )
			{
				CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, i );
				printf(" (%d,%d)\n", p->x, g_gray->height - p->y );
				f->colocarVertice(new Vertice(p->x, g_gray->height - p->y, false));
			}
			//if (!padreDone)
				//cvWaitKey();

			pair<int,int> bar = f->getBarycenter();
			cout << n << " " << endl;

			// Cogemos el color del baricentro de la figura
			CvScalar s = cvGet2D(g_copy, bar.second, bar.first);
			f->setRGB(s.val[0], s.val[1], s.val[2]);
				
			// Calculamos el area de cada poligono
			area = cvContourArea(c);
			printf("Area: %f\n", area);
				
			if(area == 0) 
				area = 100;
				
			f->setArea(area);
				
			if(cAux!=NULL) //Cogemos el siguiente para la siguiente vuelta (es como un do-while)
				cAux = cAux->h_next;

			f->setId(++id);

			// We set an area filter to skip noise figures
			if ((f->sizeVertices() < 3) || (f->getArea() < 50))
			{				
				n++;
				continue;
			}
			else
				cvWaitKey();

			cvShowImage( "Contours", g_contours );

			// We add the figure to our figure list
			if (padreDone)
			{
				figuras->colocarFig(f);
				f->setParent(padre);
				padre->colocarHijo(f);
			}
			else
			{
				figuras->colocarFig(f);
				figuras->colocarPadre(f);
				padre = f;
				padreDone = true;
			}
			//cvShowImage( "Contours", g_gray );
			n++;
		}
	}
	cvShowImage( "Contours", g_gray );

	cvWaitKey();
	figuras->guardar("test1.xml");
}

void test()
{
    cvNamedWindow( "Contours", 1 );
    cvCreateTrackbar( "Threshold", "Contours", &g_thresh, 255, on_trackbar );
    on_trackbar(0);
}


int main(int argc, char* argv[])
{


	test();

	return 0;
}

