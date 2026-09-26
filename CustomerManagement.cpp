#include "CustomerManagement.h"
#include <iostream>

using namespace std;

// Constructor
CustomerManagement::CustomerManagement() {
}

// Create a new customer
bool CustomerManagement::createCustomer(string phoneNumber, string name) {
	// Check if phone number already exists
	if (_customers.find(phoneNumber) != _customers.end()) {
		return false;
	}

	// Create new Customer
	Customer customer;

	customer.setPhoneNumber(phoneNumber);
	customer.setNameCustomer(name);

	// Insert customer into Hash Table
	_customers[phoneNumber] = customer;

	return true;
}

// Find customer by phone number
Customer *CustomerManagement::findCustomer(string phoneNumber) {
	auto it = _customers.find(phoneNumber);

	// Customer not found
	if (it == _customers.end()) {
		return nullptr;
	}

	// Return address of Customer
	return &(it->second);
}

// Deposit money into customer's account
bool CustomerManagement::deposit(string phoneNumber, float money) {
	Customer *customer = findCustomer(phoneNumber);

	// Customer not found
	if (customer == nullptr) {
		return false;
	}

	// Deposit money
	customer->deposit(money);

	return true;
}

// Deduct money from customer's account
bool CustomerManagement::deductBalance(string phoneNumber, float money) {
	Customer *customer = findCustomer(phoneNumber);

	// Customer not found
	if (customer == nullptr) {
		return false;
	}

	// Pay / deduct money
	return customer->pay(money);
}

// Display one customer
void CustomerManagement::displayCustomer(string phoneNumber) {
	Customer *customer = findCustomer(phoneNumber);

	if (customer == nullptr) {
		cout << "Customer not found!" << endl;
		return;
	}

	cout << "===== CUSTOMER INFORMATION =====" << endl;
	cout << "Phone Number : " << customer->getPhoneNumber() << endl;
	cout << "Name         : " << customer->getNameCustomer() << endl;
	cout << "Balance      : " << customer->getAccountBalance() << endl;
}

// Display all customers
void CustomerManagement::displayAllCustomers() {
	if (_customers.empty()) {
		cout << "No customer found!" << endl;
		return;
	}

	cout << "===== CUSTOMER LIST =====" << endl;

	for (auto &pair : _customers) {
		Customer &customer = pair.second;

		cout << "-----------------------------" << endl;
		cout << "Phone Number : " << customer.getPhoneNumber() << endl;
		cout << "Name         : " << customer.getNameCustomer() << endl;
		cout << "Balance      : " << customer.getAccountBalance() << endl;
	}

	cout << "-----------------------------" << endl;
}