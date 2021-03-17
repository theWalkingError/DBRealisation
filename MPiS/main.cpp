#include <iostream>
#include <string>

#include "DataBase.h"
#include "AMS.h"
#include "TDB.h"
#include "Ticket.h"

int main()
{

    TicketDataBase* TDB;

    enum Action
    {
        BONUSES = 1, 
        TICKET
    };

    int act;
    cout << "What do you want? (1 - check bonuses, 2 - order a ticket): ";
    cin >> act;

    switch (act)
    {
        case BONUSES:
            {
                int an;
                cout << "Enter account number you want to work with: ";
                cin >> an;

                AccountManagmentSystem* account = new AccountManagmentSystem(an);

                do {
                    int bon;
                    cout << "Add bonuses(1) | Deduct bonuses(2) | Check the number of bonuses(3): ";
                    cin >> bon;

                    switch (bon)
                    {
                        case 1:
                        {
                            int num;
                            cout << "How many bonuses do you want to add: ";
                            cin >> num;
                            account->addBonuses(num);
                            cout << num << " bonuses were added to the account [" << account->accountNumber << "]" << endl;
                        
                        }
                        break;

                        case 2:
                        {
                            int b;
                            cout << "How many bonuses do you want to deduct: ";
                            cin >> b;
                            account->deductBonuses(b);
                            cout << b << " bonuses were deducted from the account[" << account->accountNumber << "]" << endl; 
                        }
                        break;

                        case 3:
                        {
                            cout << "Number of bonuses on the account [" << account->accountNumber << "]:" << account->getNumberOfBonuses() << endl;
                        }
                        break;
                    }

                } while (true);

                delete account;
                break;
            }
        
        case TICKET:
            {
            Ticket* ticket = new Ticket();
            cout << "Create new ticket order. Enter information:" << endl;
            cout << "Enter date: ";
            string date;
            cin >> date;
            ticket->date = date;

            cout << "Enter type(1 or 2): ";
            int type;
            cin >> type;
            ticket->type = type;

            cout << "Enter class(1 or 2): ";
            int class_flight;
            cin >> class_flight;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ticket->classOfFlight = class_flight;

            cout << "Enter your first and second name: ";
            string name;
            getline(cin, name);
            ticket->owner = name;

            TDB = new TicketDataBase(ticket);
            TDB->createNewOrder(ticket);

            cout << "\n\tOrder was created. Chech information once again.\n" << endl;
            TDB->showTicketInfo();

            delete ticket;
            break;
            }
    }

    return 0;
}