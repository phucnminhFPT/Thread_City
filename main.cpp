#include <iostream>
#include "SeatManagement.h"
#include "CustomerManagement.h"
#include "Movie.h"
#include "MenuHandler.h"

using namespace std;

enum MenuChoice {
	ORDER_SEAT = 1,
	CANCEL_SEAT,

	AWAITING_PAYMENT_LIST,
	PAYMENT_CONFIRMATION,

	PRINT_TICKET,

	CREATE_ACCOUNT,
	SHOW_CUSTOMER_INFORMATION,
	SHOW_ACCOUNT_BALANCE,
	DEPOSIT_MONEY,

	EXIT
};

// Each Movie have seat map it self
/*
movieList[0] → Avengers → SeatManagement #1
movieList[1] → Superman → SeatManagement #2
movieList[2] → Spider-Man → SeatManagement #3
movieList[3] → Batman → SeatManagement #4
*/

void Menu() {
	cout << "\n========== MENU ==========\n";
	cout << "1. Order seat\n";
	cout << "2. Cancel seat\n";

	cout << "\n------------ PAYMENT --------------\n";
	cout << "3. Awaiting Payment List\n";
	cout << "4. Payment Confirmation\n";

	cout << "\n------------ TICKET ---------------\n";
	cout << "5. Print Ticket\n";

	cout << "\n------------ CUSTOMER -------------\n";
	cout << "6. Create account\n";
	cout << "7. Show Customer Information\n";
	cout << "8. Show Account Balance\n";
	cout << "9. Deposit Money\n";

	cout << "\n10. Exit\n";
}

int main() {
	CustomerManagement cM;

	int choice;

	do {
		Menu();

		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
			case ORDER_SEAT: {
				orderSeatFlow(cM);
				break;
			}
			case CREATE_ACCOUNT: {
				string phoneNumber = "";
				string name = "";

				cout << "Enter phone number: ";
				cin >> phoneNumber;

				cout << "Enter name: ";
				cin >> name;

				if (cM.createCustomer(phoneNumber, name)) {
					cout << "Create account successfully!\n";
				} else {
					cout << "Phone number already exists!\n";
				}

				break;
			}

			case SHOW_CUSTOMER_INFORMATION: {
				string phoneNumber = "";

				cout << "Enter phone number: ";
				cin >> phoneNumber;

				cM.displayCustomer(phoneNumber);

				break;
			}

			case EXIT: {
				cout << "Goodbye!\n";
				break;
			}

			default: {
				cout << "Invalid choice!\n";
				break;
			}
		}

	} while (choice != EXIT);

	return 0;
}