#include "Traveler.h"


Traveler::Traveler() : full_name("noname"), years_old(0), nationality("unknown") {}

Traveler::Traveler(const string& name, int age, const string& nation) {


    full_name = name;
    years_old = age;
    nationality = nation;
}

string Traveler::GetCategory() const {
    return "Traveler";
}

int Traveler::GetAge() const {
    return years_old;
}

string Traveler::GetNationality() const {
    return nationality;
}

istream& operator>>(istream& is, Traveler& t) {
    is >> t.full_name >> t.years_old >> t.nationality;
    return is;
}

ostream& operator<<(ostream& os, const Traveler& t) {
    os << "\nFull Name: " << t.full_name;
    os << "\nAge: " << t.years_old;
    os << "\nNationality: " << t.nationality;
    return os;
}