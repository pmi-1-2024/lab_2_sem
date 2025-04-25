#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


class InvalidPersonDataException : public exception {
public:

    const char* what() const noexcept override {
        return "Invalid person data exception!";
    }
};

struct Person {
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {
        if (a < 0 || a > 120) {
            throw InvalidPersonDataException();
        }
    }

    Person() : name("default"), age(0) {}

    string get_type() const { return "Person"; }

    void print(ostream& out) const {
        out << name << " " << age;
    }

    void input(istream& in) {
        try {
            in >> name >> age;
            if (in.fail()) {
                throw invalid_argument("Failed to read name or age."); 
            }
            if (age < 0 || age > 120) {
                throw InvalidPersonDataException();
            }
        }
        catch (const exception& e) {
            cerr << "Error while reading input: " << e.what() << endl;
            throw;
        }
    }

    friend ostream& operator<<(ostream& out, const Person& p) {
        p.print(out);
        return out;
    }

    friend istream& operator>>(istream& in, Person& p) {
        p.input(in);
        return in;
    }
};

