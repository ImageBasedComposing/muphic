#pragma once

#ifndef AUX_STRUCTS__H
#define AUX_STRUCTS__H

struct Color{ int r; int g; int b;
	Color(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	Color()
	{
		r=0; g=0; b=0;
	}
	}; 


#endif // AUX_STRUCTS__H