#include "Expense.h"

Expense::Expense() : date(""), material(""), volume(0), cost(0) {}
Expense::Expense(string date, string material, double volume, double cost) :
    date(date), material(material), volume(volume), cost(cost) {}

string Expense::getDate() {
    return date;
}
string Expense::getMaterial() {
    return material;
}
double Expense::getVolume() {
    return volume;
}
double Expense::getCost() {
    return cost;
}

void Expense::setDate(string date) {
    this->date = date;
}
void Expense::setMaterial(string material) {
    this->material = material;
}
void Expense::setVolume(double volume) {
    this->volume = volume;
}
void Expense::setCost(double cost) {
    this->cost = cost;
}