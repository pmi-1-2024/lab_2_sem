#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    std::string name;

public:
    Person() : name("Unknown") {}
    Person(std::string n) : name(n) {}

    std::string getName() const { return name; }
    void setName(const std::string& n) { name = n; }

    friend std::istream& operator>>(std::istream& in, Person& person) {
        in >> person.name;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Person& person) {
        out << person.name;
        return out;
    }
};

#endif

