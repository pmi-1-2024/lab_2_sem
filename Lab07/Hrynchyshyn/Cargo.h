#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "TransportException.h"

using namespace std;

class Cargo {
    string name;
    string specialCondition;

public:
    Cargo() : name(""), specialCondition("none") {} 
    Cargo(string n, string sc) {
        if (n.empty()) {
            throw invalid_argument("Cargo name cannot be empty at construction.");
        } name = n;

        if (sc != "medicine" && sc != "urgent" && sc != "fragile" && sc != "none") {
            throw TransportException("Invalid special condition at construction: " + sc + ". Allowed: medicine, urgent, fragile, none.");
        }
        specialCondition = sc;
    }

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
        if (out.fail()) {
            throw ios_base::failure("Output stream failure before saving Cargo.");
        }
        out << name << "\n" << specialCondition << "\n";
        if (out.fail()) {
            throw ios_base::failure("Output stream failure after saving Cargo.");
        }
    }

    void load(istream& in) {
        string tempName;
        getline(in, tempName);
        if (in.fail()) {
            throw ios_base::failure("File Error: Error reading cargo name from file.");
        }
        if (tempName.empty()) {
            throw TransportException("File Error: Loaded cargo name is empty.");
        }
        name = tempName;
        string tempSc;
        getline(in, tempSc);
        if (in.fail()) {
            throw ios_base::failure("File Error: Error reading special condition from file.");
        }
        if (tempSc != "medicine" && tempSc != "urgent" && tempSc != "fragile" && tempSc != "none") {
            throw TransportException("File Error: Loaded invalid special condition '" + tempSc + "'.");
        }
        specialCondition = tempSc;
    }
};