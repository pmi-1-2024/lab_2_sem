#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "TransportException.h"

using namespace std;

class Person {
    string name;
    int age;

public:
    Person() : name(""), age(0) {}

    Person(string n, int a) {
        if (n.empty()) {
            throw invalid_argument("Person name cannot be empty at construction.");
        }
        name = n;

        if (a < 0 || a > 150) {
            throw out_of_range("Age must be real.");
        }
        age = a;
    }

    string getName() const { return name; }
    int getAge() const { return age; }

    void setName(const string& n) { name = n; }
    void setAge(int a) { age = a; }

    friend istream& operator>>(istream& in, Person& p) {
        p.load(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Person& p) {
        p.save(out);
        return out;
    }

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }

    void save(ostream& out) const {
        if (out.fail()) {
            throw ios_base::failure("Output stream failure before saving Person.");
        }
        out << name << "\n" << age << "\n";
        if (out.fail()) {
            throw ios_base::failure("Output stream failure after saving Person.");
        }

    }

    void load(istream& in) {
        string tempName;
        getline(in, tempName);
        if (in.fail()) {
            throw ios_base::failure("File Error: Error reading person name from file.");
        }
        if (tempName.empty()) {
            throw TransportException("File Error: Loaded person name is empty.");
        }
        name = tempName;

        int tempAge;
        in >> tempAge;
        if (in.fail()) {
            in.clear();
            in.ignore();
            throw ios_base::failure("File Error: Error reading age from file or invalid age format.");
        }
        if (tempAge < 0 || tempAge > 150) {
            in.ignore();
            throw TransportException("File Error: Invalid age value (" + to_string(tempAge) + ") loaded from file.");
        }
        age = tempAge;
        in.ignore();
    }
};