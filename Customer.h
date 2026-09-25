#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
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
		void setAccountBalance(float monney);
		void setNameCustomer(string nameCustomer);
		void setPhoneNumber(string phoneNumber);

		// Method
		void deposit(float monney);		// Deposit monney from customer
		void pay(float monney);			// Draw and pay from customer
};

#endif