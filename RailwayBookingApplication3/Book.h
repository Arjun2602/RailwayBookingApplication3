#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include "Passenger.h"
class Book
{
public:
    // static member

    static int id;

    static int avail_Lower;
    static int avail_Middle;
    static int avail_Upper;
    static int avail_RAC;
    static int avail_WL;

    static std::map<int, Passenger> ticketMap;

    static std::vector<int> lower_seats;
    static std::vector<int> middle_seats;
    static std::vector<int> upper_seats;
    static std::vector<int> rac_seats;
    static std::vector<int> WL_seats;

    static std::queue<int> rac_queue;
    static std::queue<int> WL_queue;
    //****************

    void startBooking();
    void processBooking(int passId, Passenger& p, bool hasChild);

    void bookTicket(Passenger& p, std::string alloted, int seat);
};

#endif // BOOK_H_INCLUDED
