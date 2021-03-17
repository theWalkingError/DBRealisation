#include <iostream>
#include <vector>

#include "DataBase.h"

#ifndef AMS_H
#define AMS_H

using namespace std;

class AccountManagmentSystem : public DataBase
{
private:

	int numberOfBonuses = NULL;

public:

	int accountNumber = NULL;

	AccountManagmentSystem(int accountNumber)
		: accountNumber(accountNumber) {};

	float addBonuses(float numberOfBonuses)
	{
		this->numberOfBonuses += numberOfBonuses;
		return numberOfBonuses;
	}

	float deductBonuses(float numberOfBonuses)
	{
		this->numberOfBonuses -= numberOfBonuses;
		return numberOfBonuses;
	}

	float getNumberOfBonuses()
	{
		return numberOfBonuses;
	}

	//void setNumberOFBonuses(int number)
	//{
	//	this->numberOfBonuses += number;
	//}
};

#endif // !TDB_H
