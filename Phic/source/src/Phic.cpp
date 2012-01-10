#include "Phic.h"

/*#include "opencv2/opencv.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"*/

//#include "RegionMaker.h"
//#include "PolygonMaker.h"
//#include "FigureImg.h"
#include "opencv/cv.h"
#include "opencv/highgui.h"
class PolygonMaker;

Phic::Phic()
{
    //ctor
}

Phic::~Phic()
{
    //dtor
}


IplImage*	g_image = NULL;
IplImage*	g_gray = NULL;
int		g_thresh = 50;
CvMemStorage* 	g_storage = NULL;

void on_trackbar(int){
	if( g_storage == NULL ){
		g_gray = cvCreateImage( cvGetSize( g_image ), 8, 1 );
		g_storage = cvCreateMemStorage(0);
	} else {
		cvClearMemStorage( g_storage );
	}

	IplImage* img_8uc1 = cvLoadImage( "1.png", 0 );
	//IplImage* img_8uc1 = cvCreateImage( cvGetSize( g_image ), 8, 1 );
	//IplImage* img_8uc1 = g_gray;
	IplImage* img_edge = cvCreateImage( cvGetSize(img_8uc1), 8, 10 );
	IplImage* img_8uc3 = cvCreateImage( cvGetSize(img_8uc1), 8, 3 );
	CvScalar red = CV_RGB(250,0,0);
	CvScalar blue = CV_RGB(0,0,250);

	CvSeq* contours = 0;
	cvCvtColor( g_image, g_gray, CV_BGR2GRAY );
	
	/*parameters[0]=2;
	parameters[1]=(double) stdDev * 0.9;*/
	
	//cvAdaptiveThreshold(g_gray, g_gray,	double(255), CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 3, 3 );
	        //cvCvtColor(frame, grey, CV_BGR2GRAY);
    cvCanny( g_gray, g_gray, 1.0, 1.0, 3);
	//cvCanny( g_gray, g_gray, 8.0, 16.0, 3);
 //cvShowImage( "Contours", g_gray );return;
	/* show loaded frame */
	//cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
	cvFindContours( g_gray, g_storage, &contours, sizeof(CvContour), CV_RETR_LIST);



	cvZero( g_gray );

	CvSeq* first_polygon = NULL;
	if( contours ){
		//convert the pixel contours to line segments in a polygon.
		first_polygon = cvApproxPoly(contours, sizeof(CvContour), g_storage, CV_POLY_APPROX_DP, 2, 1);

		int n = 0;
		for( CvSeq* c=first_polygon; c!=NULL; c=c->h_next ){
			//for( CvSeq* c=contours; c!=NULL; c=c->h_next ){
		cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );
		cvDrawContours(	
			img_8uc3,
			c,
			red,
			blue,		// Blue
			1,			// Vary max_level and compare results
			1,
			8 );
		printf( "Contour #%dn", n );
		cvShowImage( "Contours", img_8uc3 );
		printf( " %d elements:\n", c->total );
		for( int i=0; i< c->total; ++i ){
			CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, i );
			printf(" (%d,%d)\n", p->x, p->y );
		}
		cvWaitKey();
		n++;
		}
	}
	cvShowImage( "Contours", g_gray );

}


int main(int argc, char* argv[])
{
	
	g_image = cvLoadImage( "1.png" );
	cvNamedWindow( "Contours", 1 );
	cvCreateTrackbar( "Threshold", "Contours", &g_thresh, 255, on_trackbar );
	on_trackbar(0);
	cvWaitKey();

	return 0;
}