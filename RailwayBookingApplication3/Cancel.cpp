#include "Cancel.h"

void Cancel::startCancel()
{
    int passId;
    int seat;
    std::string alloted;

    std::cout << "PassId: " << passId;
    std::cin >> passId;
    if(Book::ticketMap.find(passId) == Book::ticketMap.end())
    {
        std::cout << "Invalid ticket Id!!" << std::endl;
        return;
    }

    Passenger pass = Book::ticketMap[passId];
    seat = pass.get_seat();
    alloted = pass.get_alloted();
    Book::ticketMap.erase(passId); // removed from ticket map
    std::cout << "Cancelled Successfully!!" << std::endl;
    if(pass.get_alloted() == "L")
    {
        Book::avail_Lower++;
        Book::lower_seats.push_back(pass.get_seat());
    }else if(pass.get_alloted() == "M")
    {
        Book::avail_Middle++;
        Book::middle_seats.push_back(pass.get_seat());
    }else if(pass.get_alloted() == "U")
    {
        Book::avail_Upper++;
        Book::upper_seats.push_back(pass.get_seat());
    }
    if(!Book::rac_queue.empty())
    {
        Passenger& passFromRAC = Book::ticketMap[Book::rac_queue.front()];
        Book::rac_queue.pop();
        Book::avail_RAC++;
        Book::rac_seats.push_back(passFromRAC.get_seat());

        passFromRAC.set_seat(seat);
        passFromRAC.set_alloted(alloted);
        if(alloted == "L")
        {
            Book::avail_Lower--;
            Book::lower_seats.erase(Book::lower_seats.begin());
        }else if(alloted == "M")
        {
            Book::avail_Middle--;
            Book::middle_seats.erase(Book::middle_seats.begin());
        }else if(alloted == "U")
        {
            Book::avail_Upper--;
            Book::upper_seats.erase(Book::upper_seats.begin());
        }

        if(!Book::WL_queue.empty())
        {
            Passenger& passFromWL = Book::ticketMap[Book::WL_queue.front()];
            Book::WL_queue.pop();
            Book::rac_queue.push(passFromWL.get_passId());

            Book::avail_WL++;
            Book::WL_seats.push_back(passFromWL.get_seat());

            passFromWL.set_seat(Book::rac_seats[0]);
            passFromWL.set_alloted("RAC");
            Book::rac_seats.erase(Book::rac_seats.begin());
            Book::avail_RAC--;

        }
    }

}
