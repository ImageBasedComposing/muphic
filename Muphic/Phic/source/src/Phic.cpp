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

	Analizer* analizer = new Analizer();
	analizer->debug = phic->usrConf->getPhicDebug();

	IplImage* imagesrc = cvLoadImage( argv[2] );
	Figuras* figuras = new Figuras();
	figuras->setWidth(imagesrc->width);
	figuras->setHeight(imagesrc->height);
	
	int nas;
	IplImage** test;

	if (phic->usrConf->getPhicFilterSelect() == 3) 
	{
		IplImage* *images;
		int n = 0;

		analizer->analizePerRegions(imagesrc, 3, images, n);

		analizer->addFiguresfromPics(imagesrc, images, n, figuras, phic->usrConf->getPhicPolygonSimp(), phic->usrConf->getPhicNoiseSelec());
	}
	else if (phic->usrConf->getPhicFilterSelect() == 4) 
	{
		IplImage* *images;
		int n = 0;

		analizer-> analizeHSV(imagesrc, images,n, phic->usrConf->getPhicThresholdH(), phic->usrConf->getPhicThresholdS(), phic->usrConf->getPhicThresholdV());

		analizer->addFiguresfromPics(imagesrc, images, n, figuras, phic->usrConf->getPhicPolygonSimp(), phic->usrConf->getPhicNoiseSelec());
	}
	else
	{
		IplImage* imagedest;
		imagedest = analizer->analizeByFilter(imagesrc, phic->usrConf->getPhicFilterSelect(), phic->usrConf->getPhicThresholdSelec());

		analizer->addFiguresfromPicv2(imagesrc, imagedest, figuras, phic->usrConf->getPhicPolygonSimp(), phic->usrConf->getPhicNoiseSelec());
	}

	
	// NO BIG RECTANGLE BEHIND EVERYTHING
	Figura* bigfigure = new Figura();
	bigfigure->colocarVertice(new Vertice(1,1, false));
	bigfigure->colocarVertice(new Vertice(figuras->getWidth(), 1, false));
	bigfigure->colocarVertice(new Vertice(figuras->getWidth(), figuras->getHeight(), false));
	bigfigure->colocarVertice(new Vertice(1, figuras->getHeight(), false));
	figuras->colocarFig(bigfigure);

	figuras->deleteReps();
	figuras->removeFig(bigfigure);
	delete bigfigure;

	if (figuras->sizeFig() != 0)
		figuras->setParentSonStructure();

	if (phic->usrConf->getPhicDebug())
		cvWaitKey();

	figuras->redoColorFigs();

	std::string output = changeExtension(argv[2], "xml");

	figuras->guardar(output);

	delete figuras;
	delete analizer;
	delete phic;

	return 0;
}

