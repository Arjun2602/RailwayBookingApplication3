#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include <string>
class Passenger
{
private:
    int passId;
    std::string name;
    int age;
    char gender;
    std::string bp;

    std::string cName;
    int cAge;

    int seat;
    std::string alloted;

public:
    Passenger();
    Passenger(int passId,std::string name, int age, char gender, std::string bp, std::string cName, int cAge);

    // getter
    int get_passId();
    std::string get_name();
    int get_age();
    char get_gender();
    std::string get_bp();

    std::string get_cName();
    int get_cAge();

    int get_seat();
    std::string get_alloted();
    // setter

    void set_passId(int n);
    void set_name(std::string s);
    void set_age(int n);
    void set_gender(char c);
    void set_bp(std::string s);
    void set_cName(std::string s);
    void set_cAge(int n);
    void set_seat(int n);
    void set_alloted(std::string s);

};

#endif // PASSENGER_H_INCLUDED
