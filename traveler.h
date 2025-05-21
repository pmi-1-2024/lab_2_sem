#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Traveler {
private:
    string full_name;
    int years_old;
    string nationality;
public:
    Traveler();
    Traveler(const string& name, int age, const string& nation);

    string GetCategory() const;
    int GetAge() const;
    string GetNationality() const;

    friend istream& operator>>(istream& is, Traveler& t);
    friend ostream& operator<<(ostream& os, const Traveler& t);
};