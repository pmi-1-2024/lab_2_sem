#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cargo
{
private:
    string type;
    double weight;
public:
    Cargo() : type("Unknown"), weight(0.0) {}
    Cargo(string name, double weight) : type(name), weight(weight) {}

    friend istream& operator>>(istream& in, Cargo& c);
    friend ostream& operator<<(ostream& out, const Cargo& c);
};
