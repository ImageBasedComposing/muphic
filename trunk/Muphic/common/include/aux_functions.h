#pragma once

#ifndef AUX_FUNCTIONS__H
#define AUX_FUNCTIONS__H

// Paths related functions

#include <string>

std::string changeExtension(std::string picPath, std::string extension)
{
	int i = picPath.find_last_of('.');

	if (extension == "")
		return picPath.substr(0, i);
	else
		return picPath.substr(0, i) + '.' + extension;
}

std::string getPath(std::string exeFile)
{
	int i = exeFile.find_last_of("/\\");

	if (i > 0)
		return exeFile.substr(0, i) + "/";
	else
		return "";
}


#endif // AUX_FUNCTIONS__H

