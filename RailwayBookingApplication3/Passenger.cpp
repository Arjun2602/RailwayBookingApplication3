#include "Passenger.h"

Passenger::Passenger()
:passId(0),name(""),age(0),gender(' '),bp(""), cName(""), cAge(0), seat(0), alloted("")
{
}

Passenger::Passenger(int passId,std::string name, int age, char gender, std::string bp, std::string cName, int cAge)
{
    this->passId = passId;

    this->name = name;
    this->age = age;
    this->gender = gender;
    this->bp = bp;

    this->cName = cName;
    this->cAge = cAge;

    this->seat = 0;
    this->alloted = "";
}

// getter
int Passenger::get_passId()
{
    return passId;
}
std::string Passenger::get_name()
{
    return name;
}
int Passenger::get_age()
{
    return age;
}
char Passenger::get_gender()
{
    return gender;
}
std::string Passenger::get_bp()
{
    return bp;
}

std::string Passenger::get_cName()
{
    return cName;
}
int Passenger::get_cAge()
{
    return cAge;
}

int Passenger::get_seat()
{
    return seat;
}
std::string Passenger::get_alloted()
{
    return alloted;
}


// setter
void Passenger::set_passId(int n)
{
    passId = n;
}
void Passenger::set_name(std::string s)
{
    name = s;
}
void Passenger::set_age(int n)
{
    age = n;
}
void Passenger::set_gender(char c)
{
    gender = c;
}
void Passenger::set_bp(std::string s)
{
    bp = s;
}
void Passenger::set_cName(std::string s)
{
    cName = s;
}
void Passenger::set_cAge(int n)
{
    cAge = n;
}
void Passenger::set_seat(int n)
{
    seat = n;
}
void Passenger::set_alloted(std::string s)
{
    alloted = s;
}
