#include <iostream>

#include "DataBase.h"
#include "Ticket.h"

#ifndef TDB_H
#define TDB_H

using namespace std;

class TicketDataBase: public DataBase
{
private:

	Ticket* ticket;
	int numberOfOrderedTickets;

public:

	TicketDataBase(Ticket* ticket)
		: ticket(ticket) {};

	bool createNewOrder(Ticket* ticket) 
	{
		return numberOfOrderedTickets++;
	}

	Ticket changeTicket(Ticket* ticket)
	{
		string obj;
		cout << "What do you want to change(date, type or class): ";
		cin >> obj;

		if (obj == "date")
		{
			string date;
			cout << "Enter new date(MMDDYY): ";
			cin >> date;
			ticket->date = date;
		}
		else if (obj == "type")
		{
			int type;
			cout << "Enter new type(1 or 2): ";
			cin >> type;
			ticket->type = type;
		}
		else if (obj == "class")
		{
			int class_flight;
			cout << "Enter new class(1 or 2):";
			cin >> class_flight;
			ticket->classOfFlight = class_flight;
		}
		else
		{
			cout << "Something went wrong. Try Again." << endl;
		}

		return *ticket;
	}

	void showTicketInfo()
	{
		cout << "Ticket information" << endl;
		cout << "Date of flight:\n " << 
			"\tDay: " << ticket->date.substr(0, 2) <<
			"\n\tMonth: " << ticket->date.substr(2, 2) <<
			"\n\tYear: " << ticket->date.substr(4, 6) << endl;
		cout << "Type of flight: " << ticket->type << endl;
		cout << "Class of flight: " << ticket->classOfFlight << endl;
		cout << "Owner of ticket is " << ticket->owner << endl;
	}

};

#endif // !TDB_H
