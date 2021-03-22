#include <iostream>
#include <cstring>
#include "game.h"
#include "media.h"

using namespace std;

game::game() {//calling .h file


}

int game::getType() {//storing type
	return 3;
}

char* game::getPublisher() {//sending publisher to .h file
	return publisher;
}

float* game::getRating() {//sending rating to .h file
	return &rating;
}