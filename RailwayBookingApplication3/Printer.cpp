#include "Printer.h"

void Printer::booked_tickets()
{
    for(auto it = Book::ticketMap.begin(); it != Book::ticketMap.end(); it++)
    {
        Passenger p = it->second;
        std::cout << "***************************" << std::endl;
        std::cout << "PassId:       " << p.get_passId() << std::endl;
        std::cout << "Name:         " << p.get_name() << std::endl;
        std::cout << "Age:          " << p.get_age() << std::endl;
        std::cout << "Gender:       " << p.get_gender() << std::endl;
        std::cout << "BP:           " << p.get_bp() << std::endl;
        std::cout << "seatAlloted:  " << p.get_seat() << p.get_alloted() << std::endl;
    }
}

void Printer::avail_tickets()
{
    std::cout << "Lower:        " << Book::avail_Lower << std::endl;
    std::cout << "Middle:       " << Book::avail_Middle << std::endl;
    std::cout << "Upper:        " << Book::avail_Upper << std::endl;
    std::cout << "RAC:          " << Book::avail_RAC << std::endl;
    std::cout << "WL:           " << Book::avail_WL << std::endl;
}
