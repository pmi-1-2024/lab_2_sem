#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>
#include "Transport.h"
#include "SpecialTransport.h"

using namespace std;

template <typename T>
int findMostExpensive(Transport<T>** transports, int size) {
    if (size == 0) return -1;
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (transports[i]->getCost() > transports[maxIndex]->getCost()) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

template <typename T>
void applyDiscount(Transport<T>& transport) {
    transport.setCost(transport.getCost() - transport.calculateDiscount());
}

template <typename T>
int filterByCargo(Transport<T>** transports, int size, const T& cargo, Transport<T>** filteredArray, int& filteredSize) {
    filteredSize = 0;
    for (int i = 0; i < size; ++i) {
        if (transports[i]->getCargo() == cargo) {
            filteredArray[filteredSize++] = transports[i];
        }
    }
    return filteredSize;
}

template <typename T>
double calculateTotalCost(Transport<T>** transports, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += transports[i]->getCost();
    }
    return total;
}

template <typename T>
void saveDataToFile(Transport<T>** transports, int size, const char* filename) {
    ofstream file(filename);


    file << size << "\n";

    for (int i = 0; i < size; ++i) {
        if constexpr (is_same<T, Cargo>::value) {
            file << (dynamic_cast<SpecialTransport*>(transports[i]) != nullptr ? 1 : 0) << "\n";
        }
        else {
            file << 0 << "\n";
        }
        transports[i]->save(file);
    }
    file.close();
}

template <typename T>
Transport<T>** loadDataFromFile(const char* filename, int& size) {
    ifstream file(filename);

    int capacity;
    file >> capacity;

    Transport<T>** transports = new Transport<T>*[capacity];

    size = 0;

    for (int i = 0; i < capacity; ++i) {
        int isSpecial = 0;
        file >> isSpecial;

        Transport<T>* obj = nullptr;

        if constexpr (is_same<T, Cargo>::value) {
            if (isSpecial == 1) {
                obj = new SpecialTransport();
            }
            else {
                obj = new Transport<T>();
            }
        }
        else {
            if (isSpecial == 1) {

                obj = new Transport<T>();
            }
            else {
                obj = new Transport<T>();

            }
        }
        obj->load(file);

        transports[size++] = obj;
    }

    file.close();
    return transports;
}
