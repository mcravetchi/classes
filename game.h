//header file for games

#ifndef game_h
#define game_h

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class game : public media { //all header classes besides media have this, it means media inherits those classes
public:
	game();
	virtual int getType(); 
	char* getPublisher(); 
	float* getRating(); 
private:
	char publisher[100]; 
	float rating; 
};

#endif