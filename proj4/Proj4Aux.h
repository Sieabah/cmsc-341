#ifndef PROJ4_AUX_H
#define PROJ4_AUX_H

#include <sys/stat.h>

class Util
{
public:
	static bool FileExists(std::string filename)
	{
		//Buffer
		struct stat buffer;   
		//See if anything can be read from the file into the buffer
		return (stat (filename.c_str(), &buffer) == 0); 
	}
};

#endif