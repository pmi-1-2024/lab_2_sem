#pragma once
#include <iostream>
#include <string>
using namespace std;

class Passenger {
private:
    string name;
    int age;
public:
    Passenger();
    Passenger(string name, int age);

    string getName() const;
    int getAge() const;

    friend ostream& operator<<(ostream& os, const Passenger& p);
};