#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;
class Movie {
	private :
		string _movieID;
		string _nameMovie;
		string _time;
	public :

		Movie();
		Movie(string movieID, string nameMovie, string time);

		//setter
		void setMovieID(string movieID);

		void setNameMovie(string nameMovie);

		void setTime(string time);

		//getter

		string getMovieID(string movieID);

		string getNameMovie(string nameMovie);

		string getTime(string time);
};
#endif