#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
private:
	float _accountBalance;
	string _nameCustomer;
	string _phoneNumber; // Unique key

public:
	// Constructor
	Customer();
	~Customer();

	// Getter
	float getAccountBalance();
	string getNameCustomer();
	string getPhoneNumber();

	// Setter
	void setAccountBalance(float Monney);
	void setNameCustomer(string nameCustomer);
	void setPhoneNumber(string phoneNumber);
};



#endif