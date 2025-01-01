#include <iostream>
#include <string>

#include "Book.h"
#include "Printer.h"
#include "Cancel.h"

using namespace std;

void module()
{
    cout << "*************************" << endl;
    cout << "1.Book" << endl;
    cout << "2.Cancel" << endl;
    cout << "3.Print booked tickets" << endl;
    cout << "4.Print available tickets" << endl;
    cout << "5.Exit" << endl;
}
int main()
{
    cout << "\t\tWelcome Railway Application!!" << endl;
    bool flag = true;
    int option = 0;
    while(flag)
    {
        module();
        cin >> option;
        switch(option)
        {
        case 1:
            {
                // book
                Book b;
                b.startBooking();
                break;
            }
        case 2:
            {
                // cancel
                Cancel c;
                c.startCancel();
                break;
            }
        case 3:
            {
                // print booked ticket
                Printer p1;
                p1.booked_tickets();
                break;
            }
        case 4:
            {
                // print available ticket
                Printer p;
                p.avail_tickets();
                break;
            }
        case 5:
            {
                // exit
                flag = false;
                break;
            }
        default:
            {
                cout << "Invalid try!!" << endl;
                break;
            }
        }
    }
    return 0;
}
