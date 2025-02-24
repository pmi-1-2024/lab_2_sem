#ifndef ADRESS_H
#define ADRESS_H
#include <iostream>
#include <string>

using namespace std;

class Adress {
private:
    string postIndex, city, street;
public:
    Adress(string postIndex = "", string city = "", string street = "")
        : postIndex(postIndex), city(city), street(street) {}

    friend ostream& operator<<(ostream& os, const Adress& adr);
    friend istream& operator>>(istream& is, Adress& adr);
};

#endif
