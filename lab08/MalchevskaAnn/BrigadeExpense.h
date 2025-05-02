#pragma once
#include <string>

using namespace std;

struct Material {
    string date;
    string name;
    double volume;
    double cost;
    friend ostream& operator<<(ostream& os, const Material& mat);
    friend istream& operator>>(istream& is, Material& mat);
    friend bool operator==(const Material& a, const Material& b);
};

struct Foreman {
    string name;
    int age;
    friend ostream& operator<<(ostream& os, const Foreman& foreman);
    friend istream& operator>>(istream& is, Foreman& foreman);
    friend bool operator==(const Foreman& a, const Foreman& b);
};

struct BrigadeExpense {
    int brigadeNumber;
    Foreman foreman;
    Material material;
    friend ostream& operator<<(ostream& os, const BrigadeExpense& exp);
    friend istream& operator>>(istream& is, BrigadeExpense& exp);
    friend bool operator==(const BrigadeExpense& a, const BrigadeExpense& b);
};
