#include "SeatManagement.h"
#include <iostream>

using namespace std;

/*
	   ============== SEAT MAP ==============

				A1 A2 A3 A4 A5 A6
				B1 B2 B3 B4 B5 B6
				C1 C2 C3 C4 C5 C6
				D1 D2 D3 D4 D5 D6
				E1 E2 E3 E4 E5 E6
*/

// ============================================
// Constructor and destructor
// ============================================
SeatManagement::SeatManagement() {
	headWaitList = nullptr;
	tailWaitList = nullptr;

	initSeatsMap_HashMap();
}
SeatManagement::~SeatManagement() {
	Node *current = headWaitList;

	while (current != nullptr) {
		Node *temp = current;
		current = current->next;

		delete temp;
	}

	headWaitList = nullptr;
	tailWaitList = nullptr;
}

// ============================================
// Initialize Seat Hash Map
// ============================================

void SeatManagement::initSeatsMap_HashMap() {
	for (char row = 'A'; row <= 'E'; row++) {
		for (int number = 1; number <= 6; number++) {
			string seatID = string(1, row) + to_string(number);

			string seatClass = "";
			float seatPrice = 0.0;

			// A, B = Normal
			if (row == 'A' || row == 'B') {
				seatClass = "Normal";
				seatPrice = 100;
			}

			// C, D = VIP
			else if (row == 'C' || row == 'D') {
				seatClass = "VIP";
				seatPrice = 200;
			}

			// E = Couple
			else {
				seatClass = "Couple";
				seatPrice = 250;
			}

			// A = Available
			Seat seat(seatID, seatClass, "A", seatPrice);
			_seats[seatID] = seat; // Add seat in to _seats : Map
		}
	}
}

// Display Seat Map

void SeatManagement::displaySeatMap() {
	cout << "\n============== SEAT MAP ===============\n\n";

	for (char row = 'A'; row <= 'E'; row++) {
		cout << "  ";

		for (int number = 1; number <= 6; number++) {
			string seatID = string(1, row) + to_string(number);

			Seat &seat = _seats.at(seatID);

			cout << seat.getSeatID() << "[" << seat.getStatus() << "]   ";
		}

		cout << endl;
	}

	cout << "\n";
	cout << "A = Available\n";
	cout << "P = Pending\n";
	cout << "O = Ordered\n";

	cout <<"\n";
	cout <<"A1 -> B6 : Normal seats (100)\n";
	cout <<"C1 -> D6 : VIP seats (200)\n";
	cout <<"E1 -> E6 : Couple seats (250)\n";
}

// ============================================
// Order Seat
// ============================================

bool SeatManagement::orderSeat(string seatID) {
	// Search in map and return index
	auto it = _seats.find(seatID);

	// Seat does not exist
	if (it == _seats.end()) {
		return false;
	}

	Seat &seat = it->second; // Get value

	// Only Available seat can be ordered
	if (seat.getStatus() != "A") {
		return false;
	}

	// Change status
	seat.setStatus("P");

	return true;
}

// ============================================
// Cancel Seat
// ============================================

bool SeatManagement::cancelSeat(string seatID) {
	auto it = _seats.find(seatID);

	// Seat does not exist
	if (it == _seats.end()) {
		return false;
	}

	Seat &seat = it->second;

	// Only Pending / Ordered can be cancelled
	if (seat.getStatus() == "A") {
		return false;
	}

	// Change back to Available
	seat.setStatus("A");

	return true;
}

// ============================================
// Add to Waiting Payment List
// ============================================

bool SeatManagement::addToWaitList( Customer customer, string movieID, string seatID) {
	// Check seat exists
	auto it = _seats.find(seatID);

	if (it == _seats.end()) {
		return false;
	}
	/*
		Node contains:
		Customer
		Movie ID
		Seat ID
	*/
	Node *newNode = new Node(customer, movieID, seatID);

	// Empty list
	if (headWaitList == nullptr) {
		headWaitList = newNode;
		tailWaitList = newNode;
	}

	// List already has nodes
	else {
		tailWaitList->next = newNode;
		tailWaitList = newNode;
	}

	return true;
}

// ============================================
// Display Waiting Payment List
// ============================================

void SeatManagement::displayWaitList() {
	if (headWaitList == nullptr) {
		cout << "\nNo customer is waiting for payment.\n";
		return;
	}

	cout << "\n========== WAITING PAYMENT LIST ==========\n";

	Node *current = headWaitList;

	while (current != nullptr) {
		cout << "------------------------------------------\n";

		cout << "Customer : "
		     << current->customer.getNameCustomer() << endl;

		cout << "Phone    : "
		     << current->customer.getPhoneNumber() << endl;

		cout << "Movie ID : "
		     << current->movieID << endl;

		cout << "Seat     : "
		     << current->seatID << endl;

		current = current->next;
	}

	cout << "------------------------------------------\n";
}