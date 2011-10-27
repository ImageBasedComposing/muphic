#ifndef COMPOSER_DEMO__H
#define COMPOSER_DEMO__H

#include "Composer.h"

class ComposerDemo : public Composer
{
	public:
		ComposerDemo();
		~ComposerDemo();

	    string compose();
        string compose(string picPath, string usrConfPath);
};

#endif // COMPOSER_DEMO__H
