#include "Customer.h"
// Construtor and destructor
Customer::Customer()
{
	_accountBalance = 0.0;
	_nameCustomer = "";
	_phoneNumber = ""; // Unique key
}

// Getter
float Customer::getAccountBalance()
{
	return _accountBalance;
}

string Customer::getNameCustomer()
{
	return _nameCustomer;
}

string Customer::getPhoneNumber()
{
	return _phoneNumber;
}

// Setter
void Customer::setAccountBalance(float monney)
{
	_accountBalance = monney;
}
void Customer::setNameCustomer(string nameCustomer)
{
	_nameCustomer = nameCustomer;
}
void Customer::setPhoneNumber(string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

// Method for customer
// Don't allow enter monney < 0
void Customer::deposit(float monney)
{
	if (monney <= 0)
	{
		return;
	}

	_accountBalance += monney;
}

// Don't allow enter monney < 0
bool Customer::pay(float monney)
{

	if (monney <= 0)
	{
		return false;
	}

	if (_accountBalance >= monney)
	{
		_accountBalance -= monney;
		return true;
	}

	return false;
}