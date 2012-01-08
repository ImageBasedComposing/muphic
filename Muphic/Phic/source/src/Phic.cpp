#include "Phic.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "RegionMaker.h"

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

	
	RegionMaker* r = new RegionMaker();
	r->makeRegions("1.png");
	return 0;
}
