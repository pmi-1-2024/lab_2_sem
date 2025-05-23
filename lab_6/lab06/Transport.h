#pragma once
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class Transport {
protected:
    T cargo;
    char destination[100];
    double cost;
public:
    Transport(T cargo, const char* destination, double cost);
    virtual ~Transport() {}

    void setCargo(T cargo);
    void setDestination(const char* destination);
    void setCost(double cost);

    T getCargo() const;
    const char* getDestination() const;
    double getCost() const;

    virtual double calculateDiscount(double percent) const;
    virtual void print() const;
};

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
    cout << "Cargo: " << cargo
        << ", Destination: " << destination
        << ", Cost: " << cost << " UAH" << endl;
}