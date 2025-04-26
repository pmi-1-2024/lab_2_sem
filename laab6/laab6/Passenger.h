#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
    Person() : name("default"), age(0) {}

    string get_type() const { return "Person"; }

    void print(ostream& out) const {
        out << name << " " << age;
    }
    void input(istream& in) {
        in >> name >> age;
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
