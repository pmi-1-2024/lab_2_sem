#ifndef CARGO_H
#define CARGO_H
#include <iostream>
#include <string>
using namespace std;

class Cargo
{
private:
    string name;
    double weight;
    string producing_country;
public:
    Cargo();
    Cargo(string n, double w, string p_c);

    string GetType();
    string GetName();
    string GetProdCountry();

    void SetName(string nname);
    void SetWeight(double w);
    void SetProd_country(string p_c);

    friend istream& operator>>(istream& is, Cargo& c);
    friend ostream& operator<<(ostream& os, const Cargo& c);
};
#endif

