#include "Seat.h"
#include <string>

// Constructor
Seat::Seat() {
	_seatID = "";
	_seatClass = "";
	_status = "A";		// Avaible
	_seatPrice = 0.0;
}

Seat::Seat(string seatID, string seatClass, string status, float seatPrice) {
	_seatID = seatID;
	_seatClass = seatClass;
	_status = status;
	_seatPrice = seatPrice;
}


// Getter
string Seat::getSeatID() {
	// A -> E, 1 -> 6
	return _seatID;
}
string Seat::getSeatClass() {
	// Vip , Normal , Couple
	return _seatClass;
}
string Seat::getStatus() {
	// A : avaible , O : orderded , P : Pending
	return _status;
}
float Seat::getSeatPrice() {
	// 1: Vip = 200 ; Normal = 100 ; Couple = 250
	return _seatPrice;
}

// Setter
void Seat::setSeatID(string seatID) {
	this->_seatID = seatID;
}
void Seat::setSeatClass(string seatClass) {
	this->_seatClass = seatClass;
}
void Seat::setStatus(string status) {
	this->_status = status;
}
void Seat::setSeatPrice(float seatPrice) {
	this->_seatPrice = seatPrice;
}