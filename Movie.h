#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "SeatManagement.h"

using namespace std;
class Movie
{
private:
	string _movieID;
	string _nameMovie;
	string _time;
	SeatManagement _seatManagement;

public:
	// Constructor
	Movie();
	Movie(string movieID, string nameMovie, string time);

	// setter
	void setMovieID(string movieID);
	void setNameMovie(string nameMovie);
	void setTime(string time);

	// getter
	string getMovieID();
	string getNameMovie();
	string getTime();

	// Seat Management
	SeatManagement &getSeatManagement();
};
#endif