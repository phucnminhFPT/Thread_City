#ifndef CUSTOMERMANAGEMENT_H
#define CUSTOMERMANAGEMENT_H
#include "Customer.h"
#include <unordered_map>

using namespace std;
class CustomerManagement {
	private:
		unordered_map<string, Customer> _customers;

	public:
		// Construct
		CustomerManagement();

		// Method and function helper
		bool createCustomer(string phoneNumber, string name);
		Customer *findCustomer(string phoneNumber);
		bool deposit(string phoneNumber, float money);
		bool deductBalance(string phoneNumber, float money);
		void displayCustomer(string phoneNumber);
		void displayAllCustomers();
};

#endif
