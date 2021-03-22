#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"

using namespace std;

movie::movie() {//calling .h file


}

int movie::getType() {//sending type to media class
	return 2;
}

char* movie::getDirector() {//sending director to .h file
	return director;
}

int* movie::getDuration() {//sending duration to .h file
	return &duration;
}

float* movie::getRating() {//sending rating to .h file
	return &rating;
}