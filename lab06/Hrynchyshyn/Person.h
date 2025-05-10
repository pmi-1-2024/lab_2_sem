#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Person {
    string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

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
        out << name << "\n" << age << "\n";
    }

    void load(istream& in) {
        in.ignore();
        getline(in, name);
        in >> age;
    }
};