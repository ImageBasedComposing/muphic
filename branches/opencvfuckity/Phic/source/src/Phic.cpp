#include "Phic.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "RegionMaker.h"
#include "PolygonMaker.h"
#include "FigureImg.h"

class PolygonMaker;

Phic::Phic()
{
    //ctor
}

Phic::~Phic()
{
    //dtor
}




int main( int argc, const char* argv[] )
{
    cout << "...analyzing..." << endl;

	vector<Polygon> f;
	PolygonMaker* p = new PolygonMaker();
	RegionMaker* r = new RegionMaker();
	f = p->makePolygons(r->makeRegions("1.png"));
	return 0;
}
