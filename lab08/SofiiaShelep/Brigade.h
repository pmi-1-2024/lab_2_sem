#pragma once
#include <string>
#include <list>
#include "Expense.h"

using namespace std;

struct Brigade {
    int number;
    string foreman;
    list<Expense> expenses;

    double totalCost() const {
        double total = 0;
        for (const auto& exp : expenses)
            total += exp.cost;
        return total;
    }

    friend ostream& operator<<(ostream& os, const Brigade& b) {
        os << b.number << " " << b.foreman << " ";
        for (const auto& exp : b.expenses)
            os << exp << " ";
        return os;
    }

    bool operator<(const Brigade& other) const {
        return foreman < other.foreman;
    }

    bool operator==(const Brigade& other) const {
        return number == other.number && foreman == other.foreman;
    }

    bool operator!=(const Brigade& other) const {
        return !(*this == other);
    }

    bool operator>(const Brigade& other) const {
        return foreman > other.foreman;
    }
};