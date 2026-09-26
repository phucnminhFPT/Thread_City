#include "Movie.h"

// Constructor
Movie::Movie()
{
	_movieID = "";
	_nameMovie = "";
	_time = "";
}

Movie::Movie(string movieID, string nameMovie, string time)
{
	_movieID = movieID;
	_nameMovie = nameMovie;
	_time = time;
}

// Setter
void Movie::setMovieID(string movieID)
{
	_movieID = movieID;
}

void Movie::setNameMovie(string nameMovie)
{
	_nameMovie = nameMovie;
}

void Movie::setTime(string time)
{
	_time = time;
}

// Getter
string Movie::getMovieID()
{
	return _movieID;
}

string Movie::getNameMovie()
{
	return _nameMovie;
}

string Movie::getTime()
{
	return _time;
}

// Get SeatManagement of this movie
SeatManagement &Movie::getSeatManagement()
{
	return _seatManagement;
}