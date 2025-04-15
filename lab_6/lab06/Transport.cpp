#include "Transport.h"
#include <cstring>

template<typename T>
Transport<T>::Transport(T cargo, const char* destination, double cost)
    : cargo(cargo), cost(cost) {
    strcpy_s(this->destination, sizeof(this->destination), destination);
}

template<typename T>
void Transport<T>::setCargo(T cargo) {
    this->cargo = cargo;
}

template<typename T>
void Transport<T>::setDestination(const char* destination) {
    strcpy_s(this->destination, sizeof(this->destination), destination);
}

template<typename T>
void Transport<T>::setCost(double cost) {
    this->cost = cost;
}

template<typename T>
T Transport<T>::getCargo() const {
    return cargo;
}

template<typename T>
const char* Transport<T>::getDestination() const {
    return destination;
}

template<typename T>
double Transport<T>::getCost() const {
    return cost;
}

template<typename T>
double Transport<T>::calculateDiscount(double percent) const {
    return cost - (cost * percent / 100.0);
}

template<typename T>
void Transport<T>::print() const {
    cout << "Cargo: " << cargo << ", Destination: " << destination << ", Cost: " << cost << " UAH" << endl;
}

template class Transport<string>;