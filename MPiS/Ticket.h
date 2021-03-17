#include <string>
#include <time.h>

#ifndef TCT_H
#define TCT_H

using namespace std;

class Ticket
{
private:

	int ticketNumber = rand();

public:

	int type;
	string date;
	int classOfFlight;
	string owner;

	Ticket() {};

	Ticket(int type, string date, int classOfFlight, string owner, int ticketNumber)
		: type(type), date(date), classOfFlight(classOfFlight), owner(owner), ticketNumber(ticketNumber) 
	{
		srand(time(NULL));
	}

	int getTicketNumber()
	{
		return ticketNumber;
	}

};
#endif // !TCT_H
