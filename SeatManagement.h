#ifndef SEAT_MANAGEMENT_H
#define SEAT_MANAGEMENT_H

#include <unordered_map>
#include "Seat.h"
#include "Customer.h"
using namespace std;

class SeatManagement {
	private:
		// Hash Map
		unordered_map<string, Seat> _seats; // string = key , Seat = Infor seat

		/*
			SINGLY LINKED LIST
			Waiting for payment
		*/
		struct Node {
			Customer customer;
			string seatID;
			Node *next;

			Node(Customer customer, string seatID) {
				this->customer = customer;
				this->seatID = seatID;
				this->next = nullptr;
			}
		};

		Node *headWaitList;
		Node *tailWaitList;

	public:
		// Helper functions
		void initSeatsMap_HashMap(); // Init seat map
		void displaySeatMap();

		// Constructor
		SeatManagement();

		// Deconstructor
		~SeatManagement();
};
#endif