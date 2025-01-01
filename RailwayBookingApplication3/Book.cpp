#include "Book.h"

// static member

int Book::id = 1;

int Book::avail_Lower = 1;
int Book::avail_Middle = 2;
int Book::avail_Upper = 1;
int Book::avail_RAC = 1;
int Book::avail_WL = 1;

std::map<int, Passenger> Book::ticketMap;

std::vector<int> Book::lower_seats = {1};
std::vector<int> Book::middle_seats = {1,2};
std::vector<int> Book::upper_seats = {1};
std::vector<int> Book::rac_seats = {1};
std::vector<int> Book::WL_seats = {1};

std::queue<int> Book::rac_queue;
std::queue<int> Book::WL_queue;
//*************

// book ticket
void Book::bookTicket(Passenger& p, std::string alloted, int seat)
{
    p.set_seat(seat);
    p.set_alloted(alloted);
    ticketMap[p.get_passId()] = p;
}

// process booking
void Book::processBooking(int passId, Passenger& p, bool hasChild)
{
    if(avail_WL == 0)
    {
        std::cout << "No Tickets Available!!" << std::endl;
        return;
    }
    if(p.get_age() < 5)
    {
        std::cout << "No Tickets Available for child below 5!!" << std::endl;
        ticketMap[passId] = p;
        return;
    }
    if( avail_Lower > 0 && (p.get_age() > 60 || (p.get_gender() == 'F' && hasChild)) )
    {
        std::cout << "Lower Berth will be allocated for person with age above 60 and ladies with children!!" << std::endl;
        bookTicket(p, "L", lower_seats[0]);
        avail_Lower--;
        lower_seats.erase(lower_seats.begin());
        std::cout << "Lower Berth alloted!!" << std::endl;
        return;
    }

    if(p.get_bp() == "L" || p.get_bp() == "M" || p.get_bp() == "U")
    {
        // prefferd berths
        if(p.get_bp() == "L" && avail_Lower > 0)
        {
            bookTicket(p, "L", lower_seats[0]);
            avail_Lower--;
            lower_seats.erase(lower_seats.begin());
            std::cout << "Lower Berth alloted!!" << std::endl;
            return;
        }else if(p.get_bp() == "M" && avail_Middle > 0)
        {
            bookTicket(p, "M", middle_seats[0]);
            avail_Middle--;
            middle_seats.erase(middle_seats.begin());
            std::cout << "Middle Berth alloted!!" << std::endl;
            return;
        }else if(p.get_bp() == "U" && avail_Upper > 0)
        {
            bookTicket(p, "U", upper_seats[0]);
            avail_Upper--;
            upper_seats.erase(upper_seats.begin());
            std::cout << "Upper Berth alloted!!" << std::endl;
            return;
        }
    }

    // not prefferd
    if(avail_Lower > 0)
    {
        bookTicket(p, "L", lower_seats[0]);
        avail_Lower--;
        lower_seats.erase(lower_seats.begin());
        std::cout << "Lower Berth alloted!!" << std::endl;
        return;
    }
    if(avail_Middle > 0)
    {
        bookTicket(p, "M", middle_seats[0]);
        avail_Middle--;
        middle_seats.erase(middle_seats.begin());
        std::cout << "Middle Berth alloted!!" << std::endl;
        return;
    }
    if(avail_Upper > 0)
    {
        bookTicket(p, "U", upper_seats[0]);
        avail_Upper--;
        upper_seats.erase(upper_seats.begin());
        std::cout << "Upper Berth alloted!!" << std::endl;
        return;
    }
    if(avail_RAC > 0)
    {
        bookTicket(p, "RAC", rac_seats[0]);
        avail_RAC--;
        rac_seats.erase(rac_seats.begin());
        rac_queue.push(passId);
        std::cout << "RAC alloted!!" << std::endl;
        return;
    }
    if(avail_WL > 0)
    {
        bookTicket(p, "WL", WL_seats[0]);
        avail_WL--;
        WL_seats.erase(WL_seats.begin());
        WL_queue.push(passId);
        std::cout << "WL alloted!!" << std::endl;
        return;
    }

    std::cout << "No Ticket Available!!" << std::endl;
    return;
}
void Book::startBooking()
{
    int passId = id;
    std::string name;
    int age;
    char gender;
    std::string bp;

    bool hasChild = false;

    std::string cName;
    int cAge;

    std::cout << "PassId: " << passId << std::endl;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Gender(M/F): ";
    std::cin >> gender;
    std::cout << "Berth Preference(L/M/U): ";
    std::cin >> bp;

    if(gender == 'F' || gender == 'f')
    {
        std::cout << "Has Child: ";
        std::cin >> hasChild;
        if(hasChild)
        {
            std::cout << "Child Name: ";
            std::cin >> cName;
            std::cout << "Child Age: ";
            std::cin >> cAge;

            Passenger p1(passId, name, age, gender, bp, cName, cAge);
            processBooking(passId, p1, hasChild);
        }else
        {
            // no child
            Passenger p2(passId, name, age, gender, bp, "", 0);
            processBooking(passId, p2, hasChild);
        }
    }else
    {
        // male
        Passenger p3(passId, name, age, gender, bp, "", 0);
        processBooking(passId, p3, hasChild);
    }
    id++;
}
