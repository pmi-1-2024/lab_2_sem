#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Freight {
private:
    string item_name;
    double mass;
    string origin_country;
public:
    Freight();
    Freight(const string& name, double m, const string& origin);

    string GetCategory() const;
    string GetName() const;
    string GetOrigin() const;

    void SetName(const string& name);
    void SetMass(double m);
    void SetOrigin(const string& origin);

    friend istream& operator>>(istream& is, Freight& f);
    friend ostream& operator<<(ostream& os, const Freight& f);
};