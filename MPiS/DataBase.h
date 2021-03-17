#include <vector>
#include <string>

#ifndef DB_H
#define DB_H

using namespace std;

class DataBase
{
private:

	vector <string> scheduleOfFlights;
	int numberOfFreeSeats;

public:

	DataBase() {};

	DataBase(vector <string> flights, int seats)
		: scheduleOfFlights(flights), numberOfFreeSeats (seats){};

};


#endif // !DB_H
