#pragma once

#ifndef COMPOSER_DEMO__H
#define COMPOSER_DEMO__H

#include "Composer.h"
#include "tinyxml.h"
#include "MidizatorABC.h"

class MidizatorABC;

struct Point {
   int x;
   int y;
};

struct Vertex{
	int x, y;
	bool arc;
	string color;
	Vertex(){arc = false;}
};

class ComposerDemo : public Composer
{
	public:
		ComposerDemo(Music* msc);
		~ComposerDemo();

	    string compose();
        string compose(string picPath, string usrConfPath);

	private:
		Music * music;
		MidizatorABC * mdztor;
};

#endif // COMPOSER_DEMO__H
