#pragma once

#ifndef AUX_ELEMENTS__H
#define AUX_ELEMENTS__H

#include <vector>
#include "FigureImg.h"

using namespace std;

typedef std::vector< std::vector<bool>* > Mask;
typedef std::pair<Mask*,FigureImg*> Polygon;

#endif // AUX_ELEMENTS__H