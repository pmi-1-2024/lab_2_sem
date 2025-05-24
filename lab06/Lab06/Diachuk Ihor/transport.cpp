#ifndef TRANSPORT_CPP
#define TRANSPORT_CPP

#include "transport.h"

template <typename T>
Transport<T>::Transport() : cargo(""), destination(""), cost(0.0) {}

template <typename T>
Transport<T>::Transport(T c, string d, double cost)
    : cargo(c), destination(d), cost(cost) {
}

template <typename T>
Transport<T>::~Transport() {}

template <typename T>
void Transport<T>::updateCargo(T newCargo) {
    cargo = newCargo;
}

template <typename T>
void Transport<T>::updateDestination(const string& newDest) {
    destination = newDest;
}

template <typename T>
double Transport<T>::calculateDiscountedCost() const {
    return cost;
}

template <typename T>
void Transport<T>::print() const {
    cout << "Вантаж: " << cargo << ", Пункт призначення: " << destination << ", Вартість: " << cost << endl;
}

template <typename T>
T Transport<T>::getCargo() const {
    return cargo;
}

template <typename T>
string Transport<T>::getDestination() const {
    return destination;
}

template <typename T>
double Transport<T>::getCost() const {
    return cost;
}

#endif