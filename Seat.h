#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

class Seat {
	private :
		string _seatID;    // A , B, C, D, E  1 -> 9
		string _seatClass; // 1: VIP       2: Normal       3: Couple
		string _status;    // A: Avaiable  O: Ordered      P: Pending
		float _seatPrice;  // 1: Vip = 200 2: Normal = 100 3: Couple = 250

	public :

		// Construct init
		Seat();
		Seat(string seatID, string seatClass, string status, float seatPrice);  // A: Avaiable ;  O: Ordered ;  P: Pending
		// Deconstruct init
		~Seat();

		// getter
		string getSeatID();
		string getSeatClass();
		string getStatus();		// A : avaiable , O : orderded , P : Pending
		float getSeatPrice();

		// setter
		void setSeatID(string seatID);
		void setSeatClass(string seatClass);
		void setStatus(string status);
		void setSeatPrice(float seatPrice);
};

#endif