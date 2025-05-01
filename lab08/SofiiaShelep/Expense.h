#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Expense {
    string date;
    string material;
    double volume;
    double cost;

    friend ostream& operator<<(ostream& os, const Expense& exp) {
        os << exp.date << " " << exp.material << " " << exp.volume << " " << exp.cost;
        return os;
    }
};