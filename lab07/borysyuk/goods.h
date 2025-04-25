#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Goods {
    string name;
    int amount;
    int price;
    bool fragile;
    bool medical;

    Goods(string n, int a, int p, bool f = false, bool m = false)
        : name(n), amount(a), price(p), fragile(f), medical(m) {}

    Goods() : name("default"), amount(0), price(0), fragile(false), medical(false) {}

    string get_type() const { return "Goods"; }

    void print(ostream& out) const {
        out << name << " " << amount << " " << price << " " << fragile << " " << medical;
    }
    void input(istream& in) {
        in >> name >> amount >> price >> fragile >> medical;
    }

    friend ostream& operator<<(ostream& out, const Goods& g) {
        g.print(out);
        return out;
    }

    friend istream& operator>>(istream& in, Goods& g) {
        g.input(in);
        return in;
    }
};