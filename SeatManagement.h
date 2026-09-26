#ifndef SEAT_MANAGEMENT_H
#define SEAT_MANAGEMENT_H

#include <unordered_map>
#include "Seat.h"
#include "Customer.h"

using namespace std;

class SeatManagement
{
private:
	/*
		=========================
		HASH MAP
		"A1" -> Seat("A1", "Normal", "A", 100)
	*/
	unordered_map<string, Seat> _seats;

	/*
		=========================
		SINGLY LINKED LIST
		=========================
		Waiting for payment

		Each Node stores:
		- Customer
		- Movie ID
		- Seat ID
		- Next node
	*/
	struct Node
	{
		Customer customer;
		string movieID;
		string seatID;

		Node *next;

		// Auto fill infor when it is called
		Node(Customer customer, string movieID, string seatID)
		{
			this->customer = customer;
			this->movieID = movieID;
			this->seatID = seatID;
			this->next = nullptr;
		}
	};

	Node *headWaitList;
	Node *tailWaitList;

public:
	// Constructor
	SeatManagement();

	// Destructor
	~SeatManagement();

	// Initialize seat Hash Map
	void initSeatsMap_HashMap();

	// Display seat map
	void displaySeatMap();

	// Order seat
	bool orderSeat(string seatID);

	// Cancel seat
	bool cancelSeat(string seatID);

	// Add customer to waiting payment list
	bool addToWaitList(Customer customer, string movieID, string seatID);

	// Display waiting payment list
	void displayWaitList();
};

#endif