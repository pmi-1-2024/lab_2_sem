#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


class InvalidGoodsDataException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid goods data exception!";
    }
};

struct Goods {
    string name;
    int amount;
    int price;
    bool fragile;
    bool medical;

    Goods(string n, int a, int p, bool f = false, bool m = false)
        : name(n), amount(a), price(p), fragile(f), medical(m) {
        if (a < 0) {
            throw InvalidGoodsDataException();  
        }
        if (p < 0) {
            throw InvalidGoodsDataException();  
        }
    }

    Goods() : name("default"), amount(0), price(0), fragile(false), medical(false) {}

    string get_type() const { return "Goods"; }

    void print(ostream& out) const {
        out << name << " " << amount << " " << price << " " << fragile << " " << medical;
    }

    void input(istream& in) {
        try {
            in >> name >> amount >> price >> fragile >> medical;
            if (in.fail()) {
                throw invalid_argument("Failed to read name, amount, price, fragile or medical."); 
            }
            if (amount < 0 || price < 0) {
                throw InvalidGoodsDataException(); 
            }
        }
        catch (const exception& e) {
            cerr << "Error while reading input: " << e.what() << endl;
            throw;  
        }
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
