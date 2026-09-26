#include <iostream>
#include "SeatManagement.h"
#include "CustomerManagement.h"
#include "Movie.h"

using namespace std;

enum MenuChoice
{
	DISPLAY_MOVIE_LIST = 1,
	ORDER_SEAT,
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

void Menu()
{
	cout << "\n========== MOVIE THEATER ==========\n";

	cout << "\n------------ MOVIE ----------------\n";
	cout << "1. Display movie list\n";
	cout << "2. Order seat\n";
	cout << "3. Cancel seat\n";

	cout << "\n------------ PAYMENT --------------\n";
	cout << "4. Awaiting Payment List\n";
	cout << "5. Payment Confirmation\n";

	cout << "\n------------ TICKET ---------------\n";
	cout << "6. Print Ticket\n";

	cout << "\n------------ CUSTOMER -------------\n";
	cout << "7. Create account\n";
	cout << "8. Show Customer Information\n";
	cout << "9. Show Account Balance\n";
	cout << "10. Deposit Money\n";

	cout << "\n11. Exit\n";
}

// Each Movie have seat map it self
Movie movieList[4] = {
	Movie("M01", "Avengers", "18:00"),
	Movie("M02", "Superman", "19:30"),
	Movie("M03", "Spider-Man", "21:00"),
	Movie("M04", "Batman", "22:30")};

int chooseMovie()
{
	cout << "\n========== MOVIE LIST ==========\n";

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << ". "
			 << movieList[i].getMovieID()
			 << " - "
			 << movieList[i].getNameMovie()
			 << " - "
			 << movieList[i].getTime()
			 << endl;
	}

	int choice;

	cout << "Choose movie: ";
	cin >> choice;

	if (choice < 1 || choice > 4)
	{
		return -1;
	}

	return choice - 1;
}

int main()
{
	CustomerManagement cM;

	int choice;

	do
	{
		Menu();

		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case DISPLAY_MOVIE_LIST:
		{
			for (int i = 0; i < 4; i++)
			{
				cout << movieList[i].getMovieID()
					 << " - "
					 << movieList[i].getNameMovie()
					 << " - "
					 << movieList[i].getTime()
					 << endl;
			}

			break;
		}

		case CREATE_ACCOUNT:
		{
			string phoneNumber = "";
			string name = "";

			cout << "Enter phone number: ";
			cin >> phoneNumber;

			cout << "Enter name: ";
			cin >> name;

			if (cM.createCustomer(phoneNumber, name))
			{
				cout << "Create account successfully!\n";
			}
			else
			{
				cout << "Phone number already exists!\n";
			}

			break;
		}

		case SHOW_CUSTOMER_INFORMATION:
		{
			string phoneNumber = "";

			cout << "Enter phone number: ";
			cin >> phoneNumber;

			cM.displayCustomer(phoneNumber);

			break;
		}

		case EXIT:
		{
			cout << "Goodbye!\n";
			break;
		}

		default:
		{
			cout << "Invalid choice!\n";
			break;
		}
		}

	} while (choice != EXIT);

	return 0;
}