/*
Max Cravetchi
21 March 2021

This project is classes.
It takes in objects of various medias.
It can display them.
Add them.
Delete them.
It was not fun.
*/


#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

#include "media.h"
#include "music.h"
#include "movie.h"
#include "game.h"

using namespace std;

void add(vector<media*>* storeMedia, int type); //function declarations
void search(vector<media*>* storeMedia);
void deleteStuff(vector<media*>* storeMedia);

int main() {

    vector<media*> storeMedia; //vector that stores all the media

    bool replay = true;
    while (replay == true) {
        int action=0; //for int main only
        int type=0; //used to differentiate between movies, music, and vidya. 
        cout << "1 TO ADD | 2 TO SEARCH | 3 TO DELETE | 4 TO QUIT?" << endl; //type in 1 2 3 4 for each action
        cin >> action;
        cin.ignore(100, '\n');

        if (action == 1) { //same mechanism here
            cout << "1 FOR MUSIC | 2 FOR MOVIE | 3 FOR VIDEO GAME?" << endl;
            cin >> type;
            cin.ignore(100, '\n');
            if (type == 1) {        

                add(&storeMedia, 1); //calls add function, with the argument of vector, and media type.
            
            }
            else if (type == 2) {

                add(&storeMedia, 2);

            }
            else if (type == 3) {

                add(&storeMedia, 3);


            }

        }
        else if (action == 2) {


            search(&storeMedia); //search function

        }
        else if (action == 3) {


            deleteStuff(&storeMedia); //delete function

        }
        else if (action == 4) {
            replay = false;


        }
        else {
            cout << "PLEASE TYPE A VALID NUMBER" << endl;
        }

    }
   
    return 0;
}

void add(vector<media*>* storeMedia, int type) {

    if (type == 1) {
        music* newMusic = new music; //creates a new music object
        cout << "YEAR OF RELEASE?" << endl;
        cin >> *newMusic->getYear();
        cin.ignore(100, '\n');

        cout << "ARTIST?" << endl;
        cin.get(newMusic->getArtist(), 50);
        cin.ignore(100, '\n');

        cout << "TITLE?" << endl;
        cin.get(newMusic->getTitle(), 50);
        cin.ignore(100, '\n');

        cout << "PUBLISHSER?" << endl;
        cin.get(newMusic->getPublisher(), 50);
        cin.ignore(100, '\n');

        cout << "DURATION?" << endl;
        cin >> fixed >> setprecision(2) >> *newMusic->getDuration();
        cin.ignore(100, '\n');

        storeMedia->push_back(newMusic); //stores object into media vector
    }
    else if (type == 2) {

        movie* newMovie = new movie; //movie object
        cout << "YEAR OF RELEASE?" << endl;
        cin >> *newMovie->getYear();
        cin.ignore(100, '\n');

        cout << "DIRECTOR?" << endl;
        cin.get(newMovie->getDirector(), 50);
        cin.ignore(100, '\n');

        cout << "TITLE?" << endl;
        cin.get(newMovie->getTitle(), 50);
        cin.ignore(100, '\n');

        cout << "DURATION?" << endl;
        cin >> *newMovie->getDuration();
        cin.ignore(100, '\n');

        cout << "RATING?" << endl;
        cin >> fixed >> setprecision(2) >> *newMovie->getRating();
        cin.ignore(100, '\n');

        storeMedia->push_back(newMovie);


    }
    else if (type == 3) {

        game* newGame = new game; //vidya game object
        cout << "YEAR OF RELEASE?" << endl;
        cin >> *newGame->getYear();
        cin.ignore(100, '\n');

        cout << "TITLE?" << endl;
        cin.get(newGame->getTitle(), 50);
        cin.ignore(100, '\n');

        cout << "PUBLISHER?" << endl;
        cin.get(newGame->getPublisher(), 50);
        cin.ignore(100, '\n');

        cout << "RATING?" << endl;
        cin >> fixed >> setprecision(2) >> *newGame->getRating();
        cin.ignore(100, '\n');

        storeMedia->push_back(newGame);
    }
}


void search(vector<media*>* storeMedia) {

    char searchTitle[50]; //for user input if they delete by title
    int searchYear; //for user input if they delete by year
    int searchType = 0; //type of media for local function only
    bool searchRepeat = false;
    vector<media*>::iterator searchThru; //iterator
   
    cout << "1: SEARCH BY TITLE | 2: SEARCH BY YEAR" << endl;
    cin >> searchType;
    cin.ignore(100, '\n');

    if (searchType == 1) {
        cout << "TITLE TO SEARCH?" << endl;
        cin.get(searchTitle, 50);
        cin.ignore(100, '\n');

        for (searchThru = storeMedia->begin(); searchThru != storeMedia->end(); searchThru++) {
            if (strcmp((*searchThru)->getTitle(), searchTitle) == 0) {
                if ((*searchThru)->getType() == 1) { //gets type of media (music)
                    //prints music
                    cout << "MUSIC:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "ARTIST: " << dynamic_cast<music*>(*searchThru)->getArtist() << endl;
                    cout << "TITLE: " << (*searchThru)->getTitle() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<music*>(*searchThru)->getPublisher() << endl;
                    cout << "DURATION: " << *dynamic_cast<music*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 2) {//movies
                    cout << "MOVIE:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "DIRECTED BY: " << dynamic_cast<movie*>(*searchThru)->getDirector() << endl;
                    cout << "TITLE: " << (*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<movie*>(*searchThru)->getRating() << endl;
                    cout << "DURATION: " << *dynamic_cast<movie*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 3) { //games
                    cout << "VIDYA GAME:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<game*>(*searchThru)->getPublisher() << endl;
                    cout << "TITLE: " << (*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<game*>(*searchThru)->getRating() << endl;
                }
            }
        }
    }
    else if (searchType == 2) {
        cout << "YEAR TO SEARCH?" << endl;
        cin >> searchYear;

        cin.ignore(100, '\n');

        for (searchThru = storeMedia->begin(); searchThru != storeMedia->end(); searchThru++) {
            if (*(*searchThru) ->getYear()==searchYear) {
                if ((*searchThru)->getType() == 1) {
                    cout << "MUSIC:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "ARTIST: " << dynamic_cast<music*>(*searchThru)->getArtist() << endl;
                    cout << "TITLE: " << *(*searchThru)->getTitle() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<music*>(*searchThru)->getPublisher() << endl;
                    cout << "DURATION: " << *dynamic_cast<music*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 2) {
                    cout << "MOVIE:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "DIRECTED BY: " << dynamic_cast<movie*>(*searchThru)->getDirector() << endl;
                    cout << "TITLE: " << *(*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<movie*>(*searchThru)->getRating() << endl;
                    cout << "DURATION: " << *dynamic_cast<movie*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 3) {
                    cout << "VIDYA GAME:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<game*>(*searchThru)->getPublisher() << endl;
                    cout << "TITLE: " << *(*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<game*>(*searchThru)->getRating() << endl; 
                    //dereferences or not depending on return function from methods in classes, should output actual value
                }
            }
        }
    }
    else {
        searchRepeat = false;
    }
}

void deleteStuff(vector<media*>* storeMedia) {
    char deleteTitle[50];
    int deleteYear; //delete by year locally
    int deleteType; //local
    int yesorno; //for yes delete or no delete local
    vector<media*>::iterator deleteskis;

    cout << "1: DELETE BY TITLE | 2: DELETE BY YEAR" << endl;
    cin >> deleteType;
    cin.ignore(100, '\n');

    if (deleteType == 1) {
        cout << "TITLE TO DELETE?" << endl;
        cin.get(deleteTitle, 50);
        cin.ignore(100, '\n');

        for (deleteskis = storeMedia->begin(); deleteskis != storeMedia->end(); deleteskis++) {
            if (strcmp((*deleteskis)->getTitle(), deleteTitle) == 0) {
                if ((*deleteskis)->getType() == 1) { //for music
                    cout << "MUSIC TITLE FOUND: " << (*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 FOR YES/2 FOR NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MUSIC DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MUSIC WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
                else if ((*deleteskis)->getType() == 2) {
                    //for movie
                    cout << "MOVIE TITLE FOUND: " << (*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 FOR YES/2 FOR NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MOVIE DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MOVIE WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
                else if ((*deleteskis)->getType() == 3) {
                    //for games
                    cout << "VIDEO GAME TITLE FOUND: " << (*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 FOR YES/2 FOR NO " << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "VIDEO GAME DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "VIDEO GAME WAS NOT DELETED." << endl;
                        yesorno;
                    }
                }
            }
        }
    }
    else if (deleteType == 2) { //delete by year
        cout << "YEAR TO DELETE?" << endl;
        cin >> deleteYear;
        cin.ignore(100, '\n');

        for (deleteskis = storeMedia->begin(); deleteskis != storeMedia->end(); deleteskis++) {
            if (*(*deleteskis)->getYear() == deleteYear) {
                if ((*deleteskis)->getType() == 1) {
                    cout << "MUSIC YEAR(S) FOUND: " << *(*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 FOR YES/2 FOR NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MUSIC DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MUSIC WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
                else if ((*deleteskis)->getType() == 2) {
                    cout << "MOVIE YEAR(S) FOUND: " << *(*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 FOR YES/2 FOR NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MOVIE(S) DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MOVIE(S) WAS NOT DELETED." << endl;
                        yesorno;
                    }
                }
                else if ((*deleteskis)->getType() == 3) {
                    cout << "VIDEO GAME YEAR(S) FOUND: " << *(*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 FOR YES/2 FOR NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        return;
                        cout << "VIDEO GAME DELETED" << endl;
                        yesorno = 0;
                    }
                    else if (yesorno == 2) {
                        cout << "VIDEO GAME WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
            }
        }
    }
}
