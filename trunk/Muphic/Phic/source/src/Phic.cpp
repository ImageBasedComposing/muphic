#include "Phic.h"




Phic::Phic()
{
    //ctor
}

Phic::~Phic()
{
    //dtor
	delete usrConf;
}


void Phic::setUsrConfPath(std::string p)
{
	usrConfPath = p;
}

void Phic::setPicPath(std::string p)
{
	picPath = p;
}



// f is the figure which we want to color
// g_image is the source image
// c is de contour of the figure
// inv determines if we consider the inside or the outside of the figure
// all determines if we consider the current contour (false) or all of the remaining (true)
void Phic::setColorFromImage(Figura* f, IplImage* g_image, CvSeq* c, IplImage* maskAcum, bool inv, bool all)
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
		if (usrConf->getPhicDebug())
			cvShowImage( "Contours", mask1 );

	}
	else
	{
		if (usrConf->getPhicDebug())
			cvShowImage( "Contours", mask );
	}

	if (usrConf->getPhicDebug())
		cvWaitKey();

	CvScalar s;
	Vec3b test;
	cv::Mat image = mask;
	int r, g, b, num;
	r = g = b = 0;
	num = 0;
	for (int i=0; i<image.rows; i++)
	{
		for (int j=0; j<image.cols; j++)
		{
			s = cvGet2D(mask, i, j);
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


void Phic::on_trackbar(int)
{
	srand( time(NULL));

	// We create Image Data
	int id = 0;
	CvMemStorage*   g_storage = NULL;
	CvScalar red = CV_RGB(250,0,0);
	CvScalar blue = CV_RGB(250,250,250);
	IplImage* g_image = cvLoadImage( picPath.c_str() );
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

	IplImage* g_copy = cvLoadImage( picPath.c_str(), 0 );
	IplImage* g_contours = cvCreateImage( cvGetSize(g_gray), 8, 3 );

	CvSeq* contours = 0;
	cvCvtColor( g_image, g_gray, CV_BGR2GRAY );

	filtro = usrConf->getPhicFilterSelect();
	g_thresh = usrConf->getPhicThresholdSelec();
	noise = usrConf->getPhicNoiseSelec();
	polSimp = usrConf->getPhicPolygonSimp();
	// We choose the filter we will be using
	switch(filtro)
	{
		case 1:
			cvAdaptiveThreshold(g_gray, g_gray,   double(255), CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 3, 3 );
			break;
		case 0:
			cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
			break;
		case 2:
			cvCanny( g_gray, g_gray, 1.0, 1.0, 3);
			break;
		default:
			cvCanny( g_gray, g_gray, 1.0, 1.0, 3);
			break;
	}

	if (usrConf->getPhicDebug())
	{
		// We show the resulting image from apliying the filter
		cvShowImage( "Contours", g_gray );
		cvWaitKey();
	}

	// We look for image contours
	cvFindContours( g_gray, g_storage, &contours, sizeof(CvContour), CV_RETR_LIST);
	cvZero( g_gray );

	// We create figure data
	Figuras* figuras = new Figuras();
	figuras->setWidth(g_gray->width);
	figuras->setHeight(g_gray->height);
	Figura * f, * padre, * father;
	bool padreDone = false;

	// We copy contour data to our figure type
	CvSeq* first_polygon = NULL;


	IplImage* maskAcum = cvCreateImage( cvGetSize(g_gray), 8, 1 );
	cvZero( maskAcum );

	if( contours )
	{
		//convert the pixel contours to line segments in a polygon.
		first_polygon = cvApproxPoly(contours, sizeof(CvContour), g_storage, CV_POLY_APPROX_DP, polSimp, 1);

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
				CV_FILLED,//1,
				8 );

			if (usrConf->getPhicDebug())
			{
				printf( "Contour #%dn", n );
				
				printf( " %d elements:\n", c->total );
			}

			f = new FigureImg();
			
			for( int i=0; i< c->total; ++i )
			{
				CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, i );

				if (usrConf->getPhicDebug())
					printf(" (%d,%d)\n", p->x, g_gray->height - p->y );

				f->colocarVertice(new Vertice(p->x, g_gray->height - p->y, false));
			}

			// Calculamos el area de cada poligono
			area = cvContourArea(c);
			printf("Area: %f\n", area);
				
			f->setArea(area);
			double areapropr = area * 100 / (figuras->getWidth() * figuras->getHeight());
				
			if(cAux!=NULL) //Cogemos el siguiente para la siguiente vuelta (es como un do-while)
				cAux = cAux->h_next;

			f->setId(++id);

			// We set an area filter to skip noise figures
			if ((f->sizeVertices() < 3) || (areapropr < noise))
			{				
				n++;
				continue;
			}
			else
			{
				if (usrConf->getPhicDebug())
					cvWaitKey();
			}

			// set color
			setColorFromImage(f, g_image, c, NULL, false, false);

			if (usrConf->getPhicDebug())
				cvShowImage( "Contours", g_contours);
			// We add the figure to our figure list
			if (padreDone)
			{
				figuras->colocarFig(f);
			}
			else
			{
				figuras->colocarFig(f);
				padre = f;
				padreDone = true;
			}
			n++;
		}
	}
	if (usrConf->getPhicDebug())
		cvShowImage( "Contours", g_gray );


	// colour background

	if (figuras->sizeFig() != 0)
		figuras->setParentSonStructure();

	if (usrConf->getPhicDebug())
		cvWaitKey();

	std::string output = changeExtension(picPath, "xml");
	figuras->guardar(output);
}

void Phic::test()
{
    cvNamedWindow( "Contours", 1 );
    cvCreateTrackbar( "Threshold", "Contours", &g_thresh, 255, Phic::on_trackbar );
    on_trackbar(0);
}


void showUsage()
{
	cout << "Phic.exe userConfPath imagePath" << endl;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Too few arguments in function call" << endl;
		showUsage();
		cin.get();
		cin.ignore(cin.rdbuf()->in_avail());

		return 1;
	}

	Phic* phic = new Phic();
	phic->setUsrConfPath(argv[1]);
    phic->setPicPath(argv[2]);
	phic->usrConf = new UsrConf();
	phic->usrConf->readPhic(argv[1]);

	phic->test();

	return 0;
}

