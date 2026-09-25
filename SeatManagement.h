#ifndef SEAT_MANAGEMENT_H
#define SEAT_MANAGEMENT_H

#include <unordered_map>
#include <Seat.h>
using namespace std;

class SeatManagement
{
private:
	unordered_map<string, Seat> _seats;

public:
};
#endif