#pragma once
#include <string>
#include <iostream>
using namespace std;

class Material {
private:
    string date;
    string name;
    double volume;
    double cost;

public:
    Material();
    Material(const string&, const string&, double, double);

    string getDate() const;
    string getName() const;
    double getVolume() const;
    double getCost() const;

    void print(ostream&) const;
    bool operator<(const Material&) const;


    friend istream& operator>>(istream& in, Material& m);
    friend ostream& operator<<(ostream& out, const Material& m);
};
