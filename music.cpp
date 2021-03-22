#include <iostream>
#include <cstring>


#include "media.h"
#include "music.h"

using namespace std;

music::music() {
}

int* music::getDuration() {
	return &duration;
}

char* music::getArtist() {
	return artist;
}

char* music::getPublisher() {

	return publisher;
}

int music::getType() {
	return 1;
}