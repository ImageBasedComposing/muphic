#pragma once

#ifndef REGIONMAKER_H
#define REGIONMAKER_H

#include "aux_elements.h"
#include <iostream>
#include <list>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class RegionMaker
{
    public:
		RegionMaker();
        virtual ~RegionMaker();

		vector<Mask*> makeRegions(std::string picPath);

    protected:
		
	private:
};

#endif // REGIONMAKER_H
