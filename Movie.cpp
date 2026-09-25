#include "Movie.h"

// Constructor
Movie::Movie() {
	_movieID = "";
	_nameMovie = "";
	_time = "";
}

Movie::Movie(string movieID, string nameMovie, string time) {
	_movieID = movieID;
	_nameMovie = nameMovie;
	_time = time;
}

// Setter
void Movie::setMovieID(string movieID) {
	this->_movieID = movieID;
}

void Movie::setNameMovie(string nameMovie) {
	this->_nameMovie = nameMovie;
}

void Movie::setTime(string time) {
	this->_time = time;
}

// Getter
string Movie::getMovieID() {
	return _movieID;
}

string Movie::getNameMovie() {
	return _nameMovie;
}

string Movie::getTime() {
	return _time;
}