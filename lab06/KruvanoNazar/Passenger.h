#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <string>
using namespace std;
class Passenger
{
private:
    string name;
    int age;
    string zodiac_sign;
public:
    Passenger();
    Passenger(string n, int a, string zz);

    string GetType();
    int GetAge();
    string GetZS();

    friend istream& operator>>(istream& is, Passenger& p);
    friend ostream& operator<<(ostream& os, const Passenger& p);
};
#endif

