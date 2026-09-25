#include <iostream>
#include "SeatManagement.h"
#include "Movie.h"
using namespace std;

enum MenuChoice {
	DISPLAY_MOVIE_LIST = 1, // 1
	DISPLAY_SEAT_MAP,		// 2
	ORDER_SEAT,				// 3
	CANCEL_SEAT,			// 4

	AWAITING_PAYMENT_LIST, // 5
	PAYMENT_CONFIRMATION,  // 6

	PRINT_TICKET, // 7

	CREATE_ACCOUNT,			   // 8
	SHOW_CUSTOMER_INFORMATION, // 9
	SHOW_ACCOUNT_BALANCE,	   // 10
	DEPOSIT_MONEY,			   // 11

	EXIT // 12
};

// Menu for customer choice
void Menu() {
	cout << "\n========== MOVIE THEATER ==========\n";

	cout << "\n------------ MOVIE ----------------\n";
	cout << "1. Display movie list\n";
	cout << "2. Display seatmap\n";
	cout << "3. Order seat\n";
	cout << "4. Cancel seat\n";

	cout << "\n------------ PAYMENT --------------\n";
	cout << "5. Awaiting Payment List\n";
	cout << "6. Payment Confirmation\n";

	cout << "\n------------ TICKET ---------------\n";
	cout << "7. Print Ticket\n";

	cout << "\n------------ CUSTOMER -------------\n";
	cout << "8. Create account\n";
	cout << "9. Show Customer Information\n";
	cout << "10. Show Account Balance\n";
	cout << "11. Deposit Money\n";

	cout << "\n12. Exit\n";
}

// Danh sach phim Movie
Movie movieList[4] = {
	Movie("M01", "Avengers", "18:00"),
	Movie("M02", "Superman", "19:30"),
	Movie("M03", "Spider-Man", "21:00"),
	Movie("M04", "Batman", "22:30")
};

int main() {
	SeatManagement sM;
	sM.displaySeatMap();
	int choice;

	// do
	// {
	// 	Menu();

	// 	cout << "\nEnter your choice: ";
	// 	cin >> choice;

	// 	switch (choice)
	// 	{

	// 		/*------------ MOVIE ----------------*/

	// 	case DISPLAY_MOVIE_LIST: // 1. Display movie list
	// 		cout << "\n========== MOVIE LIST ==========\n";

	// 		for (int i = 0; i < 4; i++)
	// 		{
	// 			cout << movieList[i].getMovieID() << " | "
	// 				 << movieList[i].getNameMovie() << " | "
	// 				 << movieList[i].getTime() << "\n";
	// 		}

	// 		break;

	// 	case DISPLAY_SEAT_MAP: // 2. Display seatmap
	// 		seatManagement.displaySeatMap();
	// 		break;

	// 	case ORDER_SEAT:
	// 	{ // 3. Order seat
	// 		string seatID;

	// 		cout << "Enter seat ID: ";
	// 		cin >> seatID;

	// 		seatManagement.orderSeat(seatID);
	// 		break;
	// 	}

	// 	case CANCEL_SEAT:
	// 	{ // 4. Cancel seat
	// 		string seatID;

	// 		cout << "Enter seat ID: ";
	// 		cin >> seatID;

	// 		seatManagement.cancelSeat(seatID);
	// 		break;
	// 	}

	// 		/*------------ PAYMENT --------------*/

	// 	case AWAITING_PAYMENT_LIST: // 5. Awaiting Payment List
	// 		cout << "Awaiting Payment List\n";
	// 		break;

	// 	case PAYMENT_CONFIRMATION: // 6. Payment Confirmation
	// 		cout << "Payment Confirmation\n";
	// 		break;

	// 		/*------------ TICKET ---------------*/

	// 	case PRINT_TICKET: // 7. Print Ticket
	// 		cout << "Print Ticket\n";
	// 		break;

	// 		/*------------ CUSTOMER -------------*/

	// 	case CREATE_ACCOUNT: // 8. Create account
	// 		cout << "Create account\n";
	// 		break;

	// 	case SHOW_CUSTOMER_INFORMATION: // 9. Show Customer Information
	// 		cout << "Show Customer Information\n";
	// 		break;

	// 	case SHOW_ACCOUNT_BALANCE: // 10. Show Account Balance
	// 		cout << "Show Account Balance\n";
	// 		break;

	// 	case DEPOSIT_MONEY: // 11. Deposit Money
	// 		cout << "Deposit Money\n";
	// 		break;

	// 		/*------------ EXIT -----------------*/

	// 	case EXIT: // 12. Exit
	// 		cout << "Goodbye!\n";
	// 		break;

	// 	default:
	// 		cout << "Invalid choice!\n";
	// 		break;
	// 	}

	// } while (choice != EXIT);

	return 0;
}