#ifndef ADRESS_H
#define ADRESS_H

#include <string>
#include <iostream>
using namespace std;

class Adress {
    unsigned index;
    string city;
    string house;

public:
    Adress() : index(0), city(""), house("") {}
    Adress(unsigned index, string city, string house);
    void print();
    unsigned getIndex();
    string getCity();
    string getHouse();

    friend istream& operator>>(istream& is, Adress& adress);
    friend ostream& operator<<(ostream& os, const Adress& adress);
};

#endif
