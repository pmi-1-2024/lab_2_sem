#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
using namespace std;

class Expense {
private:
    string date;
    string material;
    double volume;
    double cost;

public:
    Expense();
    Expense(string date, string material, double volume, double cost);

    string getDate();
    string getMaterial();
    double getVolume();
    double getCost();

    void setDate(string date);
    void setMaterial(string material);
    void setVolume(double volume);
    void setCost(double cost);
};

#endif