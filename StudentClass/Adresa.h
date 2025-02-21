#ifndef ADRESA_H
#define ADRESA_H

#include <string>
using namespace std;

class Adresa {
public:
    string index;
    string city;
    string street;
    Adresa();
    Adresa(string ind, string cit, string str);
    void input();
    void display() const;
    string GetIndex() const;
    string GetCity() const;
    string GetStreet() const;
};

#endif
