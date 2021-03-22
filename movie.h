
//header file for movies
#ifndef movie_h
#define movie_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class movie : public media {
public: //methods
	movie();
	virtual int getType();
	char* getDirector(); 
	int* getDuration(); 
	float* getRating(); 
private: //stores director, duration, rating, in private object
	char director[50]; 
	int duration; 
	float rating; 
};

#endif
