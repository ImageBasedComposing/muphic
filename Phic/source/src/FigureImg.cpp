#include "FigureImg.h"

FigureImg::FigureImg() : Figura()
{
	//ctor
}

FigureImg::~FigureImg()
{
	//dtor
}


bool FigureImg::compare(FigureImg* f1, FigureImg* f2) 
{
	return f1->getId() > f2->getId(); //Por ahora se comparan los ids.
}