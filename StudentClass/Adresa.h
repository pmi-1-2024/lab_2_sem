#ifndef ADRESA_H
#define ADRESA_H
#include <string>
using namespace std;

class Adresa {
private:
    string index;
    string city;
    string street;
public:
    Adresa();
    Adresa(string ind, string cit, string str);
    string GetIndex() const;
    string GetCity() const;
    string GetStreet() const;
    friend istream& operator>>(istream& is, Adresa& adr);
    friend ostream& operator<<(ostream& os, const Adresa& adr);
};

#endif
