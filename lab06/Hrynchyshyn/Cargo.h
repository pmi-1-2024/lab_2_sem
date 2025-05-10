#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Cargo {
    string name;
    string specialCondition;

public:
    Cargo() : name(""), specialCondition("none") {}
    Cargo(string n, string sc) : name(n), specialCondition(sc) {}

    string getName() const { return name; }
    string getSpecialCondition() const { return specialCondition; }

    void setName(const string& n) { name = n; }
    void setSpecialCondition(const string& sc) { specialCondition = sc; }

friend istream& operator>>(istream& in, Cargo& c) {
        c.load(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Cargo& c) {
        c.save(out);
        return out;
    }
    
    bool operator==(const Cargo& other) const {
        return name == other.name && specialCondition == other.specialCondition;
    }

    void save(ostream& out) const {
        out << name << "\n" << specialCondition << "\n";
    }

    void load(istream& in) {
        in.ignore();
        getline(in, name);
        getline(in, specialCondition);
    }
};