#ifndef FUNCS_H
#define FUNCS_H

#include "Except.h"
#include "Cargo.h"
#include "Transport.h"
#include "SpecialT.h"
#include <fstream>
#include <iostream>
using namespace std;

template<typename T>
void read(Transport<T>* arr[], int& count, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        throw TransportException("Cannot open file: " + filename);
    }

    string cargoStr, dest, cond;
    double price;

    while (true) {
        if (!(fin >> cargoStr >> dest >> price)) break;

        if (price < 0) throw TransportException("Negative price is invalid");

        if (cargoStr == "Special") {
            if (!(fin >> cond)) throw TransportException("Missing special condition for Special transport");
            arr[count++] = new SpecialTransport<T>(T(cargoStr), dest, price, cond);
        }
        else if (cargoStr == "Food" || cargoStr == "Goods" || cargoStr == "Medical" || cargoStr == "Passenger") {
            arr[count++] = new Transport<T>(T(cargoStr), dest, price);
        }
        else {
            throw TransportException("Unknown cargo type: " + cargoStr);
        }
    }
}

template<typename T>
Transport<T>* findMax(Transport<T>* arr[], int count) {
    if (count == 0) throw TransportException("Empty transport list");
    Transport<T>* max = arr[0];
    for (int i = 1; i < count; ++i) {
        if (arr[i]->getPrice() > max->getPrice())
            max = arr[i];
    }
    return max;
}

template<typename T>
void showAll(Transport<T>* arr[], int count, ostream& os) {
    for (int i = 0; i < count; ++i)
        os << *arr[i] << "\n";
}

template<typename T>
void printPassenger(Transport<T>* arr[], int count, ostream& os) {
    for (int i = 0; i < count; ++i) {
        if (arr[i]->getCargo() == "Passenger") {
            os << *arr[i] << "\n";
        }
    }
}

template<typename T>
double totalCost(Transport<T>* arr[], int count) {
    double sum = 0;
    for (int i = 0; i < count; ++i)
        sum += arr[i]->getPrice();
    return sum;
}

#endif