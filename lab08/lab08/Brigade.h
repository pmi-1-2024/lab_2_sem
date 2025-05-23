#ifndef BRIGADE_H
#define BRIGADE_H

#include <string>
#include <deque>
#include "Expense.h"
using namespace std;

class Brigade {
private:
    int id;
    string brigadier;
    deque<Expense> exps;
    double totalCost;

public:
    Brigade();
    Brigade(int id, string brigadier);

    int getId();
    string getBrigadier();
    deque<Expense> getExp();
    double getTotal();

    void setId(int id);
    void setBrigadier(string brigadier);
    void addExp(Expense exp);
};

#endif