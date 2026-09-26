#include "MenuHandler.h"
#include "Movie.h"
#include <iostream>

using namespace std;


// ==================================================
// MOVIE LIST
// Each movie has its own SeatManagement
// ==================================================

Movie movieList[4] = {
	Movie("M01", "Avengers", "18:00"),
	Movie("M02", "Superman", "19:30"),
	Movie("M03", "Spider-Man", "21:00"),
	Movie("M04", "Batman", "22:30")
};

int chooseMovie() {
	cout << "\n========== MOVIE LIST ==========\n";

	// Display Moive
	for (int i = 0; i < 4; i++) {
		cout << i + 1 	<< ". "  << movieList[i].getMovieID()
		     << " - " << movieList[i].getNameMovie()
		     << " - " << movieList[i].getTime()
		     << endl;
	}

	int choice;

	cout << "Choose movie: ";
	cin >> choice;

	if (choice < 1 || choice > 4) {
		return -1;
	}

	return choice - 1;
}

void orderSeatFlow(CustomerManagement &cM) {
	// Step 1: Login customer
	string phoneNumber;

	cout << "\n========== CUSTOMER LOGIN ==========\n";
	cout << "Enter phone number: ";
	cin >> phoneNumber;

	Customer *customer = cM.findCustomer(phoneNumber);

	if (customer == nullptr) {
		cout << "Customer not found!\n";
		cout << "Please create an account first.\n";
		return;
	}

	cout << "Welcome, " << customer->getNameCustomer() << "!\n";

	// Step 2: Choose movie

	int movieIndex = chooseMovie();

	if (movieIndex == -1) {
		cout << "Invalid movie!\n";
		return;
	}
	// Step 3: Display selected movie

	cout << "\n========== SELECTED MOVIE ==========\n";

	cout << "Movie ID   : "
	     << movieList[movieIndex].getMovieID()
	     << endl;

	cout << "Movie Name : "
	     << movieList[movieIndex].getNameMovie()
	     << endl;

	cout << "Time       : "
	     << movieList[movieIndex].getTime()
	     << endl;

	// Step 4: Get SeatManagement

	SeatManagement &seatManagement = movieList[movieIndex].getSeatManagement();
	// Step 5: Display seat map

	seatManagement.displaySeatMap();
	// Step 6: Choose seat

	string seatID;

	cout << "\nEnter seat ID: ";
	cin >> seatID;

	// Step 7: Order seat
	if (seatManagement.orderSeat(seatID) == false) {
		cout << "Cannot order this seat.\n";
		return;
	}

	cout << "Seat " << seatID << " is now pending.\n";

	// Step 8: Add to waiting list

	if (seatManagement.addToWaitList( *customer, movieList[movieIndex].getMovieID(),seatID)) {
		cout << "Added to waiting payment list.\n";
	} else {
		cout << "Failed to add to waiting payment list.\n";
	}
}