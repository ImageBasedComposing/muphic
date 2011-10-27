#ifndef COMPOSER_DEMO__H
#define COMPOSER_DEMO__H

#include "Composer.h"
#include "TinyXML.h"

struct Point {   
   int x; 
   int y;
};

class ComposerDemo : public Composer
{
	public:
		ComposerDemo();
		~ComposerDemo();

	    string compose();
        string compose(string picPath, string usrConfPath);

	private:
};

#endif // COMPOSER_DEMO__H
