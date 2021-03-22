#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

#include "media.h"

using namespace std;

media::media() {
}

//year and title are shared by all classes
//it can sort and different between them via type
int* media::getYear() {
	return &year;
}

char* media::getTitle() {
	return title;
}

int media::getType() {
	return 0;
}