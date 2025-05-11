#include "Traveler.h"
#include "CustomException.h"

Traveler::Traveler() : full_name("noname"), years_old(0), nationality("unknown") {}

Traveler::Traveler(const string& name, int age, const string& nation) {
    if (name.empty()) throw CustomException("Name cannot be empty.");
    if (age < 0) throw CustomException("Age cannot be negative.");
    if (nation.empty()) throw CustomException("Nationality cannot be empty.");

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
    if (!is) throw std::runtime_error("Error reading Traveler from stream");
    return is;
}

ostream& operator<<(ostream& os, const Traveler& t) {
    os << "\nFull Name: " << t.full_name;
    os << "\nAge: " << t.years_old;
    os << "\nNationality: " << t.nationality;
    return os;
}