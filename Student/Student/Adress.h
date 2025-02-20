#ifndef ADRESS_H
#define ADRESS_H

#include <string>
using namespace std;

class Adress {
    unsigned index;
    string city;
    string house;

public:
    Adress(unsigned index, string city, string house);
    void print();
    unsigned getIndex();
    string getCity();
    string getHouse();
};

#endif