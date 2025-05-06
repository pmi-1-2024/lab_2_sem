#include "Passenger.h"

Passenger::Passenger() : name(""), age(0) {}
Passenger::Passenger(string name, int age) : name(name), age(age) {}

string Passenger::getName() const { return name; }
int Passenger::getAge() const { return age; }

ostream& operator<<(ostream& os, const Passenger& p) {
    os << "Passenger: " << p.name << ", Age: " << p.age;
    return os;
}