#include "Passenger.h"

Passenger::Passenger() : name("noname"), age(0), zodiac_sign("nosing") {}

Passenger::Passenger(string n, int a, string zz) : name(n), age(a), zodiac_sign(zz) {}

string Passenger::GetType() {
    return "Passenger";
}

int Passenger::GetAge() {
    return age;
}

string Passenger::GetZS() {
    return zodiac_sign;
}

istream& operator>>(istream& is, Passenger& p) {
    is >> p.name >> p.age >> p.zodiac_sign;
    return is;
}

ostream& operator<<(ostream& os, const Passenger& p) {
    os << "\nName: " << p.name;
    os << "\nAge: " << p.age;
    os << "\nZodiac sign: " << p.zodiac_sign;
    return os;
}