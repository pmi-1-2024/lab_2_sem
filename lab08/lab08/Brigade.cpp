#include "Brigade.h"

Brigade::Brigade() : id(0), brigadier(""), totalCost(0) {}
Brigade::Brigade(int id, string brigadier) :
    id(id), brigadier(brigadier), totalCost(0) {}

int Brigade::getId() {
    return id;
}
string Brigade::getBrigadier() {
    return brigadier;
}
deque<Expense> Brigade::getExp() {
    return exps;
}
double Brigade::getTotal() {
    return totalCost;
}

void Brigade::setId(int id) {
    this->id = id;
}
void Brigade::setBrigadier(string brigadier) {
    this->brigadier = brigadier;
}
void Brigade::addExp(Expense exp) {
    exps.push_back(exp);
    totalCost += exp.getCost();
}