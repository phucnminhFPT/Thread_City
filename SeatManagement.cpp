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

// Constructor init
SeatManagement::SeatManagement() {
	headWaitList = nullptr;
	tailWaitList = nullptr;

	initSeatsMap_HashMap();
}

// Deconstructor
SeatManagement::~SeatManagement() {
}

// Hash Map for Seat infor
/*
	Key = "A1"
	Value = Seat("A1", "Normal", "A", 100)

	Key = "A2"
	Value = Seat("A2", "Normal", "A", 100)

	Key = "C1"
	Value = Seat("C1", "VIP", "A", 200)

	Key = "E1"
	Value = Seat("E1", "Couple", "A", 250)
*/
void SeatManagement::initSeatsMap_HashMap() {
	for (char row = 'A'; row <= 'E'; row++) {
		for (int number = 1; number <= 6; number++) {
			string seatID ="";
			seatID = row + to_string(number);

			string seatClass = "";
			float seatPrice = 0.0;

			if (row == 'A' || row == 'B') {
				seatClass = "Normal";
				seatPrice = 100;
			} else if (row == 'C' || row == 'D') {
				seatClass = "VIP";
				seatPrice = 200;
			} else {
				seatClass = "Couple";
				seatPrice = 250;
			}

			// Init object seat with infor and add Map
			Seat seat(seatID, seatClass, "A", seatPrice);	// A : Avaiable

			_seats[seatID] = seat;
		}
	}
}
// Display seat map for customer
void SeatManagement::displaySeatMap() {
	cout << "============== SEAT MAP ===============\n\n";

	for (char row = 'A'; row <= 'E'; row++) {
		cout << "  ";

		for (int number = 1; number <= 6; number++) {
			string seatID = "";
			seatID = string(1, row) + to_string(number);

			Seat &seat = _seats.at(seatID);		// Lay Seat co key bang seatID trong hashmap _seats

			cout << seat.getSeatID()
			     << "["
			     << seat.getStatus()
			     << "]   ";
		}

		cout << endl;
	}

	cout << "\n";
	cout << "A = Available\n";
	cout << "P = Pending\n";
	cout << "O = Ordered\n";
}
