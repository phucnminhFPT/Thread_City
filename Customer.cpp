#include "Customer.h"

// Getter
float Customer::getAccountBalance() {
	return _accountBalance;
}

string Customer::getNameCustomer() {
	return _nameCustomer;
}

string Customer::getPhoneNumber() {
	return _phoneNumber;
}

// Setter
void Customer::setAccountBalance(float Monney) {
	_accountBalance = Monney;
}
void Customer::setNameCustomer(string nameCustomer) {
	_nameCustomer = nameCustomer;
}
void Customer::setPhoneNumber(string phoneNumber) {
	_phoneNumber = phoneNumber;
}
