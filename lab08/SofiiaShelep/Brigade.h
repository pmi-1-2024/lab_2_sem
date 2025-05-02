#pragma once
#include <string>
#include <list>
#include <iostream>
#include "Expense.h"

using namespace std;

class Brigade {
private:
    int number;
    string foreman;
    list<Expense> expenses;

public:
    Brigade() : number(0), foreman("") {}

    Brigade(int num, const string& f) : number(num), foreman(f) {}

    int getNumber() const { return number; }
    void setNumber(int num) { number = num; }

    string getForeman() const { return foreman; }
    void setForeman(const string& f) { foreman = f; }

    const list<Expense>& getExpenses() const { return expenses; }
    void addExpense(const Expense& expense) { expenses.push_back(expense); }

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
