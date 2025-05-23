#ifndef FUNCS_H
#define FUNCS_H

#include "Cargo.h"
#include "Transport.h"
#include "SpecialT.h"
#include "funcs.h"
#include <fstream>
using namespace std;

template<typename T>
void read(Transport<T>* arr[], int& count, const string& filename) {
    ifstream fin(filename);
    string cargoStr, dest, cond;
    double price;

    while (fin >> cargoStr >> dest >> price) {
        if (cargoStr == "Special") {
            fin >> cond;
            arr[count++] = new SpecialTransport<T>(T(cargoStr), dest, price, cond);
        }
        else {
            arr[count++] = new Transport<T>(T(cargoStr), dest, price);
        }
    }
}

template<typename T>
Transport<T>* findMax(Transport<T>* arr[], int count) {
    if (count == 0) return 0;
    Transport<T>* max = arr[0];
    for (int i = 1; i < count; ++i)
        if (arr[i]->getPrice() > max->getPrice())
            max = arr[i];
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

template<typename T>
void processMaxTransport(Transport<T>* arr[], int count, ostream& os) {
    Transport<T>* max = findMax(arr, count);

    os << "\nMax price transport:\n";
    if (max) os << *max << endl;

    if (max) {
        cout << "Current max transport:\n" << *max << endl;
        cout << "Enter new cargo type for max transport: ";
        string newCargoType;
        getline(cin >> ws, newCargoType);

        cout << "Enter new destination for max transport: ";
        string newDest;
        getline(cin, newDest);

        max->setCargo(T(newCargoType));
        max->setDest(newDest);

        os << "\nUpdating max transport:\n";
        os << *max << endl;

        max->discount();
        os << "\nAfter discount:\n";
        os << *max << endl;

        cout << "\nUpdated max transport saved to output.txt\n";
    }
}

template<typename T>
void clear(Transport<T>* arr[], int count) {
    for (int i = 0; i < count; ++i)
        delete arr[i];
}

#endif